#ifndef PREVOYANTE_H
#define PREVOYANTE_H

#include "Comportement.h"

class Prevoyante : public Comportement {
private:
    double margeEsquive;

public:
    Prevoyante(double margeEsquive);
    void appliquer(Bestiole& bestiole, const std::vector<Bestiole>& environnement) override;
};

#endif