#include "Peureuse.h"
#include <vector>
#include "Milieu.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif  

Peureuse::Peureuse(Bestiole *bestiole) : bestiole(bestiole)
{   
    regvit = bestiole->getVitesse();
    speedmultiplier = 1.5;
    seuilPeur = 5;
    maxpeed = regvit * speedmultiplier;
}

void Peureuse::behave(std::vector<std::unique_ptr<Bestiole>>& listeBestioles)
{
    bestiole->setCouleur(0, 255, 0);   // Couleur verte pour Peureuse

    int nbNeighbors = countNeighbors(listeBestioles);
    
    if (nbNeighbors > seuilPeur)
    {
        run();
    }
    else 
    {
        bestiole->setVitesse(regvit);
    }
}

int Peureuse::countNeighbors(std::vector<std::unique_ptr<Bestiole>>& listeBestioles)
{
    int nbNeighbors = 0;
    for (auto& it : listeBestioles)
    {
        if (bestiole != it.get() && bestiole->jeTeVois(*it))
        {
            nbNeighbors++;
        }
    }
    return nbNeighbors;
}       

void Peureuse::run()
{   
    double direction = bestiole->getOrientation();
    bestiole->setOrientation(direction + M_PI);
    bestiole->setVitesse(maxpeed);
}

std::string  Peureuse::getNom() const 
{ 
    return "Peureuse"; 
}

std::unique_ptr<Comportement> Peureuse::clone(Bestiole* bestiole) const {
    return std::make_unique<Peureuse>(bestiole);
}


