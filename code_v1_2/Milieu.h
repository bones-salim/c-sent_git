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
    double tauxNaissance;

public:
    Milieu(int _width, int _height);
    ~Milieu();

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void step();
    void ajouterBestiole_clonage(std::unique_ptr<Bestiole> bestiole);
    int nbVoisins(const Bestiole& b);
    void ajouterPopulationSpontanee();
    void afficher();
    void ajouterBestiole(Bestiole *b);
    void supprimerBestiole(Bestiole *b);
};

#endif // MILIEU_H
