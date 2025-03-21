#ifndef YEUX_H
#define YEUX_H

#include "SensorDecorator.h"
// Détecteur pour les yeux
class Yeux : public SensorDecorator {
    private:
        double alpha;
        double delta;
    
    public:
        Yeux(Bestiole* b, double a, double d);
        void detecter() override;
        Bestiole* clone() override;
    };
#endif 