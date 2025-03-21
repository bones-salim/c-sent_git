#ifndef _SENSORDECORATOR_H_
#define _SENSORDECORATOR_H_

#include "BestioleDecorator.h"

// Définition de la classe sensorielle
class SensorDecorator : public BestioleDecorator {
protected:
    double capacity;

public:
    SensorDecorator(Bestiole* b, double c);
    virtual void detecter() = 0;
    virtual void method2(int type1, int type2);
    virtual Bestiole* clone() override;
};

#endif // SENSORDECORATOR_H
 