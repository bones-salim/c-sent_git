#ifndef PEUREUSE_H
#define PEUREUSE_H

#include <cmath>
#include "Bestiole.h"
#include "Comportement.h"

class Bestiole;

class Peureuse : public Comportement
{
private:
    double regvit;
    double speedmultiplier;
    double maxpeed;
    Bestiole *bestiole;
    int seuilPeur;

    void run();

public:
    Peureuse(Bestiole *bestiole);
    Peureuse(const Peureuse& other);
    
    std::string getNom() override { return "Peureuse"; }
    std::unique_ptr<Comportement> clone() override;
    
    ~Peureuse() = default;
    void behave(Milieu& milieu, std::vector<Bestiole>& ListeBestiole) override;
};

#endif  // PEUREUSE_H

