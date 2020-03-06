# Made by Bruce Cosgrove

main: main.o Deque.o
	g++ -o main main.o Deque.o

main.o: main.cpp Deque.h
	g++ -c main.cpp Deque.h

Deque.o: Deque.cpp Deque.h
	g++ -c Deque.cpp

run:
	./main

clean:
	rm main.o Deque.o

clobber:
	rm main
