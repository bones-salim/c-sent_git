#include "Camouflage.h"
#include "Bestiole.h"
#include <cmath>

Camouflage::Camouflage(Bestiole* b, double efficaciteCamouflage)
    : AccessoireDecorator(b), efficaciteCamouflage(efficaciteCamouflage)
{
    applyEffect();
}

Camouflage::~Camouflage() {
}

void Camouflage::applyEffect()
{
    // Le camouflage est passif : l'effet se manifeste dans la détection via getCamouflage()
}

void Camouflage::drawEffect(UImg &support)
{
    // Dessiner un halo indiquant le camouflage
    support.drawHalo(bestiole->getX(), bestiole->getY(), 25, efficaciteCamouflage);
}



Camouflage* Camouflage::clone(Bestiole* b) const
{
    return new Camouflage(b, efficaciteCamouflage);
}


