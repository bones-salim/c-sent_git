#include "Gregaire.h"
#include "Bestiole.h"
#include <cmath>

Gregaire::Gregaire(double facteurAlign) : facteurAlign(facteurAlign) {

}

void Gregaire::behave(const std::vector<Bestiole>& environnement) {
    double directionMoyenne = 0;
    int count = 0;

    for (const auto& bestiole : environnement) {
        directionMoyenne += bestiole.getOrientation();
        count++;
    }

    if (count > 0) {
        directionMoyenne /= count;
        b.setOrientation( b.getOrientation() + facteurAlign * (directionMoyenne - b.getOrientation()));
    }
}