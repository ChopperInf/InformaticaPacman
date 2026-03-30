
#define PALLINO_H

class Pallino {
private:
    int x;
    int y;
    bool mangiato;

public:
    
    Pallino(int coord_x, int coord_y);

    int getX();
    int getY();
    bool IsMangiato();

    void mangia();
};

