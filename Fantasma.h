#include <iostream>
#include <string>
using namespace std;

class Fantasma {
private:
    int x;
    int y;
    int colore;

public:
    Fantasma(int startX, int startY, int c);
    void muovi();
    void disegna();
    int getX()
    int getY()
};