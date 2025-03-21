#ifndef GREGAIRE_H
#define GREGAIRE_H

#include "Comportement.h"

class Gregaire : public Comportement {
private:
    double facteurAlign;  // Facteur d'alignement pour ajuster la direction

public:
    // Constructeur prenant un facteur d'alignement
    Gregaire(double facteurAlign);

    // Appliquer le comportement grégaire à une bestiole
    void appliquer(Bestiole& bestiole, const std::vector<Bestiole>& environnement) override;
};

#endif
