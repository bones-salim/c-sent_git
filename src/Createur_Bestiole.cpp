// Createur_Bestiole.cpp
#include "Createur_Bestiole.h"
#include "Comportement.h"


Bestiole* Createur_Bestiole::creerBestiole(std::unique_ptr<Comportement> comp) {
    return new Bestiole(std::move(comp));  
}



