# Made by Bruce Cosgrove

main: main.o DynamicArray.o
	g++ -o main main.o DynamicArray.o

main.o: main.cpp DynamicArray.h
	g++ -c main.cpp DynamicArray.h

DynamicArray.o: DynamicArray.cpp DynamicArray.h
	g++ -c DynamicArray.cpp

run:
	./main

clean:
	rm *.o *.gch

clobber:
	rm main
