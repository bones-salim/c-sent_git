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

    void behave( std::vector<std::unique_ptr<Bestiole>>& environnement);
    std::string getNom() const override;
    std::unique_ptr<Comportement> clone(Bestiole* bestiole) const override;

};

#endif
