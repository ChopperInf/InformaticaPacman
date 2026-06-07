#pragma once
#include "InterfacciaUtente.h"

// ============================================================
//  OGGETTO MOBILE — versione pixel
//
//  Posizione e velocità sono in pixel float.
//  Il rimbalzo usa i limiti in pixel del Campo.
//  Il disegno chiama campo.disegnaSprite() oppure
//  campo.disegnaCerchio() (nessun accesso a celle).
// ============================================================

class OggettoMobile {
public:

    // ── Costruttori ──────────────────────────────────────────

    // Default: fermo in (0,0), raggio 16, simbolo 'O'.
    OggettoMobile();

    // Completo.
    // startX, startY : centro in pixel
    // vel            : modulo velocità (pixel/frame)
    // angoloDeg      : direzione (0°=destra, 90°=giù, 180°=sinistra, 270°=su)
    // raggio         : usato per rimbalzo, disegno e collisioni
    // f              : carattere per modalità testo
    // coloreForma    : colore del carattere
    // coloreSfondo   : colore sfondo del cerchio (modalità testo)
    OggettoMobile(float centroX, float centroY,
        float vel, float angoloDeg,
        float raggio,
        wchar_t f,
        sf::Color coloreForma,
        sf::Color coloreSfondo,
        string imgFilePacMan = "");

    // ── Getter ────────────────────────────────────────────────

    float getX();
    float getY();
    float getVelocita();
    float getRaggio();

    // Angolo corrente in gradi (ricavato da spostX/spostY).
    float getAngolo();

    // ── Setter ────────────────────────────────────────────────

    // Sposta il centro a (nuovaX, nuovaY) — clampato ai bordi.
    void impostaPosizione(float nuovaX, float nuovaY, int larghezza, int altezza);

    // Trasla la posizione di (dx, dy) — clampato ai bordi.
    void sposta(float dx, float dy, int larghezza, int altezza);

    // Imposta il modulo della velocità mantenendo la direzione.
    void impostaVelocita(float vel);

    // Imposta la direzione in gradi ricalcolando spostX/spostY.
    void impostaAngolo(float angoloDeg);

    // Aumenta la velocità di 'delta' pixel/frame.
    void accelera(float delta);

    // Imposta carattere e colori (modalità testo).
    void impostaAspetto(wchar_t f, sf::Color coloreForma, sf::Color coloreSfondo);

    // ── Movimento ─────────────────────────────────────────────

    // Aggiunge spostX/spostY alla posizione e gestisce il rimbalzo
    // sui quattro bordi del campo (usa il raggio per uscire parzialmente).
    void muoviConRimbalzoBordi(int larghezza, int altezza);
    void muoviRandomConRimbalzoBordi(int larghezza, int altezza);
    void muoviInseguimento(OggettoMobile& bersaglio, int lunghezza, int altezza);

    // ── Disegno ───────────────────────────────────────────────

    // Chiama campo.disegnaSprite() o campo.disegnaCerchio()
    // alla posizione corrente.
    // Il chiamante è responsabile di chiamare campo.pulisci()
    // prima e campo.presenta() dopo — nessuna cancellazione
    // della posizione precedente è necessaria.
    void aggiungiOggettoMobile(InterfacciaUtente& ui);

private:

    float centroX, centroY;          // centro in pixel
    float spostX, spostY;
    float velocita;
    float raggio;

	// versione testuale: forma e colori
    wchar_t   forma;
    sf::Color coloreForma;
    sf::Color coloreSfondo;
    // versione grafica con nome file di immagine
    string imgFilePacMan;

    void rimbalzaX();
    void rimbalzaY();

    // Clamp della posizione entro i bordi del campo.
    void controllaPosizione(int larghezza, int altezza);
};