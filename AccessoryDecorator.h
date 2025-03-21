#ifndef _ACCESSORYDECORATOR_H_
#define _ACCESSORYDECORATOR_H_

#include "BestioleDecorator.h"

// Classe de base pour les décorateurs d'accessoires
class AccessoryDecorator : public BestioleDecorator {
public:
    AccessoryDecorator(Bestiole* b);
    virtual void ApplyEffect() = 0;
    virtual void DrawEffect(UImg& support) = 0;
    virtual Bestiole* clone() = 0;
};


// Accessoire Nageoires
class Nageoires : public AccessoryDecorator {
private:
    double speedMult;

public:
    Nageoires(Bestiole* b, double speed);
    void ApplyEffect() override;
    void DrawEffect(UImg& support) override;
    Bestiole* clone() override;
};

// Accessoire Camouflage
class Camouflage : public AccessoryDecorator {
private:
    double psi;

public:
    Camouflage(Bestiole* b, double p);
    void ApplyEffect() override;
    void DrawEffect(UImg& support) override;
    Bestiole* clone() override;
};

#endif // ACCESSORYDECORATOR_H
