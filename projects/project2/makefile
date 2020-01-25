main: main.o Song.o
	g++ -o main main.o Song.o

main.o: main.cpp Song.h
	g++ -c main.cpp

Song.o: Song.cpp Song.h
	g++ -c Song.cpp

run:
	./main

clean:
	rm main.o Song.o

clobber:
	rm main
