# Made by Bruce Cosgrove

main: main.o CircularlyLinkedSet.o
	g++ -o main main.o CircularlyLinkedSet.o

main.o: main.cpp CircularlyLinkedSet.h
	g++ -c main.cpp CircularlyLinkedSet.h

CircularlyLinkedSet.o: CircularlyLinkedSet.cpp CircularlyLinkedSet.h
	g++ -c CircularlyLinkedSet.cpp

run:
	./main

clean:
	rm *.o

clobber:
	rm main
