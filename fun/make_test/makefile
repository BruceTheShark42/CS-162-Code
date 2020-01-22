main : main.o Printer1.o Printer2.o
	g++ -o main main.o Printer1.o Printer2.o

main.o : main.cpp Printer1.h Printer2.h
	g++ -c main.cpp

Printer2.o : Printer2.cpp Printer2.h
	g++ -c Printer2.cpp

Printer1.o : Printer1.cpp Printer1.h
	g++ -c Printer1.cpp

run :
	./main

clean :
	rm Printer1.o Printer2.o main.o
