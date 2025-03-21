#include "Prevoyante.h"
#include "Bestiole.h"
#include <cmath>

Prevoyante::Prevoyante(double margeEsquive) : margeEsquive(margeEsquive) {}

void Prevoyante::appliquer(Bestiole& b, const std::vector<Bestiole>& environnement) {
    for (const auto& bestiole : environnement) {
        if (&bestiole != &b) {  // Ne pas se compter soi-même
            double distance = std::abs(bestiole.direction - b.direction);
            if (distance < margeEsquive) {
                b.direction += M_PI / 2;  // Changer de direction pour éviter la collision
            }
        }
    }
}