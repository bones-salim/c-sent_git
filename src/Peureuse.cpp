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

// Constructeur de copie
Peureuse::Peureuse(const Peureuse& other)
    : bestiole(other.bestiole), regvit(other.regvit), speedmultiplier(other.speedmultiplier), 
      maxpeed(other.maxpeed), seuilPeur(other.seuilPeur) {}

void Peureuse::behave(Milieu& milieu, std::vector<Bestiole>& ListeBestiole)
{
    if (!bestiole) return;  // Vérification pour éviter un crash

    int nbNeighbors = milieu.nbVoisins(*bestiole);

    if (nbNeighbors > seuilPeur)
    {
        run();
    }
    else 
    {
        bestiole->setVitesse(regvit);
    }
}

void Peureuse::run()
{   
    if (!bestiole) return;  // Vérification pour éviter un crash

    double direction = bestiole->getOrientation();
    bestiole->setOrientation(direction + M_PI);
    bestiole->setVitesse(maxpeed);
}

// Correction de clone()
std::unique_ptr<Comportement> Peureuse::clone() {
    return std::make_unique<Peureuse>(*this);  
}


