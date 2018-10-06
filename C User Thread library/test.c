/*
 *   File        : test.c
 *   Name	 : 
 *   Class       : CS 442/542 Winter 07
 *   Assignment  : Assingment 4 - user thread library -- skeleton
 *   Description : test file for thread library threadlib.a
 *               
 */
#include "threadlib.h"

static void waste_time()
{
	volatile int i=0;
	volatile float var =0.0;
	for(i=0; i<100000; i++)
		var = var + 0.001;
}

// simple thread function... does not create another thread (itself)
void thread_simple(void *arg)
{
	int id = (int) arg;
	int var = 1;
	while(var++ < 30)
	{
		printf("simple_thread ** %d :: %d **\n", id, var ); fflush(stdout);
		waste_time();
	}
	printf("simple_thread ** %d :: %d **** finished\n", id, var ); fflush(stdout);
}

// sample thread function, notice that the function creates another thread
// of the same priority as this one
void thread_func(void *arg)
{
	int id = (int)arg;
	int var = 1;

	printf("starting ** %d :: %d **\n", id, var ); fflush(stdout);
	
	create_thread( thread_simple, (void *)( 100 + id ), DEFAULT_PRIORITY );
	
	while(var++ < 100 )
	{
		printf("thread func ** %d :: %d **\n", id, var ); fflush(stdout);
		waste_time();
	}
	printf("thread func ** %d :: %d **** finished\n", id, var ); fflush(stdout);
}

// main function to test some of the threadlib functions
int main()
{
	// create some threads as a test, give them various priorities
	thread_t one = create_thread( thread_func, (void*) 1, 10 );
	thread_t two = create_thread( thread_func, (void*) 2, 1 );
	thread_t tre = create_thread( thread_func, (void*) 3, 6 );
	thread_t fer = create_thread( thread_func, (void*) 4, 5 );

	// the main thread (this thread) will block untill all the 
	// other threads have quit
        printf("Main Thread ** running\n");
        printf("Main Thread will be blocked -- waiting for thread one\n");
	thread_join(one);
        printf("Main Thread ** running\n");
        printf("Main Thread will be blocked -- waiting for thread two\n");
	thread_join(two);
        printf("Main Thread ** running\n");
        printf("Maint Thread will be blocked -- waiting for thread three\n");
	thread_join(tre);
        printf("Main Thread ** running\n");
        printf("Maint Thread will be blocked -- waiting for thread four\n");
	thread_join(fer);
        printf("Main Thread ** running\n");

	// what the heck, create another
	thread_t fiv = create_thread( thread_simple, (void*) 5, 2 );
	
	thread_join(fiv);
	
	// continue to do something in main thread
	{
		int var=1;  
		while(var++ < 300)
		{
			const int id = 0;
			printf("Main Thread ** %d :: %d **\n", id, var ); fflush(stdout);
		}
	}
	return 0;
}

