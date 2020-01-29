// Made by Bruce Cosgrove

#include "SongList.h"

#include <iostream>
#include <fstream>
#include <cstring>

SongList::SongList()
	: songs(new Song*[MAX_CHARS] {nullptr}), songCount(0U), altered(false)
{
	importFromFile();
}

SongList::~SongList()
{
	if (altered)
		exportToFile();
	else
		std::cout << "No changes made; no saving needeed.\n";
	
	for (unsigned int i = 0; i < songCount; ++i)
		delete songs[i];
	delete[] songs;
}

bool SongList::add(char* title, char* artist, unsigned int minutes, unsigned int seconds, char* album, bool silent)
{
	if (songCount < MAX_SONGS)
	{
		songs[songCount] = new Song(title, artist, minutes, seconds, album);
		if (!silent)
		{
			std::cout << "Successfully added \"" << title << "\" to the list at index " << songCount << ".\n";
			altered = true;
		}
		++songCount;
		return true;
	}
	else if (!silent)
		std::cout << "There are too many songs in your list.\n"
			  << "Please remove some of them to add any more.\n";
	return false;
}

void SongList::display()
{
	if (songCount)
	{
		std::cout << "Here are your songs:\n";
		for (unsigned int i = 0; i < songCount; ++i)
			songs[i]->print(i);
	}
	else
		std::cout << "There are currently no songs in your list.\n";
}

void SongList::remove(int index)
{
	if (index < 0 || index < songCount)
	{
		for (unsigned int i = index; i < songCount - 1; ++i)
			songs[i] = songs[i + 1];
		
		// The pointer has been copied to the spot behind, 
		// so just erase the original pointer, but don't 
		// free the memory, that would erase the song.
		songs[songCount--] = nullptr;
		altered = true;
	}
	else
		std::cout << "The index is out of bounds.\n";
}

int SongList::search(char* searchParameter, bool searchByArtist)
{
	for (unsigned int i = 0; i < songCount; ++i)
		if (contains((searchByArtist ? songs[i]->getArtist() : songs[i]->getAlbum()), searchParameter))
			songs[i]->print(i);
}

void SongList::importFromFile()
{
	std::ifstream listFile(SONG_FILE);
	if (listFile.is_open())
	{
		int linesLeft = -1;
		while (!listFile.eof() && linesLeft)
		{
			char line[MAX_FILE_LINE_LEN];
			listFile.getline(line, MAX_FILE_LINE_LEN);
			
			if (linesLeft > 0)
			{
				unsigned int lineLength = std::strlen(line);
				
				unsigned int placeToAdd = 0, indexToAdd = 0;
				char* title = new char[MAX_CHARS]; // 0
				char* artist = new char[MAX_CHARS]; // 1
				char* minutes = new char[MAX_CHARS]; // 2
				char* seconds = new char[MAX_CHARS]; // 3
				char* album = new char[MAX_CHARS]; // 4
				
				for (unsigned int i = 0; i < lineLength; ++i)
				{
					if (line[i] == FILE_DELIMITER)
					{
						switch (placeToAdd++)
						{
							case 0: title[indexToAdd] = '\0'; break;
							case 1: artist[indexToAdd] = '\0'; break;
							case 2: minutes[indexToAdd] = '\0'; break;
							case 3: seconds[indexToAdd] = '\0'; break;
							case 4: album[indexToAdd] = '\0'; break;
						}
						indexToAdd = 0;
					}
					else
					{
						switch (placeToAdd)
						{
							case 0: title[indexToAdd] = line[i]; break;
							case 1: artist[indexToAdd] = line[i]; break;
							case 2: minutes[indexToAdd] = line[i]; break;
							case 3: seconds[indexToAdd] = line[i]; break;
							case 4: album[indexToAdd] = line[i]; break;
						}
						++indexToAdd;
					}
				}
				
				add(title, artist, (unsigned int)std::stoi(minutes), 
					(unsigned int)std::stoi(seconds), album, true);
				
				// Found the memory leak
				delete[] minutes;
				delete[] seconds;
				
				--linesLeft;
			}
			else
				linesLeft = std::stoi(line);
		}
		
		listFile.close();
		std::cout << "Successfully loaded " << songCount << " songs from \"" << SONG_FILE << "\"\n";
	}
}

void SongList::exportToFile()
{
	std::ofstream listFile(SONG_FILE);
	if (listFile.is_open())
	{
		// Send the number of songs
		listFile << songCount << '\n';
		
		// Send the song data
		for (unsigned int i = 0; i < songCount; ++i)
		{
			Song* song = songs[i];
			listFile << song->getTitle() << FILE_DELIMITER << song->getArtist() << FILE_DELIMITER 
				 << song->getMinutes() << FILE_DELIMITER << song->getSeconds() << FILE_DELIMITER
				 << song->getAlbum() << '\n';
		}
		
		listFile.close();
		std::cout << "Successfully saved " << songCount << " songs to \"" << SONG_FILE << "\"\n";
	}
	else
		std::cout << "Unable to save songs. Sorry :/\n";
}

unsigned int SongList::getSongCount() const
{
	return songCount;
}

Song* SongList::get(unsigned int index) const
{
	return (index < songCount ? songs[index] : nullptr);
}
