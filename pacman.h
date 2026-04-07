#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pacman {
private:
    int x;
    int y;

public:
    Pacman();
    Pacman(int x, int y);
    Pacmancolore(string colore);
    Pacmanforma(int forma);
    bool muovi(int spostaX, int spostaY);
    std::string toString() ;
};
