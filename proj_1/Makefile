all: mp3

mp3: main.o mp3.o
	gcc -g main.o mp3.o -o mp3

main.o: main.c mp3.h
	gcc -g -c main.c

mp3.o: mp3.c mp3.h
	gcc -g -c mp3.c

clean:
	\rm *.o mp3
