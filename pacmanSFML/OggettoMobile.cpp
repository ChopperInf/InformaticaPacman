#include "OggettoMobile.h"
#include <cmath>   // cos, sin, atan2, sqrt


// ============================================================
//  Costruttori
// ============================================================

OggettoMobile::OggettoMobile()
{
    this->centroX = 0.0f;
    this->centroY = 0.0f;
    this->spostX = 0.0f;
    this->spostY = 0.0f;
    this->velocita = 0.0f;
    this->raggio = 16.0f;
    this->forma = L'O';
    this->coloreForma = FG_BIANCO;
    this->coloreSfondo = BG_NERO;
    this->imgFilePacMan = "";
}

OggettoMobile::OggettoMobile(float startX, float startY,
    float vel, float angoloDeg,
    float raggio,
    wchar_t f,
    sf::Color coloreForma,
    sf::Color coloreSfondo,
    string imgFilePacMan)
{
    this->centroX = startX;
    this->centroY = startY;
    this->velocita = vel;
    this->raggio = raggio;
    this->forma = f;
    this->coloreForma = coloreForma;
    this->coloreSfondo = coloreSfondo;
    this->spostX = 0.0f;
    this->spostY = 0.0f;
    this->imgFilePacMan = imgFilePacMan;

    impostaAngolo(angoloDeg);
}


// ============================================================
//  Getter
// ============================================================

float OggettoMobile::getX()        { return this->centroX; }
float OggettoMobile::getY()        { return this->centroY; }
float OggettoMobile::getVelocita() { return this->velocita; }
float OggettoMobile::getRaggio()   { return this->raggio; }

float OggettoMobile::getAngolo()
{
    // atan2 restituisce radianti nell'intervallo (-π, π]
    float rad = std::atan2(this->spostY, this->spostX);
    float deg = rad * 180.0f / static_cast<float>(PIGRECO);
    if (deg < 0.0f)
        deg += 360.0f;
    return deg;
}


// ============================================================
//  Setter
// ============================================================

void OggettoMobile::controllaPosizione(int larghezza, int altezza)
{
    float larg = static_cast<float>(larghezza);
    float alt = static_cast<float>(altezza);

    if (this->centroX - this->raggio < 0.0f)
        this->centroX = this->raggio;
    if (this->centroX + this->raggio > larg)
        this->centroX = larg - this->raggio;
    if (this->centroY - this->raggio < 0.0f)
        this->centroY = this->raggio;
    if (this->centroY + this->raggio > alt)
        this->centroY = alt - this->raggio;
}

void OggettoMobile::impostaPosizione(float nuovaX, float nuovaY,
    int larghezza, int altezza)
{
    this->centroX = nuovaX;
    this->centroY = nuovaY;
    controllaPosizione(larghezza, altezza);
}

void OggettoMobile::sposta(float dx, float dy, int larghezza, int altezza)
{
    this->centroX += dx;
    this->centroY += dy;
    controllaPosizione(larghezza, altezza);
}

void OggettoMobile::impostaVelocita(float vel)
{
    if (vel < 0.0f) vel = 0.0f;
    float angolo = std::atan2(this->spostY, this->spostX);
    this->velocita = vel;
    this->spostX = std::cos(angolo) * this->velocita;
    this->spostY = std::sin(angolo) * this->velocita;
}

void OggettoMobile::impostaAngolo(float angoloDeg)
{
    float rad = angoloDeg * static_cast<float>(PIGRECO) / 180.0f;
    this->spostX = std::cos(rad) * this->velocita;
    this->spostY = std::sin(rad) * this->velocita;
}

void OggettoMobile::accelera(float delta)
{
    float angolo = std::atan2(this->spostY, this->spostX);
    this->velocita += delta;
    if (this->velocita < 0.0f) this->velocita = 0.0f;
    this->spostX = std::cos(angolo) * this->velocita;
    this->spostY = std::sin(angolo) * this->velocita;
}

void OggettoMobile::impostaAspetto(wchar_t f,
    sf::Color coloreForma,
    sf::Color coloreSfondo)
{
    this->forma = f;
    this->coloreForma = coloreForma;
    this->coloreSfondo = coloreSfondo;
}


// ============================================================
//  Rimbalzo
// ============================================================

void OggettoMobile::rimbalzaX()
{
    this->spostX = -this->spostX;
}

void OggettoMobile::rimbalzaY()
{
    this->spostY = -this->spostY;
}


// ============================================================
//  Movimento
// ============================================================

void OggettoMobile::muoviConRimbalzoBordi(int larghezza, int altezza)
{
    float larg = static_cast<float>(larghezza);
    float alt = static_cast<float>(altezza);

    this->centroX += this->spostX;
    this->centroY += this->spostY;

    // ── Rimbalzo bordo sinistro / destro ──────────────────────
    if (this->centroX - this->raggio < 0.0f)
    {
        this->centroX = this->raggio;
        rimbalzaX();
    }
    if (this->centroX + this->raggio > larg)
    {
        this->centroX = larg - this->raggio;
        rimbalzaX();
    }

    // ── Rimbalzo bordo superiore / inferiore ──────────────────
    if (this->centroY - this->raggio < 0.0f)
    {
        this->centroY = this->raggio;
        rimbalzaY();
    }
    if (this->centroY + this->raggio > alt)
    {
        this->centroY = alt - this->raggio;
        rimbalzaY();
    }
}

void OggettoMobile::muoviRandomConRimbalzoBordi(int larghezza, int altezza)

{
    float larg = static_cast<float>(larghezza);
    float alt = static_cast<float>(altezza);

	
	bool muoviOrizzontale = (rand() % 2 == 0); // movimento verticale o orizzontale (50% ciascuno)
    int velRandom = 3;
    if (rand() % 2 == 0)  // positiva o negativa (50% ciascuno)
	    velRandom = -velRandom;
    if (muoviOrizzontale)
    {
        // movimento orizzontale: spostX è velocità, spostY è 0
        this->spostX = velRandom * this->velocita; // -velocita o +velocita
        this->spostY = 0.0f;
    }
    else
    {
        // movimento verticale: spostY è velocità, spostX è 0
        this->spostX = 0.0f;
        this->spostY = velRandom * this->velocita; // -velocita o +velocita
	}

    this->centroX += this->spostX;
    this->centroY += this->spostY;

    // ── Rimbalzo bordo sinistro / destro ──────────────────────
    if (this->centroX - this->raggio < 0.0f)
    {
        this->centroX = this->raggio;
        rimbalzaX();
    }
    if (this->centroX + this->raggio > larg)
    {
        this->centroX = larg - this->raggio;
        rimbalzaX();
    }

    // ── Rimbalzo bordo superiore / inferiore ──────────────────
    if (this->centroY - this->raggio < 0.0f)
    {
        this->centroY = this->raggio;
        rimbalzaY();
    }
    if (this->centroY + this->raggio > alt)
    {
        this->centroY = alt - this->raggio;
        rimbalzaY();
    }
}
void OggettoMobile::muoviInseguimento(OggettoMobile& bersaglio, int larghezza, int altezza)
{
    float dx = bersaglio.getX() - this->centroX;
    float dy = bersaglio.getY() - this->centroY;

    // Calcolo le distanze positive a mano
    float distPositivaX = dx;
    if (distPositivaX < 0) distPositivaX = -distPositivaX;

    float distPositivaY = dy;
    if (distPositivaY < 0) distPositivaY = -distPositivaY;

    this->spostX = 0.0f;
    this->spostY = 0.0f;

    // Se è più lontano in orizzontale, mi muovo sull'asse X
    if (distPositivaX > distPositivaY) {
        if (dx > 0) {
            this->spostX = this->velocita;
        }
        else {
            this->spostX = -this->velocita;
        }
    }
    // Altrimenti mi muovo sull'asse Y
    else {
        if (dy > 0) {
            this->spostY = this->velocita;
        }
        else {
            this->spostY = -this->velocita;
        }
    }

    this->centroX += this->spostX;
    this->centroY += this->spostY;
    controllaPosizione(larghezza, altezza);
}
// ============================================================
//  Disegno
// ============================================================


void OggettoMobile::aggiungiOggettoMobile(InterfacciaUtente& ui)
{
    if (!this->imgFilePacMan.empty())
    {
        // Scala il PNG affinché il diametro coincida con raggio*2
        float scala = 0;

        sf::Texture texture;
        if (texture.loadFromFile(this->imgFilePacMan))
        {
            sf::Vector2u dimTex = texture.getSize();
            float diametro = this->raggio * 2.0f;
            if (dimTex.x > 0)
                scala = diametro / static_cast<float>(dimTex.x);
            else
                scala = 1.0f;
        }
        // disegnaSprite vuole il centro
        ui.aggiungiImmagine(Punto(this->centroX, this->centroY), this->imgFilePacMan, scala, scala);
    }
}