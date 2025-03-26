#include "Prevoyante.h"
#include "Bestiole.h"
#include <cmath>

// Constructeur initialisant la marge d'esquive
Prevoyante::Prevoyante(double margeEsquive) : margeEsquive(margeEsquive) {}

// Appliquer le comportement prévoyant
void Prevoyante::appliquer(Bestiole& b, const std::vector<Bestiole>& environnement) {
    for (const auto& bestiole : environnement) {
        // Ne pas se compter soi-même
        if (&bestiole != &b) {
            // Calculer la différence de direction entre la bestiole actuelle et une bestiole environnante
            double differenceDirection = std::abs(bestiole.getOrientation() - b.getOrientation());

            // Si la différence est inférieure à la marge d'esquive, ajuster la direction pour éviter une collision
            if (differenceDirection < margeEsquive) {
                double nouvelleDirection = b.getOrientation() + M_PI / 2;  // Tourner de 90 degrés
                b.setOrientation(nouvelleDirection);  // Mettre à jour la direction de la bestiole
            }
        }
    }
}
