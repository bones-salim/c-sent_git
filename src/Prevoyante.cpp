#include "Prevoyante.h"
#include "Bestiole.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif  

// Constructeur initialisant la marge d'esquive
Prevoyante::Prevoyante(double margeEsquive, Bestiole *bestiole)
    : bestiole(bestiole), margeEsquive(margeEsquive) {
}

// Appliquer le comportement prévoyant
void Prevoyante::behave(std::vector<std::unique_ptr<Bestiole>>& environnement) {
    for (const auto& bestiole1 : environnement) {
        // Ne pas se compter soi-même (comparaison correcte via .get())
        if (bestiole1.get() != bestiole) {
            double differenceDirection = std::abs(bestiole1->getOrientation() - bestiole->getOrientation());

            // Vérifier la marge d'esquive et ajuster la direction pour éviter une collision
            if (differenceDirection < margeEsquive) {
                double nouvelleDirection = bestiole->getOrientation() + M_PI / 2;  // Tourner de 90 degrés
                bestiole->setOrientation(nouvelleDirection);  // Mettre à jour la direction
            }
        }
    }
}

// Méthodes supplémentaires nécessaires :

std::string Prevoyante::getNom() const {
    return "Prevoyante";
}

std::unique_ptr<Comportement> Prevoyante::clone(Bestiole* bestiole) const {
    return std::make_unique<Prevoyante>(margeEsquive, bestiole);
}
