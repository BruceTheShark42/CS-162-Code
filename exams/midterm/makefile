CC = g++
CPPFLAGS = -Wall -g -std=c++11
all:	midterm.cc
	rm -f midterm
	$(CC) $(CPPFLAGS)  -o midterm midterm.cc

run: all
	./midterm

.PHONY: clean
clean:	
	$(info -- cleaning the direcotry --)
	rm -f midterm

