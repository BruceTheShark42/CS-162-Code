// Made by Bruce Cosgrove

#include <iostream>
#include <cstring>

#include "SongList.h"

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
	SongList list;
	
	// Welcome message
	std::cout << "\nWelcome to Seditor, the song editor!\n";
	printHelp();
	std::cout << "Have fun!\n";
	
	bool editingSongs = true;
	while (editingSongs)
	{
		char* userInput = getString("\nWhat would you like to do?\n> ");
		
		if (!std::strcmp(userInput, "add"))
		{
			char* title = getString("Enter the song's title: ");
			if (contains(title, SongList::FILE_DELIMITER))
			{
				std::cout << "The title cannot include a '" << SongList::FILE_DELIMITER << "'.\n";;
				delete[] title;
				continue;
			}
			
			char* artist = getString("Enter the song's artist: ");
			if (contains(artist, SongList::FILE_DELIMITER))
			{
				std::cout << "The artist cannot include a '" << SongList::FILE_DELIMITER << "'.\n";;
				// Fixed a memory leak :O
				delete[] title;
				delete[] artist;
				continue;
			}
			
			unsigned int minutes = (unsigned int)getInt("Enter the song's duration in minutes rounded down: ");
			unsigned int seconds = (unsigned int)getInt("Enter the remaining seconds: ");
			
			char* album = getString("Enter the song's album name: ");
			if (contains(album, SongList::FILE_DELIMITER))
			{
				std::cout << "The album cannot include a '" << SongList::FILE_DELIMITER << "'.\n";
				// Fixed a memory leak :O
				delete[] title;
				delete[] artist;
				delete[] album;
				continue;
			}
			
			list.add(title, artist, minutes, seconds, album);
		}
		else if (!std::strcmp(userInput, "display"))
			list.display();
		else if (!std::strcmp(userInput, "remove"))
		{
			int index = getInt("Enter the index of the song you would like to remove: ", -1);
			if (index >= 0 && index < list.getSongCount())
			{
				std::cout << "Are you sure you want to remove the song: \"" << list.get(index)->getTitle();
				char* confirmation = getString("\"? (yes/no) ");
				if (!std::strcmp(confirmation, "yes"))
				{
					std::cout << "Successfully removed \"" << list.get(index)->getTitle() << "\"\n";
					list.remove(index);
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
					list.search(artist, true);
				else
					std::cout << "No artist entered.\n";
				
				// Memory management
				delete[] artist;
			}
			else if (!std::strcmp(searchType, "album"))
			{
				char* album = getString("Enter the song's album: ");
				if (std::strlen(album))
					list.search(album, false);
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
	
	// Memory management for songs taken care of in SongList destructor
	
	// Goodbye message
	std::cout << "Thank you for using Seditor!\n";
	
	return 0;
}
