#ifndef MILIEU_H
#define MILIEU_H

#include "UImg.h"
#include "Bestiole.h"
#include "Createur_Bestiole.h"
#include <iostream>
#include <vector>
#include <map>
#include <memory>

class Milieu : public UImg
{
private:
    static const T white[];
    int width;
    int height;
    std::vector<std::unique_ptr<Bestiole>> listeBestioles;
    std::map<Comportement*, double> bestioleConfig;
    bool event_Naissance;
    bool event_Mort;
    double taux_Naissance;

public:
    Milieu(int _width, int _height);
    ~Milieu();

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void step();
    int nbVoisins(const Bestiole& b) ;
    void naissance();
    void ajouterPopulationSpontanee();
    void afficher();
    void ajouterBestiole_factory(Bestiole *b);
    void ajouterBestiole_clonage(Bestiole *b);
    void supprimerBestiole(Bestiole *b);
};

#endif // MILIEU_H
