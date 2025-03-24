#include "Nageoires.h"
#include "Bestiole.h"
#include <cmath>

Nageoires::Nageoires(Bestiole* b, double coeffMultiplicateur)
    : AccessoireDecorator(b), coeffMultiplicateur(coeffMultiplicateur)
{
    applyEffect();
}

Nageoires::~Nageoires() {
}

void Nageoires::applyEffect()
{
    bestiole->setVitesse( bestiole->getVitesse() * coeffMultiplicateur );
}

void Nageoires::drawEffect(UImg &support)
{
    support.drawText(bestiole->x, bestiole->y - 10, "Nageoires", bestiole->couleur);
}

void Nageoires::detecter()
{
    // Non applicable
}

bool Nageoires::jeTeDetecte(const Bestiole &autre)
{
    return false;
}

Nageoires* Nageoires::clone(Bestiole* b) const
{
    return new Nageoires(b, coeffMultiplicateur);
}
