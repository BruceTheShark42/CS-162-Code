# Made by Bruce Cosgrove

main: main.o Computer.o RAM.o CPU.o Assembler.o
	g++ -o main main.o Computer.o RAM.o CPU.o Assembler.o

main.o: main.cpp Computer.h RAM.h CPU.h Assembler.h
	g++ -c main.cpp Computer.h RAM.h CPU.h Assembler.h

Computer.o: Computer.cpp Computer.h CPU.h RAM.h
	g++ -c Computer.cpp CPU.h RAM.h

RAM.o: RAM.cpp RAM.h
	g++ -c RAM.cpp

CPU.o: CPU.cpp CPU.h
	g++ -c CPU.cpp

Assembler.o: Assembler.cpp Assembler.h
	g++ -c Assembler.cpp

run:
	./main

clean:
	rm *.o

clobber:
	rm main

noclobber:
	rm *.gch
