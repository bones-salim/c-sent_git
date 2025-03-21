#ifndef SCARED_H
#define SCARED_H
#include <cmath>
#include "Bestiole.h"
#include "Comportement.h"
class Bestiole;

class Scared : public Comportement //heritage
{

    private:
        double regvit= bestiole->getVitesse();
        double speedmultiplier;
        Bestiole *bestiole;
        int seuilPeur;
        bool panic();
        int countNeighbors();
        void run();
        int internalclock;
        double maxpeed;
    
    protected:
    public:
        Scared(Bestiole *bestiole);
        void behave() override;
        virtual Comportement* clone(Bestiole *bestiole) const override;
        ~Scared() = default;

}
;
#endif
