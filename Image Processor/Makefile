#
# Cell count program Makefile
#
#
CFLAGS = -g -Wall -Werror -O2
PROGRAM = prog2
#
${PROGRAM} : image.o ImgProc.o main.o
	g++ -g -o ${PROGRAM} image.o ImgProc.o main.o

image.o: image.cc image.h
	g++ -g -c ${PROGRAM} image.cc

ImgProc.o: ImgProc.cc ImgProc.h
	g++ -g -c ${PROGRAM} ImgProc.cc

main.o: main.cc
	g++ -c -g main.cc

clean:
	/bin/rm -f *.o ${PROGRAM} out
