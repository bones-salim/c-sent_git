// Createur_Bestiole.h
#ifndef CREATEUR_BESTIOLE_H
#define CREATEUR_BESTIOLE_H

#include "Createur.h"
#include "Bestiole.h"
#include "Comportement.h"

class Createur_Bestiole : public Createur {
private:
    static Createur_Bestiole* instance;
    Createur_Bestiole() {} // Singleton
    Createur_Bestiole(const Createur_Bestiole&) = delete;
    Createur_Bestiole& operator=(const Createur_Bestiole&) = delete;

public:
    static Createur_Bestiole* getInstance();
    Bestiole* creerBestiole(Comportement* comp);
};

#endif