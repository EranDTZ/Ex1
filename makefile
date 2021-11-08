LoopFile = basicClassification.o advancedClassificationLoop.o
RecursivesFile =  basicClassification.o advancedClassificationRecursion.o
MainFile = main.o
CC = gcc
AR = ar
FLAGS= -Wall -g

loops: libclassloops.a
libclassloops.a: $(LoopFile)
	$(AR) -rcs -o libclassloops.a $(LoopFile)

recursives: libclassrec.a
libclassrec.a: $(RecursivesFile)
	$(AR) -rcs -o libclassrec.a $(RecursivesFile)

recursived: libclassrec.so
libclassrec.so: $(RecursivesFile)
	$(CC) $(FLAGS) -shared -o libclassrec.so $(RecursivesFile) 

loopd: libclassloops.so
libclassloops.so: $(LoopFile)
	$(CC) $(FLAGS) -shared -o libclassloops.so $(LoopFile) 

mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a -lm

main.o: main.c  NumClass.h
	$(CC) $(FLAGS) -c main.c 	

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(MainFile) ./libclassloops.so -lm

maindrec: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindrec $(MainFile) ./libclassloops.so -lm

all: loops recursives recursived loopd mains main.o maindloop maindrec

.PHONY: clean all

clean:
	rm -f *.o *.a *.so maindloop maindrec mains libclassloops.a
