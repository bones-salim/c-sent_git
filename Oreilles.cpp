#include "Oreilles.h"
#include <cmath>

// Constructeur
Oreilles::Oreilles(Bestiole* b, double delta, double capaciteDetection)
    : SensorDecorator(b), delta(delta), capaciteDetection(capaciteDetection) {
}

Oreilles::~Oreilles() {
}



SensorDecorator *Oreilles::clone(Bestiole *b) const {
    return new Oreilles(bestiole->clone(), delta, capaciteDetection);
}



bool Oreilles::dansChampAudition(const Bestiole &cible) const
{
    // Calculer la distance entre la bestiole décorée et la cible
    double dx = static_cast<double>(cible.getX() - bestiole->getX());
    double dy = static_cast<double>(cible.getY() - bestiole->getY());
    double distance = std::sqrt(dx * dx + dy * dy);

    // La cible est dans la zone d'audition si la distance est inférieure ou égale à δo
    return (distance <= delta);
}

bool Oreilles::jeTeDetecte(Bestiole& cible) {
    // La cible doit être dans la zone auditive
    if (!dansChampAudition(cible)) {
        return false;
    }
    // La détection réussit si la capacité de détection des oreilles (γo) est supérieure à la capacité de camouflage de la cible (ψ)
    return (capaciteDetection > cible.getVisibilite());
}
