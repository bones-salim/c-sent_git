#ifndef PERSONNALITESMULTIPLES_H
#define PERSONNALITESMULTIPLES_H

#include "Comportement.h"
#include <vector>

class PersonnalitesMultiples : public Comportement {
private:
    std::vector<Comportement*> comportements;
    Comportement* comportementActuel;
    double probaChangement;

public:
    PersonnalitesMultiples(double probaChangement);
    void ajouterComportement(Comportement* comportement);
    void appliquer(Bestiole& bestiole, const std::vector<Bestiole>& environnement) override;
};

#endif