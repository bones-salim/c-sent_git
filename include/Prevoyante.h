#ifndef PREVOYANTE_H
#define PREVOYANTE_H

#include "Comportement.h"
#include "Bestiole.h"


class Prevoyante : public Comportement {
private:
    Bestiole *bestiole;
    double margeEsquive;

public:
    Prevoyante(double margeEsquive, Bestiole *bestiole);
    void behave(std::vector<std::unique_ptr<Bestiole>>& environnement);
    std::string getNom() const;
    std::unique_ptr<Comportement> clone(Bestiole* bestiole) const override;


};

#endif
