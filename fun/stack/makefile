# Made by Bruce Cosgrove

main: main.o Stack.o
	g++ -o main main.o Stack.o

main.o: main.cpp Stack.h
	g++ -c main.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp Stack.h

run:
	./main

clean:
	rm *.o

clobber:
	rm main

noclobber:
	rm *.h.gch
