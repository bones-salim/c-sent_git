#include "Camouflage.h"
#include "Bestiole.h"
#include <cmath>

Camouflage::Camouflage(Bestiole* b, double efficaciteCamouflage)
    : AccessoireDecorator(b), efficaciteCamouflage(efficaciteCamouflage=0)
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
    unsigned char vert[3] = {0, 255, 0};
    support.draw_circle(bestiole->getX(), bestiole->getY(), bestiole->getAFF_SIZE() + 5, vert, 0.2);
}




Camouflage* Camouflage::clone(Bestiole* b) const
{
    return new Camouflage(b, efficaciteCamouflage);
}


