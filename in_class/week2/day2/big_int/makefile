main: main.o BigInt.o
	g++ -o main main.o BigInt.o

main.o: main.cpp BigInt.h
	g++ -c main.cpp

BigInt.o: BigInt.cpp BigInt.h
	g++ -c BigInt.cpp

run:
	./main

clean:
	rm main.o BigInt.o

clobber:
	rm main
