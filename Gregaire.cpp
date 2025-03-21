#include "Gregaire.h"
#include "Bestiole.h"
#include <cmath>

Gregaire::Gregaire(double facteurAlign) : facteurAlign(facteurAlign) {}

void Gregaire::appliquer(Bestiole& b, const std::vector<Bestiole>& environnement) {
    double directionMoyenne = 0;
    int count = 0;

    for (const auto& bestiole : environnement) {
        directionMoyenne += bestiole.direction;
        count++;
    }

    if (count > 0) {
        directionMoyenne /= count;
        b.direction = b.direction + facteurAlign * (directionMoyenne - b.direction);
    }
}