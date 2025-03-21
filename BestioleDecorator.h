
#ifndef BESTIOLEDECORATOR_H
#define BESTIOLEDECORATOR_H

#include "Bestiole.h"

// Classe de base abstraite pour les décorateurs de bestioles
class BestioleDecorator : public Bestiole {
protected:
    Bestiole* bestiole;

public:
    BestioleDecorator(Bestiole* b);
    virtual void detecter() = 0;
    virtual void ApplyEffect() = 0;
    virtual void DrawEffect(UImg& support) = 0;
    virtual Bestiole* clone() = 0;
    virtual ~BestioleDecorator() = default;
};

#endif // BESTIOLEDECORATOR_H
