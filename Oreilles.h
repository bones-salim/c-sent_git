#ifndef _OREILLES_H
#define _OREILLES_H
// Détecteur pour les oreilles
class Oreille : public SensorDecorator {
    private:
        double delta;
    
    public:
        Oreille(Bestiole* b, double d);
        void detecter() override;
        Bestiole* clone() override;
    };
    
#endif // SENSORDECORATOR_H
     