#include "Gregaire.h"
#include "Bestiole.h"
#include <cmath>

Gregaire::Gregaire(double facteurAlign, Bestiole *bestiole) 
    : bestiole(bestiole), facteurAlign(facteurAlign) {

}


void Gregaire::behave( std::vector<std::unique_ptr<Bestiole>>& environnement) {
    double directionMoyenne = 0;
    int count = 0;

    for (const auto& bestiole : environnement) {
        directionMoyenne += bestiole->getOrientation();
        count++;
    }

    if (count > 0) {
        directionMoyenne /= count;
        bestiole->setOrientation( bestiole->getOrientation() + facteurAlign * (directionMoyenne - bestiole->getOrientation()));
    }
}

std::string Gregaire::getNom() const {
    return "Gregaire";
}
std::unique_ptr<Comportement> Gregaire::clone(Bestiole* bestiole) const {
    return std::make_unique<Gregaire>(facteurAlign, bestiole);
}

