#include "stdio.h"
#include "mazeGenerator.h"

void generisiGrafiku(int *vrsta, int *kolona, int nVrsta, int nKolona) {

	//za implementaciju zidova koristimo _ i |

	//pravimo novu matricu, ciji elementi sadrze (redni) broj
	//kada je to polje poseceno
	int matr[100][100];

	for (int i = 0; i < nVrsta; i++) {
		for (int j = 0; j < nKolona; j++) {

			for (int k = 0; k < nVrsta * nKolona;k++) {
				if (i == vrsta[k] && j == kolona[k]) matr[i][j] = k;
			}

		}
	}

	//generisemo zidove
	for (int i = 0; i < nVrsta; i++) {
		for (int j = 1; j < nKolona; j++) {
			
			//if ((susedno(vrsta, kolona, i, j, 0) && susedno(vrsta, kolona, i, j, 1)) || (i == 0 && susedno(vrsta, kolona, i, j, 1)) {
			//	printf("|");	

			//}
		}
	}
}

int susedno(int* vrsta, int* kolona, int i, int j, int k) {

	int susedni[4] = { 0,0,0,0 }; //N, S, W, E
	if (vrsta[j] = vrsta[j - 1] - 1) {
		susedni[0] = 1;
	}
	else if (vrsta[j] = vrsta[j + 1] - 1){
		susedni[1] = 1;
	}
	else if (kolona[j] = kolona[j - 1] - 1) {
		susedni[2] = 1;
	}
	else if (vrsta[j] = kolona[j + 1] - 1) {
		susedni[3] = 1;
	}
	return susedni[k];
}