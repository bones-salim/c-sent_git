#ifndef INTERFACE_BESTIOLE_H
#define INTERFACE_BESTIOLE_H
#include "AccessoireDecorator.h"
#include "SensorDecorator.h"
class Interface_Bestiole {
private:
std::vector<std::unique_ptr<SensorDecorator>> listedescapteurs;
std::vector<std::unique_ptr<AccessoireDecorator>> listedescapteurs;
public:
    virtual void draw(UImg& support) = 0;
    virtual void preUpdate(int minX, int minY) = 0;
    virtual void update(int minX, int minY) = 0;
    virtual void collide() = 0;
    virtual bool see(int entity) = 0;
};

#endif