// Made by Bruce Cosgrove

#include "SongList.h"

#include <iostream>
#include <fstream>
#include <cstring>

#include "util.h"

// Song
SongList::Song::Song(char *title, char *artist, const unsigned int &minutes, const unsigned int &seconds, char *album) {
	duration.minutes = minutes + seconds / 60;
	duration.seconds = seconds % 60;
	this->title = new char[std::strlen(title) + 1];
	std::strcpy(this->title, title);
	this->artist = new char[std::strlen(artist) + 1];
	std::strcpy(this->artist, artist);
	this->album = new char[std::strlen(album) + 1];
	std::strcpy(this->album, album);
}

SongList::Song::~Song() {
	delete[] title;
	delete[] artist;
	delete[] album;
}

char* SongList::Song::getTitle() const { return title; }
char* SongList::Song::getArtist() const { return artist; }
unsigned int SongList::Song::getMinutes() const { return duration.minutes; }
unsigned int SongList::Song::getSeconds() const { return duration.seconds; }
char* SongList::Song::getAlbum() const { return album; }

void SongList::Song::print() const {
	std::cout << "    - Title: " << title << '\n'
		  << "    - Artist: " << artist << '\n'
		  << "    - Duration: " << duration.minutes << ':' << (duration.seconds < 10 ? "0" : "") << duration.seconds << '\n'
		  << "    - Album: " << album << '\n';
}

// Node
SongList::Node::Node(Song *song, Node *next) : song(song), next(next) {}
SongList::Node::Node(Node *prev, Song *song) : song(song), next(prev->next) { prev->next = this; }
SongList::Node::~Node() { delete song; }

// SongList
int SongList::Song::compare(const Song &song) { return std::strcmp(title, song.title); }

SongList::SongList() : head(new Node()), songCount(0), altered(false) {
	importFromFile();
}

SongList::~SongList() {
	if (altered) exportToFile();
	else std::cout << "No changes made; no saving needeed.\n";
	for (Node *node = head, *next; node != nullptr; node = next) {
		next = node->next;
		delete node;
	}
}

void SongList::add(char* title, char* artist, const unsigned int& minutes, const unsigned int& seconds, char* album, bool silent) {
	Song *newSong = new Song(title, artist, minutes, seconds, album);
	Node *prev = head;
	for (Node *node = prev->next; node != nullptr && node->song->compare(*newSong) < 0; prev = node, node = node->next);
	new Node(prev, newSong);
	if (!silent) {
		std::cout << "Successfully added \"" << title << "\" to the list at index " << songCount << ".\n";
		altered = true;
	}
	++songCount;
}

void SongList::display() const {
	if (songCount != 0) {
		std::cout << "Here are your songs:\n";
		Node *node = head->next;
		for (unsigned int i = 0; i < songCount; ++i, node = node->next)
			printSong(node, i);
	} else std::cout << "There are currently no songs in your list.\n";
}

void SongList::printSong(const Node *node, const unsigned int& index) const {
	std::cout << "-----------------------\n  Song " << index << ":\n";
	node->song->print();
}

void SongList::remove(const unsigned int& index) {
	if (index < songCount) {
		Node *node = head;
		for (unsigned int i = 0; i < index; ++i, node = node->next);
		Node *toDelete = node->next;
		if (toDelete != nullptr) {
			node->next = node->next->next;
			delete toDelete;
		}
		altered = true;
		--songCount;
	} else std::cout << "The index is out of bounds.\n";
}

int SongList::search(char *searchParameter, bool searchByArtist) const {
	Node *node = head->next;
	for (unsigned int i = 0; i < songCount; ++i, node = node->next)
		if (contains((searchByArtist ? node->song->getArtist() : node->song->getAlbum()), searchParameter))
			printSong(node, i);
}

void SongList::importFromFile() {
	std::ifstream file(SONG_FILE);
	if (file.is_open()) {
		int linesLeft = -1;
		while (!file.eof() && linesLeft) {
			String line;
			for (char c = file.get(); c != '\n'; c = file.get())
				line.append(c);
			
			if (linesLeft > 0) {
				unsigned int indexToAdd = 0;
				String *inputs = new String[5];
				
				for (unsigned int i = 0; i < line.getLength(); ++i) {
					if (line[i] == FILE_DELIMITER) ++indexToAdd;
					else inputs[indexToAdd].append(line[i]);
				}
				add(inputs[0].getChars(), inputs[1].getChars(), (unsigned int)std::stoi(inputs[2].getChars()), 
					(unsigned int)std::stoi(inputs[3].getChars()), inputs[4].getChars(), true);
				
				delete[] inputs;
				--linesLeft;
			} else linesLeft = std::stoi(line.getChars());
		}
		
		file.close();
		std::cout << "Successfully loaded " << songCount << " songs from \"" << SONG_FILE << "\"\n";
	} else {
		std::cout << "Unable to load songs from \"" << SONG_FILE << "\"\n";
	}
}

void SongList::exportToFile() const {
	std::ofstream file(SONG_FILE);
	if (file.is_open()) {
		file << songCount << '\n';
		for (Node *node = head->next; node != nullptr; node = node->next) {
			Song *song = node->song;
			file << song->title << FILE_DELIMITER << song->artist << FILE_DELIMITER 
				 << song->duration.minutes << FILE_DELIMITER << song->duration.seconds << FILE_DELIMITER
				 << song->album << '\n';
		}
		
		file.close();
		std::cout << "Successfully saved " << songCount << " songs to \"" << SONG_FILE << "\"\n";
	} else std::cout << "Unable to save songs. Sorry :/\n";
}

SongList::Song* SongList::operator[](const unsigned int& index) const {
	Node *node = head->next;
	for (unsigned int i = 0; i < index && node != nullptr; ++i, node = node->next);
	if (node != nullptr) return node->song;
	else return nullptr;
}

unsigned int SongList::getSongCount() const { return songCount; }
