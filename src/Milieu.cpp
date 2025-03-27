#include "Milieu.h"
#include "Createur_Bestiole.h"
#include "Bestiole.cpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <typeindex>
#include <algorithm>
#include <random>
#include <Oreilles.h>
#include <Yeux.h>
#include <Nageoires.h>
#include <Carapace.h>
#include <Camouflage.h>


const T Milieu::white[] = { (T)255, (T)255, (T)255 };

Milieu::Milieu(int _width, int _height) : UImg(_width, _height, 1, 3), width(_width), height(_height),
    gen(std::random_device()()), dis(0.0, 1.0)
{
    bestioleConfig["Peureuse"] = 0.2;
    bestioleConfig["Grégaire"] = 0.3;
    bestioleConfig["Prévoyante"] = 0.3;
    bestioleConfig["Multiple"] = 0;
    bestioleConfig["Kamikaze"] = 0.2;
    std::cout << "const Milieu" << std::endl;
}

Milieu::~Milieu()
{
    std::cout << "dest Milieu" << std::endl;
}

void Milieu::step()
{
    cimg_forXY(*this, x, y) fillC(x, y, 0, white[0], white[1], white[2]);
    for (auto& bestiole : listeBestioles) {
      bestiole->action(*this);
      bestiole->draw(*this);
  }
}

int Milieu::nbVoisins(const Bestiole& b)
{
    int nb = 0;
    for (const auto& bestiole : listeBestioles)
    {
        if (!(b == *bestiole) && b.jeTeVois(*bestiole))
            ++nb;
    }
    return nb;
}

void Milieu::ajouterBestiole_clonage(Bestiole* b) {
   listeBestioles.push_back(std::unique_ptr<Bestiole>(b->clone()));
}

void Milieu::naissance(){
    double p = dis(gen);
    if (p < taux_Naissance) {
        auto calculerProbabilites = [](const std::vector<std::unique_ptr<Bestiole>>& listeBestioles) {
            std::map<std::string, int> compteur;
            int total = listeBestioles.size();
        
            for (const auto& bestiole : listeBestioles) {
                if (bestiole->getComportement()) {
                    compteur[bestiole->getComportement()->getNom()]++;
                }
            }
        
            std::map<std::string, double> probabilites;
            for (const auto& [nom, count] : compteur) {
                probabilites[nom] = static_cast<double>(count) / total;
            }
        
            return probabilites;
        };
        
        auto choisirComportement = [](const std::map<std::string, double>& probabilites, const std::map<std::string, double>& bestioleConfig) {
            for (const auto& [nom, prob] : probabilites) {
                auto it = bestioleConfig.find(nom);
                if (it != bestioleConfig.end() && prob < it->second) {
                    return nom;
                }
            }
            return std::string();
        };

        auto creerComportement = [](const std::string& nom) -> std::unique_ptr<Comportement> {
            if (nom == "Peureuse") return std::make_unique<Peureuse>();
            if (nom == "Grégaire") return std::make_unique<Gregaire>();
            if (nom == "Prévoyante") return std::make_unique<Prevoyante>();
            if (nom == "Multiple") return std::make_unique<PersonnalitesMultiples>();
            if (nom == "Kamikaze") return std::make_unique<Kamikaze>();
            return nullptr;
        };

        std::map<std::string, double> probabilites = calculerProbabilites(listeBestioles);
    
        std::string comportementChoisi = choisirComportement(probabilites, bestioleConfig);
    
        std::unique_ptr<Comportement> comp = creerComportement(comportementChoisi);
        
        Bestiole* newBestiole = Createur_Bestiole::creerBestiole(std::move(comp));
   
        if (newBestiole) {
            listeBestioles.push_back(std::unique_ptr<Bestiole>(newBestiole));
        } else {
            std::cout << "Erreur : Impossible de créer une bestiole !" << std::endl;
        }
        attribuerCapteurs(newBestiole);
        attribuerAccessoires(newBestiole);
    }
}

void Milieu::supprimerBestiole(Bestiole* b) {
   if (b->get_age() >= b->get_dureeVie()) {
      listeBestioles.erase(std::remove_if(listeBestioles.begin(), listeBestioles.end(),
      [b](const std::unique_ptr<Bestiole>& bestiolePtr) {
          return bestiolePtr.get() == b;
      }), listeBestioles.end());
   }
}
void Milieu::checkForCollisions()
{
    int collisionRange = 3;
    for (auto it = listeBestioles.begin(); it != listeBestioles.end();)
    {  
        
        for (auto it2 = listeBestioles.begin(); it2 != listeBestioles.end();)
       {
          if (std::abs((*it)->getX() - (*it2)->getX()) <= collisionRange)
          {
             if (std::abs((*it)->getY() - (*it2)->getY()) <= collisionRange)
             {
                if (*it != *it2)
                {
                   (*it)->collide();
                   break;
                }
             }
          }
          ++it2;
       }
       ++it;
    }
}
void attribuerCapteurs(Bestiole* b) {
    // Générer un nombre aléatoire de capteurs (par exemple entre 1 et 3)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 2); // Changez 3 si vous voulez un nombre max différent de 3
    int nbCapteurs = dis(gen);

    std::uniform_real_distribution<> distribAlpha(0.0, 3.14); // alpha entre 0 et pi
    std::uniform_real_distribution<> distribDelta(10.0, 100.0); // distance entre 10 et 100
    std::uniform_real_distribution<> distribCapacite(0.0, 1.0); // capacité entre 0 et 1

    double alpha = distribAlpha(gen);
    double delta_y = distribDelta(gen);
    double capaciteDetection_y = distribCapacite(gen);

    std::uniform_real_distribution<> distribDelta(10.0, 100.0); // distance entre 10 et 100
    std::uniform_real_distribution<> distribCapacite(0.0, 1.0); // capacité entre 0 et 1

    double delta_o = distribDelta(gen);
    double capaciteDetection_o = distribCapacite(gen);

    if (nbCapteurs == 1) {
        // Choisir aléatoirement entre Yeux ou Oreilles
        std::uniform_int_distribution<int> capteurDis(0, 1);
        if (capteurDis(gen) == 0) {
            b->listedescapteurs.push_back(std::make_unique<Yeux>(alpha, delta_y, capaciteDetection_y));
        } else {
            b->listedescapteurs.push_back(std::make_unique<Oreilles>(delta_o, capaciteDetection_o));
        }
    } else if (nbCapteurs == 2) {
        b->listedescapteurs.push_back(std::make_unique<Yeux>(alpha, delta_y, capaciteDetection_y));
        b->listedescapteurs.push_back(std::make_unique<Oreilles>(delta_o, capaciteDetection_o));
    }
}


void attribuerAccessoires(Bestiole* b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 2);  // Nombre d'accessoires entre 0 et 2

    // Distribution pour les attributs des accessoires
    std::uniform_real_distribution<> distribVitesse(1.0, 3.0);  // Coefficient de vitesse
    std::uniform_real_distribution<> distribProbabilite(0.5, 1.0);  // Réduction probabilité de mort
    std::uniform_real_distribution<> distribCamouflage(0.0, 1.0);  // Capacité de camouflage

    // Créer un tableau pour les types d'accessoires disponibles
    std::vector<int> accessoiresDisponibles = {0, 1, 2};  // 0: Nageoires, 1: Carapace, 2: Camouflage
    std::shuffle(accessoiresDisponibles.begin(), accessoiresDisponibles.end(), gen);  // Mélanger les indices

    int nbAccessoires = dis(gen);  // Nombre aléatoire d'accessoires à attribuer

    for (int i = 0; i < nbAccessoires; ++i) {
        int typeAccessoire = accessoiresDisponibles[i];  // Tirer un accessoire du tableau mélangé

        if (typeAccessoire == 0) {
            b->listedesaccessoires.push_back(std::make_unique<Nageoires>(distribVitesse(gen)));
        } else if (typeAccessoire == 1) {
            b->listedesaccessoires.push_back(std::make_unique<Carapace>(distribProbabilite(gen), distribVitesse(gen)));
        } else {
            b->listedesaccessoires.push_back(std::make_unique<Camouflage>(distribCamouflage(gen)));
        }
    }
}

    


    




