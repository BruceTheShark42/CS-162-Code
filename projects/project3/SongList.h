#ifndef SONG_LIST_H
#define SONG_LIST_H

#include "Song.h"
#include "util.h"

class SongList
{
public:
	SongList();
	~SongList();
public:
	bool add(char* title, char* artist, unsigned int minutes, unsigned int seconds, char* album, bool silent = true);
	void display();
	void remove(int index);
	int search(char* searchParameter, bool searchByArtist);
	
	void importFromFile();
	void exportToFile();
	
	unsigned int getSongCount() const;
	Song* get(unsigned int index) const;
public:
	static const char FILE_DELIMITER = ';';
private:
	static const unsigned int MAX_SONGS = 100;
	static const unsigned int MAX_FILE_LINE_LEN = 3 * MAX_CHARS + 23;
	static constexpr const char* SONG_FILE = "songs.txt";
private:
	Song** songs;
	unsigned int songCount;
	bool altered;
};

#endif
