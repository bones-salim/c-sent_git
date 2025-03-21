#ifndef INTERFACE_BESTIOLE_H
#define INTERFACE_BESTIOLE_H

class Interface_Bestiole {
public:
    virtual void draw(int support) = 0;
    virtual void preUpdate(int minX, int minY) = 0;
    virtual void update(int minX, int minY) = 0;
    virtual void collide() = 0;
    virtual bool see(int entity) = 0;
};

#endif