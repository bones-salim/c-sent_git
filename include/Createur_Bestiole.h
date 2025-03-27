// Createur_Bestiole.h
#ifndef CREATEUR_BESTIOLE_H
#define CREATEUR_BESTIOLE_H

#include "Createur.h"
#include "Bestiole.h"
#include "Comportement.h"

class Createur_Bestiole : public Createur {

public:
    Createur_Bestiole() {} // Singleton
    Bestiole* creerBestiole(std::unique_ptr<Comportement>) override;
};

#endif