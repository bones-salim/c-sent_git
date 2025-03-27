#include "Gregaire.h"
#include "Bestiole.h"
#include "Milieu.h"
#include <cmath>

Gregaire::Gregaire(double facteurAlign, Bestiole *bestiole)
    : bestiole(bestiole), facteurAlign(facteurAlign) {
}

void Gregaire::behave(Milieu& milieu, std::vector<Bestiole>& environnement) {
    double directionMoyenne = 0;
    int count = 0;

    for (const auto& b : environnement) {
        directionMoyenne += b.getOrientation();
        count++;
    }

    if (count > 0) {
        directionMoyenne /= count;
        bestiole->setOrientation(bestiole->getOrientation() +
                                 facteurAlign * (directionMoyenne - bestiole->getOrientation()));
    }
}

std::string Gregaire::getNom() {
    return "Gregaire";
}

std::unique_ptr<Comportement> Gregaire::clone() {
    return std::make_unique<Gregaire>(facteurAlign, bestiole);
}
