// Createur.h
#ifndef CREATEUR_H
#define CREATEUR_H
#include "Comportement.h"
class Createur {
public:
    virtual ~Createur() {}
    virtual Bestiole* creerBestiole(std::unique_ptr<Comportement>) = 0;
};

#endif