#ifndef PEUREUSE_H
#define PEUREUSE_H
#include <cmath>
#include "Bestiole.h"
#include "Comportement.h"
class Bestiole;

class Peureuse : public Comportement //heritage
{

    private:
        Bestiole *bestiole;
        void chase(Bestiole *target);
        int mobsize;
        bool panic();
        


    protected:
    public:
        Peureuse(Bestiole *bestiole);
        void behave() override;
        virtual Comportement* clone(Bestiole *bestiole) const override;
        //reference vs pointers
        Bestiole* countNeighbors();
        void run();
        ~Peureuse() = default;

}
;
#endif
