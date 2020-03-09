# Made by Bruce Cosgrove

main: main.o Queue.o
	g++ -o main main.o Queue.o

main.o: main.cpp Queue.h
	g++ -c main.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp Queue.h

run:
	./main

clean:
	rm *.o

clobber:
	rm main

noclobber:
	rm *.h.gch
