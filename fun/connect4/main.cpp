// Made by Bruce Cosgrove

#include <iostream>
#include <string>
#include <cstdlib>

int getInt(const char *message, int error = -1) {
	std::cout << message;
	std::string str;
	std::getline(std::cin, str, '\n');
	try {
		return std::stoi(str);
	} catch (...) {
		return error;
	}
}

const unsigned int ROWS = 6, COLS = 7;
bool gameOver = false, tie = false, turn = false;
char board[ROWS][COLS];

bool isColFull(const unsigned int col) {
	return board[0][col];
}

char getChar(const unsigned int row, const unsigned int col) {
	switch (board[row][col]) {
		case 1: return 'X';
		case 2: return 'O';
		default: return ' ';
	}
}

void place(const unsigned int col) {
	unsigned int row = 0;
	while (row < ROWS - 1 && board[row + 1][col] == 0)
		++row;
	board[row][col] = 1 + turn;
}

void playerMove() {
	int col;
	do {
		col = getInt("Please enter the column to place your piece (0-6): ", -1);
		if (isColFull(col)) {
			std::cout << "That column is full.\n";
			col = -1;
		}
	} while (col < 0);
	place(col);
}

void aiMove() {
	int col;
	do {
		col = std::rand() % 7;
	} while (isColFull(col));
	place(col);
}

char checkWin() {
	const char piece = 1 + turn;
	for (unsigned int i = 0; i < ROWS; ++i)
		for (unsigned int j = 0; j < COLS - 3; ++j)
			if (board[i][j] == piece && board[i][j + 1] == piece && board[i][j + 2] == piece && board[i][j + 3] == piece)
				return true;
	for (unsigned int i = 0; i < ROWS - 3; ++i)
		for (unsigned int j = 0; j < COLS; ++j)
			if (board[i][j] == piece && board[i + 1][j] == piece && board[i + 2][j] == piece && board[i + 3][j] == piece)
				return true;
	for (unsigned int i = 0; i < ROWS - 3; ++i)
		for (unsigned int j = 0; j < COLS - 3; ++j)
			if (board[i][j] == piece && board[i + 1][j + 1] == piece && board[i + 2][j + 2] == piece && board[i + 3][j + 3] == piece)
				return true;
	for (unsigned int i = 3; i < ROWS; ++i)
		for (unsigned int j = 0; j < COLS - 3; ++j)
			if (board[i][j] == piece && board[i - 1][j + 1] == piece && board[i - 2][j + 2] == piece && board[i - 3][j + 3] == piece)
				return true;
	return false;
}

bool checkTie() {
	for (unsigned int i = 0; i < ROWS; ++i)
		for (unsigned int j = 0; j < COLS; ++j)
			if (board[i][j] == 0)
				return false;
	return true;
}

void draw() {
	for (unsigned int i = 0; i < COLS; ++i)
		std::cout << "| " << i << ' ';
	for (unsigned int i = 0; i < ROWS; ++i) {
		std::cout << "|\n";
		for (unsigned int j = 0; j < COLS; ++j) {
			const bool inverted = (i + j) % 2 == 0;
			std::cout << '|';
			if (inverted) std::cout << "\033[7m";
			std::cout << ' ' << getChar(i, j) << ' ';
			if (inverted) std::cout << "\033[0m";
		}
	}
	std::cout << "|\n-----------------------------\n";
}

int main() {
	draw();
	while (!gameOver) {
		if (turn) aiMove();
		else playerMove();
		draw();
		char win = checkWin();
		if (win) {
			std::cout << "Someone won\n";
			gameOver = true;
		} else if (checkTie()) {
			std::cout << "Tie\n";
			gameOver = true;
		} else {
			turn = !turn;
		}
	}
	return 0;
}
