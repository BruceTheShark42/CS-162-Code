// Made by Bruce Cosgrove

#ifndef SONG_H
#define SONG_H

class Song
{
public:
	Song(char* title, char* artist, unsigned int minutes, unsigned int seconds, char* album);
	~Song();
public:
	char* getTitle() const;
	char* getArtist() const;
	unsigned int getMinutes() const;
	unsigned int getSeconds() const;
	char* getAlbum() const;
	void print(unsigned int index) const;
private:
	char* title;
	char* artist;
	struct
	{
		unsigned int minutes;
		unsigned int seconds;
	} duration;
	char* album;
};

#endif
