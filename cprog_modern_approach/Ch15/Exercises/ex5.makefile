// 3 source files: main.c, f1.c, and f2.c
// 2 header files: f1.h and f2.h
// all three source files include f1.h, but only 
//      f1.c and f2.c include f2.h
// Write a makefile assuming compiler is gcc and the executable is named demo

demo: main.o f1.o f2.o
    gcc -o demo main.o f1.o f2.o

main.o: main.c f1.h
    gcc -c main.c

f1.o: f1.c f1.h f2.h
    gcc -c f1.c

f2.o: f2.c f1.h f2.h
    gcc -c f2.c
