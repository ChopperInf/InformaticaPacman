#include "Pacman.h"
#include <string>

Pacman::Pacman(int x, int y) {
    this->x = x;
    this->y = y;
}


bool Pacman::muovi(int spostax, int spostay) {
    x = spostax;
    y = spostay;
    return true;
}
string Pacman::colore(int colore) {
    
    return true;
}
