# Made by Bruce Cosrove

main: main.o Mat.o
	g++ -o main main.o Mat.o

main.o: main.cpp Mat.h
	g++ -c main.cpp

#Vec2.o: Vec2.cpp Vec2.h
#	g++ -c Vec2.cpp Vec2.h

#Vec3.o: Vec3.cpp Vec3.h
#	g++ -c Vec3.cpp Vec3.h

#Vec4.o: Vec4.cpp Vec4.h
#	g++ -c Vec4.cpp Vec4.h

Mat.o: Mat.cpp Mat.h
	g++ -c Mat.cpp Mat.h

run:
	./main

clean:
	rm *.o

clobber:
	rm main

noclobber:
	rm *.h.gch
