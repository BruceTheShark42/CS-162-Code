main: main.o Student.o
	g++ -o main main.cpp Student.o

main.o: main.cpp Student.h
	g++ -c main.cpp

Student.o: Student.cpp Student.h
	g++ -c Student.cpp

run:
	./main

clean:
	rm Student.o main.o

clobber:
	rm main
