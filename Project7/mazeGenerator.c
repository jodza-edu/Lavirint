#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct polje {
	int trenV; //tren == trenutna
	int trenK;
};
struct posecenaPolja { //cuva recom posecena polja
	int vrsta[100];
	int kolona[100];
};
// todo: strukture pretvoriti u neku vrstu stack pair-a
 // todo: pretvori promenljive za strane ka orijentaciji na enum

struct polje Polje;
struct posecenaPolja Posecena;

int* ptrPosecenaVrsta = &Posecena.vrsta;
int* ptrPosecenaKolona = &Posecena.kolona;

generisi(int vrsta, int kolona, int nUlaza, int nIzlaza) {
	srand(time(NULL));

	//dodeli svima posecenost 0
	for (int i = 0; i < 100; i++) {
		Posecena.vrsta[i] = 0;
		Posecena.kolona[i] = 0;
	}


	Polje.trenK = 0;
	Polje.trenV = rand() % vrsta;

	Posecena.vrsta[0] = Polje.trenV;
	Posecena.kolona[0] = Polje.trenK;

	int brojPosecenih = 1;

	while (brojPosecenih < kolona*vrsta) {
		int lokacija[2] = { Polje.trenV, Polje.trenK };
		int brojVracanja = 1;
		if (slobodni(lokacija, vrsta, kolona, brojPosecenih, 0) == -1) {
			//vrati se nazad
			Polje.trenV = Posecena.vrsta[brojPosecenih - 1 - brojVracanja];
			Polje.trenK = Posecena.kolona[brojPosecenih - 1 - brojVracanja];
			brojVracanja++;
		}
		//pomeri se na dato polje i upisi da si ga posetio
		else {
			brojVracanja = 1;

			int skociNa[4];

			for (int i = 0; i < 4; i++) {
				skociNa[i] = slobodni(lokacija, vrsta, kolona, brojPosecenih, i);
			}
			int odaberi = izaberi(skociNa);

			if (odaberi == 1) {
				Polje.trenV--;
			}
			else if (odaberi == 2) {
				Polje.trenV++;
			}
			else if (odaberi == 3) {
				Polje.trenK--;
			}
			else if (odaberi == 4) {
				Polje.trenK++;
			}
			//upis posecenosti, redom
			lokacija[0] = Polje.trenV;
			lokacija[1] = Polje.trenK;
			if (!poseceno(lokacija, brojPosecenih)) {
				Posecena.vrsta[brojPosecenih] = Polje.trenV;
				Posecena.kolona[brojPosecenih] = Polje.trenK;

				//debug printer
				printf("%4d: %3d   | %3d\n",brojPosecenih, Polje.trenV, Polje.trenK);

				brojPosecenih++;
			}
		}
	}
}

int slobodni(int lokacija[2], int vrsta, int kolona, int brojPosecenih, int j) {
	
	int skociNa[4] = { 0,0,0,0 };
	
	//sever
	if (lokacija[0] != 0) {
		int privremenaLokacija[2] = { lokacija[0] - 1, lokacija[1] };
		if (!poseceno(privremenaLokacija, brojPosecenih)) {
			skociNa[0] = 1;
		}
	}
	else skociNa[0] = 0;
	//jug
	if (lokacija[0] < vrsta - 1) {
		int privremenaLokacija[2] = { lokacija[0] + 1, lokacija[1] };
		if (!poseceno(privremenaLokacija, brojPosecenih)) {
			skociNa[1] = 2;
		}
	}
	else skociNa[1] = 0;
	//zapad
	if (lokacija[1] != 0) {
		int privremenaLokacija[2] = { lokacija[0], lokacija[1] - 1 };
		if (!poseceno(privremenaLokacija, brojPosecenih)) {
			skociNa[2] = 3;
		}
	}
	else skociNa[2] = 0;
	//istok
	if (lokacija[1] < kolona - 1) {
		int privremenaLokacija[2] = { lokacija[0], lokacija[1] + 1 };
		if (!poseceno(privremenaLokacija, brojPosecenih)) {
			skociNa[3] = 4;
		}
	}
	else skociNa[3] = 0;
	
	int brojac = 0;
	for (int i = 0; i < 4; i++) {
		if (skociNa[i] == 0) brojac++;
	}
	if (brojac == 4) skociNa[0] = -1;

	return skociNa[j];
}

int izaberi(int *skociNa) {
	int element = 0;
	do {
		element = rand() % 4;
	} while (skociNa[element] < 1);
	return skociNa[element];

	/*for (int i = 0; i < 150; i++) {
		element = rand() % 4;
		if (skociNa[element] > 0 && skociNa[element] < 5) return skociNa[element];
	}
	return 0;*/
}

int poseceno(int *lokacija, int brojPosecenih) {

	for (int i = 0; i < brojPosecenih; i++) {
		if ((Posecena.vrsta[i] == lokacija[0]) && (Posecena.kolona[i] == lokacija[1])) return 1;
	}

	return 0;
}