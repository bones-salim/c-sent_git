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

bool Yeux::jeTeDetecte(const Bestiole &cible) {
    if (!dansChampVision(cible))
        return false;
    return (capaciteDetection > cible.getCamouflage());
}

SensorDecorator* Yeux::clone(Bestiole* b) const {
    return new Yeux(b, alpha, delta, capaciteDetection);
}
