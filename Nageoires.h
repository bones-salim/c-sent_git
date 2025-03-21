#ifndef _NAGEOIRES_H_
#define _NAGEOIRES_H_

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

#endif