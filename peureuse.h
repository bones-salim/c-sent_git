#ifndef PEUREUSE_H
#define PEUREUSE_H
#include <cmath>
#include "Bestiole.h"
#include "Comportement.h"
class Bestiole;

class Peureuse : public Comportement //heritage
{

    private:
        double regvit= bestiole->getVitesse();
        double speedmultiplier;
        double maxpeed;
        Bestiole *bestiole;
        int seuilPeur;
        bool panic();
        int countNeighbors();
        void run();
       
    
    protected:
    public:
        Peureuse(Bestiole *bestiole);
        void behave(std::vector<Bestiole>& ListeBestioles) override;
        virtual Comportement* clone(Bestiole *bestiole) const override;
        ~Peureuse() = default;

}
;
#endif
