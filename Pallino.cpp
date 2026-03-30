#include "PallinoClass.h"


Pallino::Pallino(int coord_x, int coord_y) {
    this->x = coord_x;
    this->y = coord_y;
    mangiato = false;
}


int Pallino::getX() {
    return this->x;
}


int Pallino::getY() {
    return this->y;
}


bool Pallino::IsMangiato() {
    return this->mangiato;
}


void Pallino::mangia() {
    this->mangiato = true;
}