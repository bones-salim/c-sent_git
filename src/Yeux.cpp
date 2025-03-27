#include "Yeux.h"
#include "Bestiole.h"
#include <cmath>

Yeux::Yeux(Bestiole* b, double alpha, double delta, double capaciteDetection)
    : SensorDecorator(b), alpha(alpha), delta(delta), capaciteDetection(capaciteDetection) { }

Yeux::~Yeux() { }

bool Yeux::dansChampVision(const Bestiole &cible) const {
    double dx = static_cast<double>(cible.getX() - bestiole->getX());
    double dy = static_cast<double>(cible.getY() - bestiole->getY());
    double distance = std::sqrt(dx * dx + dy * dy);
    if (distance > delta)
        return false;
    double angleToCible = std::atan2(dy, dx);
    double orientation = bestiole->getOrientation();
    double angleDiff = std::fabs(angleToCible - orientation);
    if (angleDiff > M_PI)
        angleDiff = 2 * M_PI - angleDiff;
    return (angleDiff <= (alpha / 2.0));
}

bool Yeux::jeTeDetecte(Bestiole &cible)  {
    if (!dansChampVision(cible))
        return false;
    return (capaciteDetection > cible.getVisibilite());
}

SensorDecorator* Yeux::clone(Bestiole* b) const {
    return new Yeux(b, alpha, delta, capaciteDetection);
}
// Méthode de dessin des yeux
void Yeux::drawEffect(UImg &support) {
    // Récupération de la position et orientation via les getters
    int x = bestiole->getX();
    int y = bestiole->getY();
    double orientation = bestiole->getOrientation();
    
    // On se base sur AFF_SIZE pour dimensionner les yeux (AFF_SIZE étant une constante statique)
    double eyeRadius = bestiole->getAFF_SIZE() / 4.0;
    double offset = bestiole->getAFF_SIZE();  // distance entre le centre et la position des yeux
    double angleOffset = M_PI / 6.0;       // 30° d'écart pour chaque œil

    // Calcul des positions pour l'œil gauche et droit
    int xg = x + static_cast<int>(cos(orientation + angleOffset) * offset);
    int yg = y - static_cast<int>(sin(orientation + angleOffset) * offset);
    int xd = x + static_cast<int>(cos(orientation - angleOffset) * offset);
    int yd = y - static_cast<int>(sin(orientation - angleOffset) * offset);

    // Couleur rouge pour les yeux
    unsigned char rouge[3] = {255, 0, 0};
    support.draw_circle(xg, yg, eyeRadius, rouge, 1.0);
    support.draw_circle(xd, yd, eyeRadius, rouge, 1.0);
}
