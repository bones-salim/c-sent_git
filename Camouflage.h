#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "AccessoireDecorator.h"

/**
 * @brief Décorateur pour ajouter un camouflage à une bestiole.
 * Rend la bestiole plus difficile à détecter en modifiant sa capacité de camouflage.
 */
class Camouflage : public AccessoireDecorator {
private:
    double efficaciteCamouflage; // ψ
public:
    Camouflage(Bestiole* b, double efficaciteCamouflage);
    virtual ~Camouflage();

    virtual void applyEffect() override;
    virtual void drawEffect(UImg &support) override;
   
    virtual Camouflage* clone(Bestiole* b) const override;

    double getCamouflage() const ;
};

#endif // CAMOUFLAGE_H
