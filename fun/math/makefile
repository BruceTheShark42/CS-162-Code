# Made by Bruce Cosrove

main: main.o Vec2.o Vec3.o
	g++ -o main main.o Vec2.o Vec3.o

main.o: main.cpp Vec2.h Vec3.h
	g++ -c main.cpp

Vec2.o: Vec2.cpp Vec2.h
	g++ -c Vec2.cpp Vec2.h

Vec3.o: Vec3.cpp Vec3.h
	g++ -c Vec3.cpp Vec3.h

run:
	./main

clean:
	rm *.o

clobber:
	rm main

noclobber:
	rm *.h.gch
