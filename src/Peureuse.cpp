#include "peureuse.h"
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
void Peureuse::behave(std::vector<Bestiole>& ListeBestioles)
{
    //bestiole->setCouleur( 0,255, 0);   // x color for Peureuse
    // Identify the nearest bestiole and find it
    // idea: we count the number of neighbours and if it's more than a certain number we run
    int nbNeighbors= countNeighbors(ListeBestioles);
    
    if ( nbNeighbors > seuilPeur)
    {
        run();
    }
    else 
    {
        bestiole->setVitesse(regvit);
    }
    
  
}
int Peureuse::countNeighbors(std::vector<Bestiole>& ListeBestioles)
    {
        int nbNeighbors = 0;
        for (std::vector<Bestiole>::iterator it = ListeBestioles.begin(); it != ListeBestioles.end(); ++it)

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
std::string getNom()   { return "Peureuse"; }
std::unique_ptr<Comportement> clone()  {
    return std::make_unique<Peureuse>(); // Copie
}

