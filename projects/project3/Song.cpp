#include "Song.h"

#include <iostream>

Song::Song(char* title, char* artist, unsigned int minutes, unsigned int seconds, char* album)
{
	this->title = title;
	this->artist = artist;
	duration.minutes = minutes + seconds / 60;
	duration.seconds = seconds % 60;
	this->album = album;
}

Song::~Song()
{
	delete[] title;
	delete[] artist;
	delete[] album;
}

char* Song::getTitle() const
{
	return title;
}

char* Song::getArtist() const
{
	return artist;
}

unsigned int Song::getMinutes() const
{
	return duration.minutes;
}

unsigned int Song::getSeconds() const
{
	return duration.seconds;
}

char* Song::getAlbum() const
{
	return album;
}

void Song::print(unsigned int index) const
{
	std::cout << "-----------------------\n"
		  << "  Song " << index << ":\n"
		  << "    - Title: " << title << '\n'
		  << "    - Artist: " << artist << '\n'
		  << "    - Duration: " << duration.minutes << ':' << (duration.seconds < 10 ? "0" : "") << duration.seconds << '\n'
		  << "    - Album: " << album << '\n';
}
