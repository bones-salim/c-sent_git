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
Nageoires* Nageoires::clone(Bestiole* b) const
{
    return new Nageoires(b, coeffMultiplicateur);
}
