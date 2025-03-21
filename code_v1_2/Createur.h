// Createur.h
#ifndef CREATEUR_H
#define CREATEUR_H

class Createur {
public:
    virtual ~Createur() {}
    virtual void creerEntite(int, int) = 0;
};

#endif