// Createur_Bestiole.cpp
#include "Createur_Bestiole.h"
#include "Comportement.h"

Createur_Bestiole* Createur_Bestiole::instance = nullptr;

Createur_Bestiole* Createur_Bestiole::getInstance() {
    if (!instance)
        instance = new Createur_Bestiole();
    return instance;
}

Bestiole* Createur_Bestiole::creerBestiole(int xLim, int yLim, Comportement* comp) {
    return new Bestiole(xLim, yLim, comp);
}



