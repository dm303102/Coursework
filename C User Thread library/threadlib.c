/*
 *   File        : threadlib.c 
 *   Name  	 : 
 *   Class       : CS 442/542 Winter 07
 *   Assignment  : Project 4 - user thread library -- skeleton
 *   Description : This file has all the code that goes into threadlib.a
 *               
 */
#include "threadlib.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

// The set of signals that are turned on and off during
// the thread scheduling, and the macros that do it
static sigset_t signals;
#define DISABLE()  sigprocmask(SIG_BLOCK, &signals, NULL)
#define ENABLE()   sigprocmask(SIG_UNBLOCK, &signals, NULL)

// The ready queue and the blocking queue,  The blocking queue
// is used by the blocking functionality
// Note: theads DO block when they "join" another thread but 
// that queue is in the other threads structure
static queue ready_queue;
static queue block_queue;

// used by the scheduler
static thread * current_thread = NULL;
static thread * next_thread = NULL;

// each thread gets a unique id... sequential number
static int thread_id = 0;

// The next three functions just implement the queue of threads
static void initialize(queue *q)
{
	q->front = NULL;	// start with empty queue
}

// remove the front item from the queue or NULL
static thread *dequeue(queue *q)
{ 
	thread   *ret;

	if ( q->front != NULL ) 
	{
		ret = q->front->next;
		q->front->next = ret->next;
		ret->next = NULL;
		if ( q->front == ret ) 
		{
			q->front = NULL;
		}
	} 
	else
	{
		ret = NULL;
	}
	return ret;
}

// add the thread to the back of the queue
static void enqueue(thread *d, queue *q)
{
	if ( q->front == NULL ) 
	{
		q->front = d;
		d->next = q->front;
	} 
	else 
	{
		d->next = q->front->next;
		q->front->next = d;
		q->front = d;
	}
}

static void handler(int signum, siginfo_t *ptr1, ucontext_t *ptr2) 
{
	DISABLE();  // don't interupt this handler
	
	// implement the Weighted Priority round robin by counting 
	// time slices and letting the thread continue if it's
	// not used up all its slices
	if ( current_thread && current_thread->state==ready && 
		 ( current_thread->slice_count < current_thread->priority) )
	{
		current_thread->slice_count++;
		ENABLE();
		return;
	}

	// the programmer wants to know if this ever fails
	assert(current_thread);
	
	// but check for it just in case it gets by quality control
	if ( current_thread )
	{
		// done with this thread for now so reset slice count
		current_thread->slice_count = 0;

		// retrieve the next thread
		thread * next_thread = dequeue(&ready_queue);
		if ( next_thread )
		{
			// this thread is marked as a zombie, meaning it finished
			// or was exited, so free the memory and don't add to ready_queue
			if ( current_thread->state == zombie )
			{
				free( current_thread );
				current_thread = next_thread;
				ENABLE();
				setcontext(&next_thread->context);
			}
			
			// save the context into the current thread so it can be
			// resumed at the correct place in the code (after semaphore)
			else
			{
				// Use the hold semaphore to ensure that the context is resumed
				// in the correct place next time around
				current_thread->hold = 1;
				getcontext( &current_thread->context );
				if ( current_thread->hold == 1 )
				{
					current_thread->hold = 0;
					
					// only enque the old thread if it is still ready
					if ( current_thread->state == ready )
					{ enqueue( current_thread, &ready_queue ); }
					
					// switch to the next thread
					current_thread = next_thread;
					setcontext(&next_thread->context);
				}
			}
		}
	}
	ENABLE();   // resume interuptions
}

// this function sets up the signal timer and signal action
// which handles all the thread scheduling.  The function is 
// called any time a thread is created, but it only executes
// the code the first time it is called
static void init_threads()
{
	static int called = 0;

	// only call this function once
	if ( called == 0 )
	{
		called = 1;
		
		initialize(&ready_queue);
		initialize(&block_queue);
		
		// setup signal handler
		struct sigaction act;
		{
			memset(&act,0,sizeof(act));
			act.sa_handler = handler;
			act.sa_flags=SA_RESTART|SA_SIGINFO;
			sigaction(SIGALRM, &act, 0);
		}
		
		// setup timer for the handler 
		struct itimerval itv;
		{
			memset(&itv,0,sizeof(itv));
			itv.it_interval.tv_sec=0;
			itv.it_interval.tv_usec=10000;  
			itv.it_value.tv_sec = 0;
			itv.it_value.tv_usec = 10000;  
		}

		// Initialize the signal set that is enabled/disabled
		sigemptyset(&signals);
		sigaddset(&signals,SIGALRM);

		// the current thread is the main thread
		{
			current_thread = (thread *) malloc( sizeof( thread ) );
			getcontext(&current_thread->context);

			current_thread->state = ready;
			current_thread->id = thread_id++;
		}
		
		// start the handler... scheduler running
		setitimer(ITIMER_REAL, &itv, NULL);
	}
}

// change the static priority of the calling thread
int thread_set_priority( thread * t, int pri )
{
	DISABLE();
	assert( t );
	if ( t )
	{
		t->priority = ( MIN_PRIORITY <= pri && pri > MAX_PRIORITY ? pri :  DEFAULT_PRIORITY );
	}
	ENABLE();
}

// cause the current thread to yield processor
void thread_yield()
{
	raise(SIGALRM);
}

// quit or exit the current thread
void thread_exit()
{
	DISABLE();
	current_thread->state = zombie;
	ENABLE();
	raise(SIGALRM);
}

void lock()
{
	DISABLE();
}

void unlock()
{
	ENABLE();
}
// cause the current thread to block untill the 
// "joined" thread has quit
void thread_join( thread_t tojoin )
{
	DISABLE();
	
	// can't join zombies
	if ( tojoin == NULL || tojoin->state == zombie )
	{
		ENABLE();
		return;
	}

	// This code makes the current thread wait for the "to join" thread
	// 1) add this thread to the waiting queue of the "joined" thread
	// 2) set the thread to blocking
	// 3) increment the wait count
	enqueue( current_thread, &tojoin->waiting_threads );
	current_thread->state = blocking;
	current_thread->wait_count++;

	// printf("%d is joining: %d\n", current_thread->id, tojoin->id); fflush(stdout);
	
	ENABLE();
	raise(SIGALRM);
}

// The function passed to the init_thread function is actually wrapped in 
// this function, so that some cleanup can be done when the thread exits
void thread_wrapper( thread_function_t func, int id, void * parameter )
{
	// call the function that was passed as a parameter
	func(parameter);
	
	// thread finished so begin post-proccessing
	DISABLE();
	
	if ( current_thread )
	{
		// reset variables in the context structure so it won't run again
		// even if gets "set" .  Mark the thread as a "zombie" so it gets
		// freed by the handler
		memset(&current_thread->context,0,sizeof(current_thread->context));
		current_thread->state = zombie;

		// now, remove all threads that are waiting on this thread
		// and push them onto the ready_queue, but only if the waiting
		// count has been reduced to 0.  That is... if the thread is not
		// waiting for any other threads.
		thread * cursor;
		while ( cursor = dequeue( &current_thread->waiting_threads ) )
		{
			if ( --cursor->wait_count <= 0 )
			{
				printf("un-joining: %d\n", cursor->wait_count ); fflush(stdout);
				cursor->state = ready;
				enqueue(cursor, &ready_queue);
				break;
			}
		}
	}
		 
	ENABLE();		
	raise(SIGALRM);		// jump right to the handler
}

// This function creats an entry in TCB, the TCB is actually just a queue
// of thread structures.  This is the ready queue.  The function parameter "func"
// is passed to the thread_wrapper function which becomes the actual thread function.
thread * create_thread(thread_function_t func, void * parameter, int priority)
{
	// make sure thread system is setup
	init_threads();
	
	// create the thread structure and push it on the queue
	thread * threadp = (thread *) malloc( sizeof( thread ) );
	memset(threadp,0,sizeof(thread) );
	getcontext(&threadp->context);
	
	// set thread priority from the parameter and keep it in bounds
	threadp->priority = priority;
	threadp->priority = ( threadp->priority < MIN_PRIORITY ? MIN_PRIORITY : threadp->priority );
	threadp->priority = ( threadp->priority < MIN_PRIORITY ? MIN_PRIORITY : threadp->priority );

	// the thread is "ready" so it will be run when it's turn 
	// is scheduled by the handler, also set the id to the next number
	threadp->state = ready;
	threadp->id = thread_id++;
	
	// Each thread needs it's own stack
	threadp->context.uc_stack.ss_sp = threadp->stack;
	threadp->context.uc_stack.ss_size = sizeof(threadp->stack);	
	
	// Create the context based on the thread function
	makecontext(&threadp->context,thread_wrapper, 3, func, threadp->id, parameter ); 
	
	// not the main thread, so the link is not 0
	threadp->context.uc_link = &(threadp->context);
	
	// Add the newly created structure to the ready queue
	DISABLE();
	enqueue(threadp, &ready_queue);
	ENABLE();

	// return value is the pointer to the structure so it can 
	// be used by the calling program to change thread characteristics
	return threadp;
}

