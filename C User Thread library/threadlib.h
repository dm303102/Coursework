/*
 *   File        : threadlib.h
 *   Name	 : 
 *   Class       : CS 442/542 Winter 07
 *   Assignment  : Project 4 - user thread library -- skeleton
 *   Description : header file for threadlib.a
 *              
 */
#ifndef _CS542_THREADLIB_H__
#define _CS542_THREADLIB_H__

#include <signal.h>
#include <ucontext.h>
#include <sys/time.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10
#define DEFAULT_PRIORITY 5

typedef enum { zombie=0, ready, blocking } state_t;
typedef void (* thread_function_t )(void *); 

typedef struct thread thread;
typedef thread * thread_t;

typedef struct queue queue;
typedef queue * queue_t;

struct queue 
{
	thread *front;
};

struct thread 
{
	int id;							// the thread id
	
	int priority;					// used for scheduling
	int slice_count;				// used for shceduling
	
	queue  waiting_threads;			// queue of threads that'joined" this thread
	int wait_count;					// count of threads that this thread joined
	
	int hold;						// semaphore 

	ucontext_t  context;			// context
	state_t state;					// state
	
	char stack[200000];				// each thread gets a stack
	thread *next;
};

// prototypes
thread_t create_thread( thread_function_t, void *, int );

void thread_yield();
void thread_exit();
void thread_join( thread_t tojoin );
int thread_set_priority( thread *, int pri );

int Terminate(int);


#endif


