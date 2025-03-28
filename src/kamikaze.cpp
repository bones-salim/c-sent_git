#include "kamikaze.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Kamikaze::Kamikaze(Bestiole *bestiole) : bestiole(bestiole) {}

void Kamikaze::behave(std::vector<std::unique_ptr<Bestiole>>& listeBestioles)
{   
    bestiole->setCouleur(255, 0, 0);  // Couleur rouge pour Kamikaze

    Bestiole *target = getTarget(listeBestioles);
    if (target != nullptr) {
        chase(target);
    }
}

Bestiole* Kamikaze::getTarget(std::vector<std::unique_ptr<Bestiole>>& listeBestioles)
{
    double minDistance = std::numeric_limits<double>::max();
    Bestiole* target = nullptr;

    for (const auto& it : listeBestioles) {
        if (it.get() != bestiole && bestiole->jeTeVois(*it)) {
            double distance = calculateDistance(*bestiole, *it);
            if (distance < minDistance) {
                minDistance = distance;
                target = it.get();
            }
        }
    }
    return target;
}

void Kamikaze::chase(Bestiole *target)
{
    double dx = target->getX() - bestiole->getX();
    double dy = target->getY() - bestiole->getY();
    double norm = sqrt(dx * dx + dy * dy);

    if (norm > 0) {
        dx /= norm;
        dy /= norm;
    }

    double direction = -std::atan2(dy, dx); // Coordonnées inversées
    bestiole->setOrientation(direction);
}

double Kamikaze::calculateDistance(const Bestiole &b1, const Bestiole &b2)
{
    double dx = b1.getX() - b2.getX();
    double dy = b1.getY() - b2.getY();
    return sqrt(dx * dx + dy * dy);
}

std::string Kamikaze::getNom() const {
    return "Kamikaze";
}

std::unique_ptr<Comportement> Kamikaze::clone(Bestiole *bestiole) const {
    return std::make_unique<Kamikaze>(bestiole);
}
