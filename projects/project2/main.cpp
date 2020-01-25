// Made by Bruce Cosgrove

#include <iostream>
#include <fstream>
#include <cstring>

#include "Song.h"

#define MAX_SONGS 100
#define MAX_CHARS 100

// The "3 * MAX_CHARS + 23" comes from 
// the max possible characters for the 
// title, artist, and album, then an 
// extra 23 for the minutes and seconds. 
// 2^32-1 is the max for an unsigned int, 
// which is what the minutes and seconds 
// are stored as. This happens to be 10 
// digits, so just add some more room for 
// the separator tokens and that's the max.
#define MAX_FILE_LINE_LEN 3 * MAX_CHARS + 23

// TODO: --------------------------- Remove delimeter from inputs ---------------------------
#define FILE_DELIMITER ';'
#define SONG_FILE "songs.txt"

// Taken from project 1
// The "CompareCStrings" function has been removed
// and is being replaced by std::strcmp().
// Returns a char[] entered by the user
char* getString(const char* message)
{
	// Print the message
	std::cout << message;
	char* in = new char[MAX_CHARS];
	
	// Get user input
	std::cin.get(in, MAX_CHARS, '\n');
	
	// Help clean up io stuff
	std::cin.get();
	if (!std::cin)
	{
		std::cin.clear();
		std::cin.get();
	}
	
	return in;
}

int getInt(const char* message, int returnError = 0)
{
	char* numberInput = getString(message);
	
	// Validate input
	bool valid = true;
	if (!std::strlen(numberInput))
	{
		valid = false;
		std::cout << "No number present.\n";
	}
	
	for (unsigned int i = 0; valid && numberInput[i]; ++i)
		if (numberInput[i] < '0' || numberInput[i] > '9')
		{
			valid = false;
			std::cout << "Invalid number.\n";
		}
	
	if (valid)
	{
		int number = std::stoi(numberInput);
		delete[] numberInput;
		return number;
	}
	else
	{
		std::cout << "Defaulting to " << returnError << ".\n";
		delete[] numberInput;
		return returnError;
	}
}

bool contains(char* str1, const char* str2)
{
	unsigned int str1len = std::strlen(str1);
	unsigned int str2len = std::strlen(str2);
	
	if (str1len < str2len)
		return false;
	
	for (unsigned int i = 0; i < str1len - str2len + 1; ++i)
	{
		bool has = true;
		for (unsigned int j = 0; j < str2len; ++j)
			if (str1[i + j] != str2[j])
				has = false;
		if (has)
			return true;
	}
	
	return false;
}

bool addSongToList(Song** songList, unsigned int &songCount, char* title, char* artist, unsigned int minutes, unsigned int seconds, char* album, bool silent = false)
{
	if (songCount < MAX_SONGS)
	{
		songList[songCount] = new Song(title, artist, minutes, seconds, album);
		if (!silent)
			std::cout << "Successfully added \"" << title << "\" to the list at index " << songCount << ".\n";
		++songCount;
		return true;
	}
	else if (!silent)
		std::cout << "There are too many songs in your list.\n"
			  << "Please remove some of them to add any more.\n";
	return false;
}

void displaySongList(Song** songList, unsigned int songCount)
{
	if (songCount)
	{
		std::cout << "Here are your songs:\n";
		for (unsigned int i = 0; i < songCount; ++i)
			songList[i]->print(i);
	}
	else
		std::cout << "There are currently no songs in your list.\n";
}

void removeSongFromListByIndex(Song** songList, unsigned int &songCount, int index)
{
	if (index < 0 || index < songCount)
	{
		for (unsigned int i = index; i < songCount - 1; ++i)
			songList[i] = songList[i + 1];
		
		// The pointer has been copied to the spot behind, 
		// so just erase the original pointer, but don't 
		// free the memory, that would erase the song.
		songList[songCount--] = nullptr;
	}
	else
		std::cout << "The index is out of bounds.\n";
}

int searchListForSong(Song** songList, unsigned int songCount, const char* searchParameter, bool searchByArtist)
{
	for (unsigned int i = 0; i < songCount; ++i)
		if (contains((searchByArtist ? songList[i]->getArtist() : songList[i]->getAlbum()), searchParameter))
			songList[i]->print(i);
}

void loadSongsFromFileToList(Song** songList, unsigned int &songCount)
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
				
				addSongToList(songList, songCount, title, artist, 
					(unsigned int)std::stoi(minutes), 
					(unsigned int)std::stoi(seconds), album, true);
				
				--linesLeft;
			}
			else
				linesLeft = std::stoi(line);
		}
		
		listFile.close();
		std::cout << "Successfully loaded " << songCount << " songs from \"" << SONG_FILE << "\"\n";
	}
}

void exportSongsToFileFromList(Song** songList, unsigned int songCount)
{
	std::ofstream listFile(SONG_FILE);
	if (listFile.is_open())
	{
		// Send the number of songs
		listFile << songCount << '\n';
		
		// Send the song data
		for (unsigned int i = 0; i < songCount; ++i)
		{
			Song* song = songList[i];
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

void printHelp()
{
	std::cout << "To add a song to the database, type: \"add\"\n"
		  << "To display song information, type: \"display\"\n"
		  << "To remove a song by it's index, type: \"remove\"\n"
		  << "To search for a specific song, type: \"search\"\n"
		  << "To exit Seditor for now, type: \"exit\"\n"
		  << "To print the help menu, type: \"help\"\n";
}

int main()
{
	Song** songs = new Song*[MAX_SONGS];
	unsigned int songCount = 0;
	
	loadSongsFromFileToList(songs, songCount);
	
	// Welcome message
	std::cout << "\nWelcome to Seditor, the song editor!\n";
	printHelp();
	std::cout << "Have fun!\n";
	
	bool alteredList = false;
	
	bool editingSongs = true;
	while (editingSongs)
	{
		char* userInput = getString("\nWhat would you like to do?\n> ");
		
		if (!std::strcmp(userInput, "add"))
		{
			char* title = getString("Enter the song's title: ");
			char* artist = getString("Enter the song's artist: ");
			
			unsigned int minutes = (unsigned int)getInt("Enter the song's duration in minutes rounded down: ");
			unsigned int seconds = (unsigned int)getInt("Enter the remaining seconds: ");
			
			char* album = getString("Enter the song's album name: ");
			
			if (addSongToList(songs, songCount, title, artist, minutes, seconds, album))
				alteredList = true;
		}
		else if (!std::strcmp(userInput, "display"))
			displaySongList(songs, songCount);
		else if (!std::strcmp(userInput, "remove"))
		{
			int index = getInt("Enter the index of the song you would like to remove: ", -1);
			if (index >= 0 && index < songCount)
			{
				std::cout << "Are you sure you want to remove the song: \"" << songs[index]->getTitle();
				char* confirmation = getString("\"? (yes/no) ");
				if (!std::strcmp(confirmation, "yes"))
				{
					std::cout << "Successfully removed \"" << songs[index]->getTitle() << "\"\n";
					removeSongFromListByIndex(songs, songCount, index);
					alteredList = true;
				}
				else if (std::strcmp(confirmation, "no"))
					std::cout << "Taking \"" << confirmation << "\" as no.";
				
				// Memory management
				delete[] confirmation;
			}
			else
				std::cout << "Failed to remove a nonexistent song.";
		}
		else if (!std::strcmp(userInput, "search"))
		{
			char* searchType = getString("Would you like to search by artist or album: ");
			if (!std::strcmp(searchType, "artist"))
			{
				char* artist = getString("Enter the song's artist: ");
				if (std::strlen(artist))
					searchListForSong(songs, songCount, artist, true);
				else
					std::cout << "No artist entered.\n";
				
				// Memory management
				delete[] artist;
			}
			else if (!std::strcmp(searchType, "album"))
			{
				char* album = getString("Enter the song's album: ");
				if (std::strlen(album))
					searchListForSong(songs, songCount, album, false);
				else
					std::cout << "No album entered.\n";
				
				// Memory management
				delete[] album;
			}
			else
				std::cout << "Unknown search type.\n";
			
			// Memory management
			delete[] searchType;
		}
		else if (!std::strcmp(userInput, "exit"))
			editingSongs = false;
		else if (!std::strcmp(userInput, "help"))
			printHelp();
		else
			std::cout << "Unknown command.\n";
		
		// Memory management
		delete[] userInput;
	}
	
	// Save the songs before they're deleted if any changes have been made
	if (alteredList)
		exportSongsToFileFromList(songs, songCount);
	else
		std::cout << "No changes made, no saving needed.\n";
	
	// Memory management
	for (unsigned int i = 0; i < songCount; ++i)
		delete songs[i];
	delete[] songs;
	
	// Goodbye message
	std::cout << "Thank you for using Seditor!\n";
	
	return 0;
}
