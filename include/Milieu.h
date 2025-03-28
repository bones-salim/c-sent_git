#ifndef MILIEU_H
#define MILIEU_H

#include "UImg.h"
#include "Bestiole.h"
#include "Comportement.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include  "Prevoyante.h"
#include "kamikaze.h"
//#include "PersonnalitesMultiples.h"

class Createur_Bestiole;  // Déclaration avancée

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <random>
class Milieu : public UImg  {
private:
    static const T white[];
    int width;
    int height;
    std::vector<std::unique_ptr<Bestiole>> listeBestioles;
    std::map<std::string, double> bestioleConfig;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;
    bool event_Naissance;
    bool event_Mort;
    double taux_Naissance;

public:
    Milieu(int _width, int _height);
    ~Milieu();

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    size_t getPopulationSize() const { return listeBestioles.size(); }
    void dessiner(UImg &support);
    void step();
    int nbVoisins(const Bestiole& b) ;
    void naissance();
    void ajouterPopulationSpontanee();
    void afficher();
    void ajouterBestiole_factory(Bestiole *b);
    void ajouterBestiole_clonage(Bestiole *b);
    void supprimerBestiole(Bestiole *b);
    void checkForCollisions();
    void attribuerCapteurs(Bestiole* b);
    void attribuerAccessoires(Bestiole* b);
    void comporter();
    std::vector<int> getdead();
    void removeDead();
    
};

#endif // MILIEU_H
