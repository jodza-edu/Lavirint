#include "stdio.h"
#include "mazeGenerator.h"

void generisiGrafiku(int nVrsta, int nKolona) {

	//za implementaciju zidova koristimo 0 i +

	//pravimo novu matricu, ciji elementi sadrze (redni) broj
	//kada je to polje poseceno

	for (int i = 0; i < nVrsta; i++) {
		
		//printf("0");

		// TO BE IMPROVED
		// todo: treba doraditi print
		// treba printati matrice
		for (int j = 0; j < nKolona; j++) {
			//susedna gore

			for (int k = 0; k < 2; k++) {

				if (matrPosecenihKoordinata[i][j] == matrPosecenihKoordinata[i - 1][j] && i > 0) {
					//susedna dole
					if (matrPosecenihKoordinata[i][j] == matrPosecenihKoordinata[i + 1][j]) {
						//printf("0 0");
						switch (k) {
						case 0:
							printf(" 0");
							break;
						case 1:
							printf(" 0");
							break;
						default:
							break;
						}
						
						
					}
					//susedna zapad
					else if (matrPosecenihKoordinata[i][j] == matrPosecenihKoordinata[i][j - 1] && j > 0) {
						//printf("0 0");											
						switch (k) {
						case 0:
							printf(" 0");
							break;
						case 1:
							printf("00");
							break;
						default:
							break;
						}
						
						
					}
					//susedna istok
					else if (matrPosecenihKoordinata[i][j] == matrPosecenihKoordinata[i][j + 1]) {
						//printf("0 0");
						switch (k) {
						case 0:
							printf("  ");
							break;
						case 1:
							printf("00");
							break;
						default:
							break;
						}						
					}
					//jedina
					else {
						//printf("0 0");
						switch (k) {
						case 0:
							printf(" 0");
							break;
						case 1:
							printf("00");
							break;
						default:
							break;
						}
						
						
					}

				}
				//susedna dole
				else if (matrPosecenihKoordinata[i][j] == matrPosecenihKoordinata[i + 1][j]) {
					//susedna zapad
					if (matrPosecenihKoordinata[i][j] == matrPosecenihKoordinata[i][j - 1] && j > 0) {
						//printf("000");
						switch (k) {
						case 0:
							printf(" 0");
							break;
						case 1:
							printf(" 0");
							break;
						default:
							break;
						}						
					}
					//susedna istok
					else if (matrPosecenihKoordinata[i][j] == matrPosecenihKoordinata[i][j + 1]) {
						//printf("000");
						switch (k) {
						case 0:
							printf("  ");
							break;
						case 1:
							printf(" 0");
							break;
						default:
							break;
						}
						
						
					}
					//jedina
					else {
						//printf("000");
						switch (k) {
						case 0:
							printf(" 0");
							break;
						case 1:
							printf(" 0");
							break;
						default:
							break;
						}
						
						
					}
				}
				//susedna zapad
				else if (matrPosecenihKoordinata[i][j] == matrPosecenihKoordinata[i][j - 1] && j > 0) {
					//susedna istok
					if (matrPosecenihKoordinata[i][j] == matrPosecenihKoordinata[i][j + 1]) {
						//printf("000");
						switch (k) {
						case 0:
							printf("  ");
							break;
						case 1:
							printf("00");
							break;
						default:
							break;
						}
						
						
					}
					//jedina
					else {
						//printf("000");
						switch (k) {
						case 0:
							printf(" 0");
							break;
						case 1:
							printf("00");
							break;
						default:
							break;
						}
						
						
					}
				}
				//susedna istok samo
				else if (matrPosecenihKoordinata[i][j] == matrPosecenihKoordinata[i][j + 1]) {
					//printf("000");
					switch (k) {
					case 0:
						printf("  ");
						break;
					case 1:
						printf("00");
						break;
					default:
						break;
					}
					
					
				} 
			} 
		}printf("\n");
	}
}