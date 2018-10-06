CC = gcc 
CCFLAGS = -Werror -Wall -O2 -L.

all: threadlib.a test
	# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
	#
	#   CS 442/542 Assignment 4 -- premptive user-level thread library
	#
	#   
	#
	# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

threadlib.a: threadlib.c
	$(CC) $(CFLAGS) -c threadlib.c -o threadlib.o
	ar -r threadlib.a threadlib.o
	
test: test.c
	$(CC) $(CCFLAGS) test.c threadlib.a -o test
	
clean:
	rm -f test threadlib.a core *.o
