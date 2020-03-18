CC = g++
CPPFLAGS = -Wall -g -std=c++11
all:	final.cc
	rm -f final
	$(CC) $(CPPFLAGS)  -o final final.cc

run: all
	./final

.PHONY: clean
clean:	
	$(info -- cleaning the direcotry --)
	rm -f final

