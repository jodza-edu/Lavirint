/*
main funkcija u source ce da sadrzi samo naredbe za generisanje lavirinta
odgovarajuce velicine i, u narednom poglavlju, naredbu za resavanje lavirinta
*/

#include "stdio.h"
#include "graphicsGenerator.h"
#include "mazeGenerator.h"

void main() {


	generisi(8, 8, 1, 1);
	for (int i = 0; i < 64; i++) {
		printf("%3d: %3d   | %3d\n", i, ptrPosecenaVrsta[i], ptrPosecenaKolona[i]);
	}

}