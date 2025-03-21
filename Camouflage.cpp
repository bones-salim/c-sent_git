#include "Camouflage.h"

Camouflage::Camouflage(Bestiole* bestiole, double psi) : AccessoryDecorator(bestiole), psi(psi) {}

void Camouflage::ApplyEffect() {
    // Par exemple, rendre la bestiole plus difficile à voir pour d'autres bestioles
}

void Camouflage::DrawEffect(UImg& support) {
    // Dessiner l'effet du camouflage
}

Camouflage* Camouflage::clone(Bestiole* bestiole) {
    return new Camouflage(bestiole, psi);  // Créer une copie de l'objet Camouflage
}
