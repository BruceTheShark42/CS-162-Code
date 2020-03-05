// Made by Bruce Cosgrove

#include <iostream>
#include <cstring>

#include "SongList.h"
#include "util.h"

void printHelp() {
	std::cout << "To add a song to the database, type: \"add\"\n"
			  << "To display song information, type: \"display\"\n"
			  << "To remove a song by it's index, type: \"remove\"\n"
			  << "To search for a specific song, type: \"search\"\n"
			  << "To exit Seditor for now, type: \"exit\"\n"
			  << "To print the help menu, type: \"help\"\n";
}

void add(SongList& list) {
	String title = getString("Enter the song's title: ");
	if (contains(title.getChars(), SongList::FILE_DELIMITER)) {
		std::cout << "The title cannot include a '" << SongList::FILE_DELIMITER << "'.\n";;
		return;
	}
	
	String artist = getString("Enter the song's artist: ");
	if (contains(artist.getChars(), SongList::FILE_DELIMITER)) {
		std::cout << "The artist cannot include a '" << SongList::FILE_DELIMITER << "'.\n";;
		return;
	}
	
	unsigned int minutes = (unsigned int)getInt("Enter the song's duration in minutes rounded down: ");
	unsigned int seconds = (unsigned int)getInt("Enter the remaining seconds: ");
	
	String album = getString("Enter the song's album name: ");
	if (contains(album.getChars(), SongList::FILE_DELIMITER)) {
		std::cout << "The album cannot include a '" << SongList::FILE_DELIMITER << "'.\n";
		return;
	}
	
	list.add(title.getChars(), artist.getChars(), minutes, seconds, album.getChars());
}

void remove(SongList& list) {
	int index = getInt("Enter the index of the song you would like to remove: ", -1);
	if (index >= 0 && index < list.getSongCount()) {
		std::cout << "Are you sure you want to remove the song: \"" << list[index]->getTitle();
		String confirmation = getString("\"? (yes/no) ");
		if (!std::strcmp(confirmation.getChars(), "yes")) {
			std::cout << "Successfully removed \"" << list[index]->getTitle() << "\"\n";
			list.remove(index);
		} else if (std::strcmp(confirmation.getChars(), "no")) std::cout << "Taking \"" << confirmation << "\" as no.";
	} else std::cout << "Failed to remove a nonexistent song.";
} 

void search(SongList& list) {
	String searchType = getString("Would you like to search by artist or album: ");
	if (!std::strcmp(searchType.getChars(), "artist")) {
		String artist = getString("Enter the song's artist: ");
		if (artist.getLength()) list.search(artist.getChars(), true);
		else std::cout << "No artist entered.\n";
	} else if (!std::strcmp(searchType.getChars(), "album")) {
		String album = getString("Enter the song's album: ");
		if (album.getLength()) list.search(album.getChars(), false);
		else std::cout << "No album entered.\n";
	} else std::cout << "Unknown search type.\n";
}

int main() {
	SongList list;
	
	// Welcome message
	std::cout << "\nWelcome to Seditor, the song editor!\n";
	printHelp();
	std::cout << "Have fun!\n";
	
	bool editingSongs = true;
	while (editingSongs) {
		String userInput = getString("\nWhat would you like to do?\n> ");
		char *chars = userInput.getChars();
		
		if (!std::strcmp(chars, "add")) add(list);
		else if (!std::strcmp(chars, "display")) list.display();
		else if (!std::strcmp(chars, "remove")) remove(list);
		else if (!std::strcmp(chars, "search")) search(list);
		else if (!std::strcmp(chars, "exit")) editingSongs = false;
		else if (!std::strcmp(chars, "help")) printHelp();
		else std::cout << "Unknown command.\n";
	}
	
	std::cout << "Thank you for using Seditor!\n";
	return 0;
}
