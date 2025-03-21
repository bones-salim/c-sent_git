#ifndef GREGAIRE_H
#define GREGAIRE_H

#include "Comportement.h"

class Gregaire : public Comportement {
private:
    double facteurAlign;

public:
    Gregaire(double facteurAlign);
    void appliquer(Bestiole& bestiole, const std::vector<Bestiole>& environnement) override;
};

#endif