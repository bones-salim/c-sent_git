// Clonable.h
#ifndef CLONABLE_H
#define CLONABLE_H

class Clonable {
public:
    virtual ~Clonable() {}
    virtual Clonable* clone() const =0;
};

#endif