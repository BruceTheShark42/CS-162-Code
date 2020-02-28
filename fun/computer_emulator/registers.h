// Made by Bruce Cosgrove

#ifndef REGISTERS_H
#define REGISTERS_H

enum Reg8 {
	A, F, B, C, D, E, H, L, IXH, IXL, IYH, IYL, N, pBC, pDE, pHL, pIXpN, pIYpN, pSP, pNN, I, R
};

enum Reg16 {
	AF, BC, DE, HL, IX, IY, SP, PC, NN
};

#endif
