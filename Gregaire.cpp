#include "Gregaire.h"
#include "Bestiole.h"
#include <cmath>

// Constructeur initialisant le facteur d'alignement
Gregaire::Gregaire(double facteurAlign) : facteurAlign(facteurAlign) {}

// Appliquer le comportement grégaire
void Gregaire::appliquer(Bestiole& b, const std::vector<Bestiole>& environnement) {
    double directionMoyenne = 0;  // Variable pour stocker la direction moyenne des bestioles environnantes
    int count = 0;                // Compteur pour le nombre de bestioles environnantes

    // Calculer la direction moyenne des bestioles environnantes
    for (const auto& bestiole : environnement) {
        directionMoyenne += bestiole.getOrientation();  // Utilisation de getOrientation() pour obtenir la direction
        count++;
    }

    // Si des bestioles sont détectées, ajuster la direction de la bestiole actuelle
    if (count > 0) {
        directionMoyenne /= count;  // Calcul de la direction moyenne
        double nouvelleDirection = b.getOrientation() + facteurAlign * (directionMoyenne - b.getOrientation());
        b.setOrientation(nouvelleDirection);  // Mise à jour de la direction de la bestiole
    }
}
