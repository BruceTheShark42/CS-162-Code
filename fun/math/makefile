# Made by Bruce Cosrove

main: main.o Complex.o
	g++ -o main main.o Complex.o

main.o: main.cpp Complex.h
	g++ -c main.cpp

#Vec2.o: Vec2.cpp Vec2.h
#	g++ -c Vec2.cpp Vec2.h

#Vec3.o: Vec3.cpp Vec3.h
#	g++ -c Vec3.cpp Vec3.h

#Vec4.o: Vec4.cpp Vec4.h
#	g++ -c Vec4.cpp Vec4.h

#Mat.o: Mat.cpp Mat.h
#	g++ -c Mat.cpp Mat.h

Complex.o: Complex.cpp Complex.h
	g++ -c Complex.cpp Complex.h

run:
	./main

clean:
	rm *.o

clobber:
	rm main

noclobber:
	rm *.h.gch
