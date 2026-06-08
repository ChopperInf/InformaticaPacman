<<<<<<< HEAD
﻿#include "GameEngine.h"

// ============================================================
//  Costanti schermata
// ============================================================

const float RAGGIO_PALLINA = 20.0f;
const float PASSO_TASTO = 10.0f;   // pixel per pressione freccia
const float PASSO_ANGOLO = 5.0f;   // gradi per pressione rotazione o/a (orario/antiorario)
const int   RITARDO_MS = 100;      // ~60 fps

const int RIGA_TITOLO = 1;
const int COL_TITOLO = 4;

GameEngine::GameEngine(InterfacciaUtente& ui, wstring nomeGiocatore)
    : ui(ui)    // qui GameEngine usa un riferimento a InterfacciaUtente, 
                // quindi nel costruttore è necessario usare la lista di inizializzazione : ui(ui)
{
    this->nomeGiocatore = nomeGiocatore;

    // ── Creazione pacMan ─────────────────────────────────────
    // Centrato al centro del campo, diretta a sinistra (180°),
    // velocità iniziale 0.
    float pacManX = (LARGHEZZA_FINESTRA) / 2.0f;
    float pacManY = (ALTEZZA_FINESTRA) / 2.0f;
	float pacManVel = 0.0f;
	float pacManAngolo  = 180.0f;

    this->pacMan = OggettoMobile(pacManX, pacManY,
        pacManVel, pacManAngolo,
        RAGGIO_PALLINA,
		"./images/pacMan.png"); // immagine PNG di PacMan (con trasparenza)

    // ── Creazione Fantasma ─────────────────────────────────────
    // Centrato al sinistra del campo, diretta in diagonale (45°),
    // velocità iniziale 10.
    float fantasmaX = (LARGHEZZA_FINESTRA) / 1.5f;
    float fantasmaY = (ALTEZZA_FINESTRA) / 1.5f;
    float fantasmaVel = 10.0f;
    float fantasmaAngolo = 45.0f;

    this->fantasma = OggettoMobile(fantasmaX, fantasmaY,
        fantasmaVel, fantasmaAngolo,
        RAGGIO_PALLINA,
        "./images/ghost.png"); // immagine PNG di PacMan (con trasparenza)
}

void GameEngine::run() {
	// inizializza random per movimento fantasma
	srand(static_cast<unsigned int>(time(nullptr)));

    bool finito = false;

	int larghezzaCampo = ui.getLarghezza();
	int altezzaCampo = ui.getAltezza();
    // ── Game loop ─────────────────────────────────────────────
    while (!finito)
    {
        int tasto = ui.leggiTasto();

        // ── Uscita ────────────────────────────────────────────
        if (tasto == TASTO_ESC)
            finito = true;

        // ── Spostamento con frecce (10 px) ────────────────────
        if (tasto == TASTO_SU)
            pacMan.sposta(0.0f, -PASSO_TASTO, larghezzaCampo, altezzaCampo);
        if (tasto == TASTO_GIU)
            pacMan.sposta(0.0f, PASSO_TASTO, larghezzaCampo, altezzaCampo);
        if (tasto == TASTO_SINISTRA)
            pacMan.sposta(-PASSO_TASTO, 0.0f, larghezzaCampo, altezzaCampo);
        if (tasto == TASTO_DESTRA)
            pacMan.sposta(PASSO_TASTO, 0.0f, larghezzaCampo, altezzaCampo);

        // ── Spostamento legato alla velocità ────────────────
        fantasma.muoviRandomConRimbalzoBordi(larghezzaCampo, altezzaCampo);

        // ── Rendering ─────────────────────────────────────────
        ui.pulisci();

        aggiungiSfondo();

        // PacMan
        pacMan.aggiungiOggettoMobile(ui);
        // Fantasma
        fantasma.aggiungiOggettoMobile(ui);

        ui.disegna();

        ui.sleep(RITARDO_MS);
    }
}

void GameEngine::aggiungiSfondo() {
    // Bordo decorativo
    ui.aggiungiRettangoloVuoto(Punto(2, 2),
        LARGHEZZA_FINESTRA - 6, ALTEZZA_FINESTRA - 6,
        FG_ROSSO_I, 2.0f);

    // Titolo
    ui.aggiungiTestoAlCentro(RIGA_TITOLO, L"PACKMAN");

    // info: nome, posizione e direzione
    wchar_t info[128];
    swprintf(info, 128,
        L"%ls  |  pos (%.0f, %.0f)  |  dir %.0f\u00B0  |  vel %.1f px/f",
        nomeGiocatore.c_str(),
        pacMan.getX(), pacMan.getY(),
        pacMan.getAngolo(), pacMan.getVelocita());
    ui.aggiungiTestoRigCol(Posizione(2, 2), info);
}
=======
﻿#include "GameEngine.h"

// ============================================================
//  Costanti schermata
// ============================================================

const float RAGGIO_PALLINA = 20.0f;
const float PASSO_TASTO = 10.0f;   // pixel per pressione freccia
const float PASSO_ANGOLO = 5.0f;   // gradi per pressione rotazione o/a (orario/antiorario)
const int   RITARDO_MS = 100;      // ~60 fps

const int RIGA_TITOLO = 1;
const int COL_TITOLO = 4;

GameEngine::GameEngine(InterfacciaUtente& ui, wstring nomeGiocatore)
    : ui(ui)    // qui GameEngine usa un riferimento a InterfacciaUtente, 
                // quindi nel costruttore è necessario usare la lista di inizializzazione : ui(ui)
{
    this->nomeGiocatore = nomeGiocatore;

    // ── Creazione pacMan ─────────────────────────────────────
    // Centrato al centro del campo, diretta a sinistra (180°),
    // velocità iniziale 0.
    float pacManX = (LARGHEZZA_FINESTRA) / 2.0f;
    float pacManY = (ALTEZZA_FINESTRA) / 2.0f;
	float pacManVel = 0.0f;
	float pacManAngolo  = 180.0f;

    this->pacMan = OggettoMobile(pacManX, pacManY,
        pacManVel, pacManAngolo,
        RAGGIO_PALLINA,
        L'\u25CF',        // ● cerchio pieno Unicode se file immagine non esiste
        FG_GIALLO_I,
        BG_VERDE,
		"./images/pacMan.png"); // immagine PNG di PacMan (con trasparenza)

    // ── Creazione Fantasma ─────────────────────────────────────
    // Centrato al sinistra del campo, diretta in diagonale (45°),
    // velocità iniziale 10.
    float fantasmaX = (LARGHEZZA_FINESTRA) / 1.5f;
    float fantasmaY = (ALTEZZA_FINESTRA) / 1.5f;
    float fantasmaVel = 10.0f;
    float fantasmaAngolo = 45.0f;

    this->fantasma = OggettoMobile(fantasmaX, fantasmaY,
        fantasmaVel, fantasmaAngolo,
        RAGGIO_PALLINA,
        L'\u25CF',        // ● cerchio pieno Unicode se file immagine non esiste
        FG_GIALLO_I,
        BG_VERDE,
        "./images/ghost.png"); // immagine PNG di PacMan (con trasparenza)
}

void GameEngine::run() {
    // inizializza random per movimento fantasma
    srand(static_cast<unsigned int>(time(nullptr)));

    bool finito = false;

    int larghezzaCampo = ui.getLarghezza();
    int altezzaCampo = ui.getAltezza();

    // ── Game loop ─────────────────────────────────────────────
    while (!finito)
    {
        int tasto = ui.leggiTasto();

        // ── Uscita ────────────────────────────────────────────
        if (tasto == TASTO_ESC)
            finito = true;

        // ── Spostamento con frecce (10 px) ────────────────────
        if (tasto == TASTO_SU)
            pacMan.sposta(0.0f, -PASSO_TASTO, larghezzaCampo, altezzaCampo);
        if (tasto == TASTO_GIU)
            pacMan.sposta(0.0f, PASSO_TASTO, larghezzaCampo, altezzaCampo);
        if (tasto == TASTO_SINISTRA)
            pacMan.sposta(-PASSO_TASTO, 0.0f, larghezzaCampo, altezzaCampo);
        if (tasto == TASTO_DESTRA)
            pacMan.sposta(PASSO_TASTO, 0.0f, larghezzaCampo, altezzaCampo);

        // ── Spostamento legato alla velocità (Inseguimento) ──
        fantasma.muoviInseguimento(pacMan, larghezzaCampo, altezzaCampo);

        // ── Controllo Morte / Game Over ────────────────────────────────────
        float distX = pacMan.getX() - fantasma.getX();
        float distY = pacMan.getY() - fantasma.getY();

        // Tolgo il meno se la distanza è negativa
        if (distX < 0) {
            distX = -distX;
        }
        if (distY < 0) {
            distY = -distY;
        }

        // Il limite per toccarsi è il raggio per due
        float limite = pacMan.getRaggio() * 2.0f;

        // Se le distanze sono minori del limite, c'è lo scontro
        if (distX < limite && distY < limite) {

            ui.pulisci();
            aggiungiSfondo();
            ui.aggiungiTestoAlCentro(12, L"SEI STATO MANGIATO DAL FANTASMA!");
            ui.aggiungiTestoAlCentro(14, L"=== GAME OVER ===");
            ui.disegna();

            ui.sleep(3000); // Pausa di 3 secondi

            finito = true;
            break; // Salta il resto del codice ed esce subito dal while
        }

        // ── Rendering (avviene solo se non c'è stato Game Over) ──
        ui.pulisci();

        aggiungiSfondo();

        // PacMan
        pacMan.aggiungiOggettoMobile(ui);
        // Fantasma
        fantasma.aggiungiOggettoMobile(ui);

        ui.disegna();

        ui.sleep(RITARDO_MS);
    }
}
void GameEngine::aggiungiSfondo() {
    // Bordo decorativo
    ui.aggiungiRettangoloVuoto(Punto(2, 2),
        LARGHEZZA_FINESTRA - 6, ALTEZZA_FINESTRA - 6,
        FG_ROSSO_I, 2.0f);

    // Titolo
    ui.aggiungiTestoAlCentro(RIGA_TITOLO, L"PACKMAN");

    // info: nome, posizione e direzione
    wchar_t info[128];
    swprintf(info, 128,
        L"%ls  |  pos (%.0f, %.0f)  |  dir %.0f\u00B0  |  vel %.1f px/f",
        nomeGiocatore.c_str(),
        pacMan.getX(), pacMan.getY(),
        pacMan.getAngolo(), pacMan.getVelocita());
    ui.aggiungiTestoRigCol(Posizione(2, 2), info);
}
>>>>>>> bf62bf95eec73800e2b7570cee74387ad756f41c
