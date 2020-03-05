// Made by Bruce Cosgrove

#ifndef SONG_LIST_H
#define SONG_LIST_H

class SongList {
public:
	SongList();
	~SongList();
public:
	void add(char *title, char *artist, const unsigned int &minutes, const unsigned int &seconds, char *album, bool silent = false);
	void display() const;
	void remove(const unsigned int &index);
	int search(char *searchParameter, bool searchByArtist) const;
	void importFromFile();
	void exportToFile() const;
	unsigned int getSongCount() const;
public:
	static const char FILE_DELIMITER = ';';
private:
	static constexpr const char *SONG_FILE = "songs.txt";
	class Song {
	public:
		Song(char *title, char *artist, const unsigned int &minutes, const unsigned int &seconds, char *album);
		~Song();
	public:
		char* getTitle() const;
		char* getArtist() const;
		unsigned int getMinutes() const;
		unsigned int getSeconds() const;
		char* getAlbum() const;
		void print() const;
		int compare(const Song &song);
	private:
		char *title;
		char *artist;
		struct {
			unsigned int minutes;
			unsigned int seconds;
		} duration;
		char *album;
	};
public:
	Song* operator[](const unsigned int &index) const;
private:
	struct Node {
		Node(Song *song = nullptr, Node *next = nullptr);
		Node(Node *prev, Song *song = nullptr);
		~Node();
		Song *song;
		Node *next;
	};
	void printSong(const Node *node, const unsigned int &index) const;
	
	Node *head;
	unsigned int songCount;
	bool altered;
};

#endif
