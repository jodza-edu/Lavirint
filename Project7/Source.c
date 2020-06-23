/*
main funkcija u source ce da sadrzi samo naredbe za generisanje lavirinta
odgovarajuce velicine i, u narednom poglavlju, naredbu za resavanje lavirinta
*/

#include "stdio.h"
#include "graphicsGenerator.h"
#include "mazeGenerator.h"

void main() {

	int a = 6;
	int b = 6;
	generisi(a, b, 1, 1);
	printf("\n\n\tI Z G E N E R I S A N O\n\n\n");
	for (int i = 0; i < a*b; i++) {
		printf("%3d: %3d   | %3d\n", i + 1, ptrPosecenaVrsta[i], ptrPosecenaKolona[i]);
	}
	
	generisiGrafiku(a, b);

}