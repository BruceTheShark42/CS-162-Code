# Made by Bruce Cosgrove

main: main.o LinkedList.o
	g++ -o main main.o LinkedList.o

main.o: main.cpp LinkedList.h
	g++ -c main.cpp LinkedList.h

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

run:
	./main

clean:
	rm main.o LinkedList.o

clobber:
	rm main
