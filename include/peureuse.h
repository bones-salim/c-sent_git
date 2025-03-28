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
        void run();
       
    
    protected:
    public:
        Peureuse(Bestiole *bestiole);
        virtual void behave(std::vector<std::unique_ptr<Bestiole>>& listeBestioles);
        virtual std::string getNom() const override  ;
        std::unique_ptr<Comportement> clone(Bestiole* bestiole) const override;

        int countNeighbors(std::vector<std::unique_ptr<Bestiole>>& listeBestioles);
        ~Peureuse() = default;
        
}
;
#endif

