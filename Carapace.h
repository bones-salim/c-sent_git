#ifndef _CARAPACE_H
#define _CARAPACE_H

// Accessoire Carapace
class Carapace : public AccessoryDecorator {
    private:
        double eta;
        double omega;
    
    public:
        Carapace(Bestiole* b, double e, double o);
        void ApplyEffect() override;
        void DrawEffect(UImg& support) override;
        Bestiole* clone() override;
    };

#endif