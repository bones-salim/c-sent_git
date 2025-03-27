#ifndef GREGAIRE_H
#define GREGAIRE_H

#include "Comportement.h"
#include <memory>
#include <string>
#include <vector>

class Bestiole;
class Milieu;

class Gregaire : public Comportement {
private:
    Bestiole* bestiole; 
    double facteurAlign;  // Facteur d'alignement pour ajuster la direction
public:
    // Le constructeur n'a plus de valeur par défaut, les deux paramètres sont requis.
    Gregaire(double facteurAlign, Bestiole* bestiole);

    void behave(Milieu& milieu, std::vector<Bestiole>& environnement) override;
    std::string getNom() override;
    std::unique_ptr<Comportement> clone() override;
};

#endif
