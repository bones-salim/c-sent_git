#include "Yeux.h"
#include <cmath>

// Constructeur
Yeux::Yeux(Bestiole* b, double alpha, double delta, double capaciteDetection)
    : CapteurDecorator(b), alpha(alpha), delta(delta), capaciteDetection(capaciteDetection) {
}

Yeux::~Yeux() {
}

void Yeux::detecter() {
    // Implémentation de la logique de détection globale.
    // Par exemple, parcourir l'ensemble des bestioles dans le milieu et utiliser jeTeDetecte.
}

BestioleDecorator* Yeux::clone() const {
    return new Yeux(bestiole->clone(), alpha, delta, capaciteDetection);
}

bool Yeux::dansChampVision(const Bestiole& cible) const {
    // Calculer la distance entre la bestiole décorée et la cible
    double dx = static_cast<double>(cible.x - bestiole->x);
    double dy = static_cast<double>(cible.y - bestiole->y);
    double distance = std::sqrt(dx * dx + dy * dy);

    // Vérifier si la cible est dans la distance maximale (delta)
    if (distance > delta) {
        return false;
    }

    // Calculer l'angle entre la ligne joignant les deux bestioles et l'orientation de la bestiole décorée
    double angleToCible = std::atan2(dy, dx);
    double orientation = bestiole->orientation; // En radians

    // Calculer la différence angulaire en s'assurant qu'elle est dans [0, π]
    double angleDifference = std::fabs(angleToCible - orientation);
    if (angleDifference > M_PI) {
        angleDifference = 2 * M_PI - angleDifference;
    }

    // La cible est dans le champ de vision si l'angle différentiel est inférieur à alpha/2
    return (angleDifference <= (alpha / 2.0));
}

bool Yeux::jeTeDetecte(const Bestiole& cible) const {
    // La cible doit d'abord être dans le champ de vision
    if (!dansChampVision(cible)) {
        return false;
    }
    // Puis la capacité de détection de la bestiole (γy) doit être supérieure à la capacité de camouflage de la cible (ψ)
    return (capaciteDetection > cible.getCamouflage());
}
