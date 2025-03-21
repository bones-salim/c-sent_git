#include "Peureuse.h"
#include <vector>
#include "Milieu.h"
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif  
Peureuse::Peureuse(Bestiole *bestiole) : bestiole(bestiole)
{   regvit= bestiole->getVitesse();
    speedmultiplier=1.5;
    seuilPeur=5;
    maxpeed=regvit*speedmultiplier;

}
void Peureuse::behave()
{
    //bestiole->setCouleur( 0,255, 0);   // x color for Peureuse
    // Identify the nearest bestiole and find it
    // idea: we count the number of neighbours and if it's more than a certain number we run
    int nbNeighbors= countNeighbors();
    
    if ( nbNeighbors > seuilPeur)
    {
        run();
    }
    else 
    {
        bestiole->setVitesse(regvit);
    }
    
  
}
int Peureuse::countNeighbors()
    {
        int nbNeighbors = 0;
        for (std::vector<Bestiole>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it)

            if (bestiole->jeTeVois(*it))
            {
                nbNeighbors++;
            }
        return nbNeighbors;
        }
        
void Peureuse::run()
{   
    double direction = bestiole->getOrientation();
    bestiole->setOrientation(direction+M_PI);
    bestiole->setVitesse(maxpeed);


}

Comportement *Peureuse::clone(Bestiole *bestiole) const
{
    return new Peureuse(bestiole);
}