# Made by Bruce Cosgrove

main: main.o CPU.o Reg8.o Reg16.o
	g++ -o main main.o CPU.o Reg8.o Reg16.o

main.o: main.cpp cpu/CPU.h cpu/reg/Reg8.h cpu/reg/Reg16.h
	g++ -c main.cpp cpu/CPU.h cpu/reg/Reg8.h cpu/reg/Reg16.h

CPU.o: cpu/CPU.cpp cpu/CPU.h
	g++ -c cpu/CPU.cpp

Reg16.o: cpu/reg/Reg16.cpp cpu/reg/Reg16.h
	g++ -c cpu/reg/Reg16.cpp

Reg8.o: cpu/reg/Reg8.cpp cpu/reg/Reg8.h
	g++ -c cpu/reg/Reg8.cpp

run:
	./main

clean:
	rm *.o

clobber:
	rm main
