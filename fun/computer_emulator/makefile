# Made by Bruce Cosgrove

main: main.o Assembler.o Computer.o Reg8.o
	g++ -o main main.o Assembler.o Computer.o Reg8.o

main.o: main.cpp Assembler.h Computer.h Reg8.h
	g++ -c main.cpp Assembler.h Computer.h Reg8.h

Assembler.o: Assembler.cpp Assembler.h
	g++ -c Assembler.cpp

Computer.o: Computer.cpp Computer.h
	g++ -c Computer.cpp

Reg8.o: Reg8.cpp Reg8.h
	g++ -c Reg8.cpp

run:
	./main

clean:
	rm *.o

clobber:
	rm main *.gch
