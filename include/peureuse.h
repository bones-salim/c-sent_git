#ifndef PEUREUSE_H
#define PEUREUSE_H
#include <cmath>
#include "Bestiole.h"
#include "Comportement.h"
class Bestiole;

class Peureuse : public Comportement //heritage
{

    private:
        double regvit;
        double speedmultiplier;
        double maxpeed;
        Bestiole *bestiole;
        int seuilPeur;
        bool panic();
        int countNeighbors(std::vector<Bestiole>& ListeBestioles);
        void run();
       
    
    protected:
    public:
        Peureuse(Bestiole *bestiole);
        void behave(std::vector<Bestiole>& ListeBestioles);
        virtual std::string getNom() override  = 0 ;
        virtual std::unique_ptr<Comportement> clone() override ;
        ~Peureuse() = default;
        
}
;
#endif
