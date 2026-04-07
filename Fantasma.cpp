#include "Fantasma.h"
#include <iostream>
#include <windows.h>
using namespace std;

Fantasma::Fantasma(int startX, int startY, int c) {
    x = startX;
    y = startY;
    colore = c;
}

void Fantasma::muovi() {
    x += (rand() % 3) - 1;
    y += (rand() % 3) - 1;
    if (x < 0) 
        x = 0; 
    if (x > 30) 
        x = 30;
    if (y < 0) 
        y = 0; 
    if (y > 15) 
        y = 15;
}

void Fantasma::disegna() {
    vai(x, y);

    cout << "$";
}