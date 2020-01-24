app: app.o list.o
	g++ -o app app.o list.o

app.o: app.cpp list.h
	g++ -c app.cpp

list.o: list.cpp list.h
	g++ -c list.cpp

run:
	./app

clean:	
	rm app.o list.o

clobber:
	rm app
