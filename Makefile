all: compile

compile: main variable tableau
	gcc main.o variable.o tableau.o -o main
	
main: main.c
	gcc -c main.c
	
variable: variable.c 
	gcc -c variable.c

tableau: tableau.c
	gcc -c tableau.c