// Createur.h
#ifndef CREATEUR_H
#define CREATEUR_H
<<<<<<< HEAD
#include "Comportement.h"
class Createur {
public:
    virtual ~Createur() {}
    virtual Bestiole* creerBestiole(std::unique_ptr<Comportement>) = 0;
=======


class Createur {
public:
    virtual ~Createur() {}
    virtual void creerEntite(Comportement* comp) = 0;
>>>>>>> 190583cf5849345e9f7cf7ae76a4d2235bc9af27
};

#endif