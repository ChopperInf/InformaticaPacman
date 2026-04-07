#include <iostream>
#include "Frutta.h"
#include "Pacman.h"
#include "PallinoClass.h"
#include ""
using namespace std;

int main() {
    srand(time(NULL));

    Pacman p1(5, 10);
	Frutta mela = Frutta(4, 2, 'O');
	Pallino pallino(10, 5);
    Fantasma f[] = {
        Fantasma(10, 5, 12);
        Fantasma(15, 5, 10);
        Fantasma(20, 5, 15);
        Fantasma(25, 5, 9);
    };

    //PACMAN
    p1.muovi(5, 10);

    //FANTASMA
    while (true) {
        system("cls");

        for (int i = 0; i < 4; i++) {
            f[i].muovi();
            f[i].disegna();
        }
    }

    //PALLINO
	cout << "Pallino creato a X: " << pallino.getX() << ", Y: " << pallino.getY() << endl;
	cout << "E' gia' stato mangiato? " << pallino.IsMangiato() << endl;
	cout << "Pac-Man passa e lo mangia" << endl;
	pallino.mangia();
	cout << "E' stato mangiato ora? " << pallino.IsMangiato() << endl;

    //FRUTTA
	mela.setPosizione();
	mela.visualizzaSuSchermo(10, 4);
	cout << mela.toString();

	return 0;
}