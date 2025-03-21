#include "Oreilles.h"

Oreilles::Oreilles(Bestiole* bestiole, double delta) : SensorDecorator(bestiole), delta(delta) {}

void Oreilles::detecter() {
    // Implémentation spécifique pour détecter avec les oreilles
    // Par exemple, détecter des sons ou des vibrations
}


Oreilles* Oreilles::clone(Bestiole* bestiole) {
    return new Oreilles(bestiole, delta);  // Créer une copie de l'objet Oreilles
}
