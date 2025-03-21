#include "Carapace.h"

Carapace::Carapace(Bestiole* bestiole, double eta, double omega) : AccessoryDecorator(bestiole), eta(eta), omega(omega) {}

void Carapace::ApplyEffect() {
    // Implémentation de l'effet de la carapace
    // Par exemple, augmenter la défense ou diminuer la vitesse
}

void Carapace::DrawEffect(UImg& support) {
    // Dessiner l'effet de la carapace sur l'entité bestiole
}

Carapace* Carapace::clone(Bestiole* bestiole) {
    return new Carapace(bestiole, eta, omega);  // Créer une copie de l'objet Carapace
}
