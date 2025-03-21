#ifndef MILIEU_H
#define MILIEU_H

#include "UImg.h"
#include "Bestiole.h"
#include "Createur_Bestiole.h"
#include <iostream>
#include <vector>
#include <map>

class Milieu : public UImg
{
private:
    static const T white[];
    
    int width;
    int height;
    std::vector<Bestiole> listeBestioles;
    std::map<Comportement*, double> bestioleConfig; // Supposons que 'prob' = double
    bool event_Naissance;
    bool event_Mort;
    double taux_naissance;  // Les tirets sont interdits dans les noms de variables

public:
    Milieu(int _width, int _height);
    ~Milieu();

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void step();
    void addMember(const Bestiole& b);
    int nbVoisins(const Bestiole& b);
    void removeMember();
};

#endif

