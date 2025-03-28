#include "Oreilles.h"
#include "Bestiole.h"

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

bool Oreilles::jeTeDetecte(Bestiole &cible) {
    // La cible doit être dans la zone auditive
    if (!dansChampAudition(cible)) {
        return false;
    }
    // La détection réussit si la capacité de détection des oreilles (γo) est supérieure à la capacité de camouflage de la cible (ψ)
    return (capaciteDetection > cible.getVisibilite());
}

void Oreilles::drawEffect(UImg &support) {
    // Récupération de la position et orientation via les getters
    int x = bestiole->getX();
    int y = bestiole->getY();
    double orientation = bestiole->getOrientation();

    // On définit des constantes de dimensionnement pour l'oreille
    double base = bestiole->getAFF_SIZE()  ;
    double height = bestiole->getAFF_SIZE()  ;

    // Calcul des coordonnées d'un triangle représentant une oreille
    int x1 = x + static_cast<int>(cos(orientation - M_PI/2) * base);
    int y1 = y - static_cast<int>(sin(orientation - M_PI/2) * base);
    int x2 = x1 + static_cast<int>(cos(orientation) * height);
    int y2 = y1 - static_cast<int>(sin(orientation) * height);
    int x3 = x1 + static_cast<int>(cos(orientation + M_PI/6) * base);
    int y3 = y1 - static_cast<int>(sin(orientation + M_PI/6) * base);

    // Couleur noire pour les oreilles
    unsigned char blanc[3] = {255, 255, 255};
    support.draw_triangle(x1, y1, x2, y2, x3, y3, blanc);
}
