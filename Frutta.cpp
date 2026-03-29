#include "Frutta.h"

Frutta::Frutta()
{
	this->riga = 0;
	this->colonna = 0;
	this->righe = 0;
	this->colonne = 0;
	this->colore = 1;
	this->forma = 'O';
	this->visibile = false;
}

Frutta::Frutta(int righe, int colonne, char forma) {

	this->riga = righe;
	this->colonna = colonne;
	this->colore = 1;
	this->forma = forma;
	this->visibile = true;
}

int Frutta::getRiga()
{
	return riga;
}

int Frutta::getColonna()
{
	return colonna;
}

int Frutta::getColore()
{
	return colore;
}

char Frutta::getForma()
{
	return forma;
}

bool Frutta::getVisibile()
{
	return visibile;
}

void Frutta::setRiga(int riga)
{
	this->riga = riga;
}

void Frutta::setColonna(int colonna)
{
	this->colonna = colonna;
}

void Frutta::setColore(int colore)
{
	this->colore = colore;
}

void Frutta::setForma(char forma)
{
	this->forma = forma;
}
void Frutta::setPosizione() {
	srand(time(NULL));
	this->riga = rand() % riga;
	this->colonna = rand() % colonna;
}

void Frutta::setVisibile(bool visibile) {
	this->visibile = visibile;
}

string Frutta::toString() {
	string str;
	int numel = 10;
	for (int i = 0; i < numel; i++){

		for (int j = 0; j < numel; j++){

			if (i == this->riga && j == this->colonna && visibile) {

				str += forma;
			}
			else {
				str += " ";
			}
		}
		cout << endl;
	}
	return str;
}

void Frutta::visualizzaSuSchermo(int righe, int colonne)
{

	for (int i = 0; i < righe; i++)
	{
		for (int j = 0; j < colonne; j++)
			
		{
			if (i == this->riga && j == this->colonna)
				
				cout << forma;
			else
				cout << " ";
		}
		cout << endl;
	}
}
