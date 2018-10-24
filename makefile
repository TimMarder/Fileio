all:fileio.o
	gcc fileio.o

fileio.o:fileio.c
	gcc -c fileio.c

run:
	./a.out

clean:
	rm *.o
	rm edit.txt
