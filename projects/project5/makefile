# Made by Bruce Cosgrove

main: main.o SongList.o util.o String.o
	g++ -o main main.o SongList.o util.o String.o

main.o: main.cpp SongList.h util.h
	g++ -c main.cpp

SongList.o: SongList.cpp SongList.h util.h String.h
	g++ -c SongList.cpp SongList.h

util.o: util.cpp util.h String.h
	g++ -c util.cpp util.h

String.o: String.cpp String.h
	g++ -c String.cpp String.h

run:
	./main

clean:
	rm *.o

clobber:
	rm main

noclobber:
	rm *.gch
