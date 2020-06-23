#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct polje {
	int trenV; //tren == trenutna
	int trenK;
};
struct posecenaPolja { //cuva redom posecena polja
	int vrsta[100];
	int kolona[100];
};
// todo: strukture pretvoriti u neku vrstu stack pair-a
 // todo: pretvori promenljive za strane ka orijentaciji na enum
enum strane {
	SEVER = 0x01,
	JUG = 0x02,
	ZAPAD = 0x03,
	ISTOK = 0x04,
	PUNO = 0x10
};


struct polje Polje;
struct posecenaPolja Posecena;



int* ptrPosecenaVrsta = &Posecena.vrsta;
int* ptrPosecenaKolona = &Posecena.kolona;

int matrPosecenihKoordinata[100][100];
int brojPosecenih = 0;
int lokacija[2];
int smer[4];

int susediZauzeti(int smer[4]) {
	int brojac = 0;
	for (int i = 0; i < 4; i++) {
		if (smer[i] == PUNO) brojac++;
	}
	if (brojac == 4) return 1;
	else return 0;
}

void setPosecena(int vrsta, int kolona, int brojPosecenih) {

	Posecena.vrsta[brojPosecenih] = vrsta;
	Posecena.kolona[brojPosecenih] = kolona;
	matrPosecenihKoordinata[vrsta][kolona] = 1;
	//brojPosecenih++;

}
void setTrenutno(int vrsta, int kolona) {
	Polje.trenV = vrsta;
	Polje.trenK = kolona;
	//setLokacija
	lokacija[0] = vrsta;
	lokacija[1] = kolona;
}


generisi(int vrsta, int kolona, int nUlaza, int nIzlaza) {
	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		Posecena.vrsta[i] = 0;
		Posecena.kolona[i] = 0;
	}

	//////dodeli svima posecenost 0
	////for (int i = 0; i < 100; i++) {
	////	
	////}

	setTrenutno(rand() % vrsta, 0);

	setPosecena(Polje.trenV, Polje.trenK, 0);
	brojPosecenih++;
	int brojVracanja = 1;

	while (brojPosecenih < kolona*vrsta) {
		
		slobodniSusedi(lokacija, brojPosecenih, vrsta, kolona);

		if (susediZauzeti(smer)) {
			//vrati se nazad
			setTrenutno(Posecena.vrsta[brojPosecenih - 1 - brojVracanja], Posecena.kolona[brojPosecenih - 1 - brojVracanja]);

			brojVracanja++;
		}
		//pomeri se na dato polje i upisi da si ga posetio
		else {
			brojVracanja = 1;

			
			int predjiNa = izaberi(smer);
			int sj = 0;	//location modifiers
			int zi = 0;

			if (predjiNa == SEVER) {
				sj = -1;
			}
			else if (predjiNa == JUG) {
				sj = 1;
			}
			else if (predjiNa == ZAPAD) {
				zi = -1;
			}
			else if (predjiNa == ISTOK) {
				zi = 1;
			}
			//upis posecenosti, redom
			setTrenutno(Polje.trenV + sj, Polje.trenK + zi);
			setPosecena(Polje.trenV, Polje.trenK, brojPosecenih);
			brojPosecenih++;

			//debug print
			//printf("%3d: %3d   | %3d\n", brojPosecenih, Polje.trenV, Polje.trenK);

		}
	}
}

int slobodniSusedi(int *lokacija, int brojPosecenih, int nVrsta, int nKolona) {
	
	//sever
	if (!matrPosecenihKoordinata[lokacija[0] - 1][lokacija[1]] && lokacija[0] != 0) smer[0] = SEVER;
	else smer[0] = PUNO;
	//jug
	if (!matrPosecenihKoordinata[lokacija[0] + 1][lokacija[1]] && lokacija[0] != nVrsta - 1) smer[1] = JUG;
	else smer[1] = PUNO;
	//zapad
	if (!matrPosecenihKoordinata[lokacija[0]][lokacija[1] - 1] && lokacija[1] != 0) smer[2] = ZAPAD;
	else smer[2] = PUNO;
	//istok
	if (!matrPosecenihKoordinata[lokacija[0]][lokacija[1] + 1] && lokacija[1] != nKolona - 1) smer[3] = ISTOK;
	else smer[3] = PUNO;

	return 0;
}

int izaberi(int *smer) {
	
	do {
		int random = rand() % 4;
		if (smer[random] != PUNO) return smer[random];
	} while (1);
}

int poseceno(int *lokacija, int brojPosecenih) {

	for (int i = 0; i < brojPosecenih; i++) {
		if ((Posecena.vrsta[i] == lokacija[0]) && (Posecena.kolona[i] == lokacija[1])) return 1;
	}

	return 0;
}