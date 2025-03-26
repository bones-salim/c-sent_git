#ifndef PERSONNALITESMULTIPLES_H
#define PERSONNALITESMULTIPLES_H

#include "Comportement.h"
#include <vector>

class PersonnalitesMultiples : public Comportement {
private:
    std::vector<Comportement*> comportements;  // Liste des comportements disponibles
    Comportement* comportementActuel;          // Comportement actuellement appliqué
    double probaChangement;                    // Probabilité de changer de comportement

public:
    // Constructeur avec la probabilité de changement de comportement
    PersonnalitesMultiples(double probaChangement);

    // Ajouter un nouveau comportement à la liste
    void ajouterComportement(Comportement* comportement);

    // Appliquer le comportement actuel à la bestiole
    void appliquer(Bestiole& bestiole, const std::vector<Bestiole>& environnement) override;
};

#endif
