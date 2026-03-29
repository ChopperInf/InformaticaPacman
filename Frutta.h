#pragma once
#include <string>
#include <iostream>
using namespace std;

class Frutta{
private:
	int riga;
	int colonna;
	int colore;
	char forma;
	bool visibile;
	int righe;
	int colonne;

public:
	Frutta();
	Frutta(int righe, int colonne, char forma);
	int getRiga();
	int getColonna();
	int getColore();
	char getForma();
	bool getVisibile();

	void setRiga(int riga);
	void setColonna(int colonna);
	void setColore(int colore);
	void setForma(char forma);
	void setVisibile(bool visibile);
	void setPosizione();

	void visualizzaSuSchermo(int righe, int colonne);

	string toString();
};
