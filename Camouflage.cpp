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
    support.drawHalo(bestiole->x, bestiole->y, 25, efficaciteCamouflage);
}

void Camouflage::detecter()
{
    // Non applicable
}

bool Camouflage::jeTeDetecte(const Bestiole &autre)
{
    return false;
}

Camouflage* Camouflage::clone(Bestiole* b) const
{
    return new Camouflage(b, efficaciteCamouflage);
}

double Camouflage::getCamouflage() const
{
    return efficaciteCamouflage;
}
