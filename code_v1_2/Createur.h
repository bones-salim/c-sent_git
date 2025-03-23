// Createur.h
#ifndef CREATEUR_H
#define CREATEUR_H

class Createur {
public:
    virtual ~Createur() {}
    virtual void creerEntite(Comportement* comp) = 0;
};

#endif