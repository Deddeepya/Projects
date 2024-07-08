all:	out.o

out.o:	myshell-2.o cp.o
	gcc myshell-2.o -lreadline cp.o -o out.o 

myshell-2.o:	myshell-2.c
	gcc -c myshell-2.c -lreadline -o myshell-2.o 

cp.o:	cp.c
	gcc -c cp.c -o cp.o

