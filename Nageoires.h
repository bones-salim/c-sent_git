#ifndef NAGEOIRES_H
#define NAGEOIRES_H

#include "AccessoryDecorator.h"

/**
 * @brief Décorateur pour ajouter des nageoires à une bestiole.
 * Augmente la vitesse par un coefficient multiplicateur.
 */
class Nageoires : public AccessoireDecorator {
private:
    double coeffMultiplicateur; // ν
public:
    Nageoires(Bestiole* b, double coeffMultiplicateur);
    virtual ~Nageoires();

    virtual void applyEffect() override;
    virtual void drawEffect(UImg &support) override;
    
    virtual Nageoires* clone(Bestiole* b) const override;
};

#endif // NAGEOIRES_H
