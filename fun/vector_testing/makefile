# Made by Bruce Cosgrove

main: main.o Vector.o
	g++ -o main main.o Vector.o

main.o: main.cpp Vector.h
	g++ -c main.cpp Vector.h

Vector.o: Vector.cpp Vector.h
	g++ -c Vector.cpp

run:
	./main

clean:
	rm main.o Vector.o

clobber:
	rm main
