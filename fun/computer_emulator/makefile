# Made by Bruce Cosgrove

main: main.o Computer.o RAM.o CPU.o Reg16.o
	g++ -o main main.o Computer.o RAM.o CPU.o Reg16.o

main.o: main.cpp Computer.h RAM.h CPU.h Reg16.h
	g++ -c main.cpp Computer.h RAM.h CPU.h Reg16.h

Computer.o: Computer.cpp Computer.h CPU.h RAM.h
	g++ -c Computer.cpp CPU.h RAM.h

RAM.o: RAM.cpp RAM.h
	g++ -c RAM.cpp

CPU.o: CPU.cpp CPU.h Reg16.h
	g++ -c CPU.cpp Reg16.h

Reg16.o: Reg16.cpp Reg16.h
	g++ -c Reg16.cpp

run:
	./main

clean:
	rm *.o

clobber:
	rm main

noclobber:
	rm *.gch
