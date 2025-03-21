#ifndef _CAMOUFLAGE_H_
#define _CAMOUFLAGE_H_

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

#endif