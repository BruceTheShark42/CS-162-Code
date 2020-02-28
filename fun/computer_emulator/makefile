# Made by Bruce Cosgrove

main: main.o Computer.o RAM.o CPU.o Assembler.o
	g++ -o main main.o Computer.o RAM.o CPU.o Assembler.o

main.o: main.cpp Computer.h RAM.h CPU.h Assembler.h
	g++ -c main.cpp Computer.h RAM.h CPU.h Assembler.h

Computer.o: Computer.cpp Computer.h RAM.h CPU.h
	g++ -c Computer.cpp RAM.h CPU.h

RAM.o: RAM.cpp RAM.h
	g++ -c RAM.cpp

CPU.o: CPU.cpp CPU.h opcodes.h
	g++ -c CPU.cpp opcodes.h

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
