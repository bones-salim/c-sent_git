#include "Nageoires.h"

Nageoires::Nageoires(Bestiole* bestiole, double speedMultiplier) : AccessoryDecorator(bestiole), speedMultiplier(speedMultiplier) {}

void Nageoires::ApplyEffect() {
    // Par exemple, augmenter la vitesse de la bestiole
}

void Nageoires::DrawEffect(UImg& support) {
    // Dessiner l'effet des nageoires
}

Nageoires* Nageoires::clone(Bestiole* bestiole) {
    return new Nageoires(bestiole, speedMultiplier);  // Créer une copie de l'objet Nageoires
}
