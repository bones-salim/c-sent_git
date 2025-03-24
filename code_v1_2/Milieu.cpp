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


const T Milieu::white[] = { (T)255, (T)255, (T)255 };

Milieu::Milieu(int _width, int _height) : UImg(_width, _height, 1, 3), width(_width), height(_height),
    gen(std::random_device()()), dis(0.0, 1.0)
{
    bestioleConfig["Peureuse"] = 0.2;
    bestioleConfig["Grégaire"] = 0.3;
    bestioleConfig["Prévoyante"] = 0.3;
    bestioleConfig["Multiple"] = 0.1;
    bestioleConfig["Kamikaze"] = 0.1;
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
        
        Bestiole* newBestiole = Createur_Bestiole::creerBestiole(comp);
   
        if (newBestiole) {
            listeBestioles.push_back(std::unique_ptr<Bestiole>(newBestiole));
        } else {
            std::cout << "Erreur : Impossible de créer une bestiole !" << std::endl;
        }
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



