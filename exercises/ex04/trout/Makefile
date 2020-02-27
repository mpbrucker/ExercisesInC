util.o: util.h util.c
	gcc -c util.c

trout.o: trout.h trout.c
	gcc -c trout.c

trout: util.o trout.o main.c
	gcc -Wall main.c util.o trout.o -o trout 
