#include "Yeux.h"

Yeux::Yeux(Bestiole* bestiole, double alpha, double delta) : SensorDecorator(bestiole), alpha(alpha), delta(delta) {}

void Yeux::detecter() {
    // Implémentation spécifique pour détecter avec les yeux
    // Par exemple, augmenter la vision de la bestiole ou détecter un autre type d'entité
}



Yeux* Yeux::clone(Bestiole* bestiole) {
    return new Yeux(bestiole, alpha, delta);  // Créer une copie de l'objet Yeux
}
