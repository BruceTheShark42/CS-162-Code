main: main.o SongList.o Song.o util.o
	g++ -o main main.o SongList.o Song.o util.o

main.o: main.cpp SongList.h Song.h util.h
	g++ -c main.cpp

SongList.o: SongList.cpp SongList.h Song.h util.h
	g++ -c SongList.cpp

Song.o: Song.cpp Song.h
	g++ -c Song.cpp

util.o: util.cpp util.h
	g++ -c util.cpp

run:
	./main

clean:
	rm main.o SongList.o Song.o util.o

clobber:
	rm main
