LoopFile = basicClassification.o advancedClassificationLoop.o
RecursivesFile =  basicClassification.o advancedClassificationRecursion.o
MainFile = main.o
CC = gcc
AR = ar
FLAGS= -Wall -g

loops: $(LoopFile) 
	$(AR) -rcs -o libclassloops.a $(LoopFile)

recursives: $(RecursivesFile)
	$(AR) -rcs -o libclassrec.a $(RecursivesFile)

recursived: $(RecursivesFile)
	$(CC) $(FLAGS) -shared -o libclassrec.so $(RecursivesFile) 

loopd: $(LoopFile) 
	$(CC) $(FLAGS) -shared -o libclassloops.so $(LoopFile) 

mains: $(MainFile) recursives
	$(CC) $(FLAGS) -o mains $(MainFile) libclassrec.a -lm

main.o: main.c  NumClass.h
	$(CC) $(FLAGS) -c main.c 	

maindloop: $(MainFile) loopd
	$(CC) $(FLAGS) -o maindloop $(MainFile) ./libclassloops.so -lm

maindrec: $(MainFile) recursived
	$(CC) $(FLAGS) -o maindrec $(MainFile) ./libclassloops.so -lm

all: loops recursives recursived loopd mains main.o maindloop maindrec

.PHONY: clean all

clean:
	rm -f *.o *.a *.so maindloop maindrec mains libclassloops.a




