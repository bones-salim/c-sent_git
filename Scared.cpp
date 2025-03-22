#include "Scared.h"
#include <vector>
#include "Milieu.h"
#include <cmath>

Scared::Scared(Bestiole *bestiole) : bestiole(bestiole)
{   regvit= bestiole->getVitesse();
    speedmultiplier=1.5;
    seuilPeur=5;
    maxpeed=regvit*speedmultiplier;
    internalclock=0;
}
void Scared::behave(vector<Bestiole> &listeBestioles)
{
    if (countNeighbors(listeBestioles) && internalclock==0)
    {
        run();
        internalclock=5;
    }
    else if (internalclock>0)
    {
        internalclock--;
    }
    else
    {
        bestiole->setVitesse(regvit);
    }
  
}
int Scared::countNeighbors(vector<Bestiole> &listeBestioles)
    {
        int nbNeighbors = 0;
        for (std::vector<Bestiole>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it)

            if (bestiole->jeTeVois(*it))
            {
                nbNeighbors++;
            }
        return nbNeighbors;
        }
        
void Scared::run()
{   
    double direction = bestiole->getOrientation();
    bestiole->setOrientation(fmod((direction + 3.1415926), (2 * 3.1415926)));
    bestiole->setVitesse(bestiole->getVitesse()*speedmultiplier);


}

Comportement *Scared::clone(Bestiole *bestiole) const
{
    return new Scared(bestiole);
}