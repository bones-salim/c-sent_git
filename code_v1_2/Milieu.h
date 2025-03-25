#ifndef MILIEU_H
#define MILIEU_H

#include "UImg.h"
#include "Bestiole.h"
#include "Createur_Bestiole.h"
#include "Comportement.h"
#include "Gregaire.h"
#include "peureuse.h"
#include  "Prevoyante.h"
#include "kamikaze.h"
#include "PersonnalitesMultiples.h"

#include <iostream>
#include <vector>
#include <map>
#include <memory>
<<<<<<< HEAD
#include <random>
=======

>>>>>>> 190583cf5849345e9f7cf7ae76a4d2235bc9af27
class Milieu : public UImg
{
private:
    static const T white[];
    int width;
    int height;
    std::vector<std::unique_ptr<Bestiole>> listeBestioles;
<<<<<<< HEAD
    std::map<std::string, double> bestioleConfig;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;
=======
    std::map<Comportement*, double> bestioleConfig;
>>>>>>> 190583cf5849345e9f7cf7ae76a4d2235bc9af27
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
