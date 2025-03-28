#include "Milieu.h"
#include "Createur_Bestiole.h"
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
#include "CImg.h"
using namespace cimg_library;

const T Milieu::white[] = { (T)255, (T)255, (T)255 };

Milieu::Milieu(int _width, int _height) : UImg(_width, _height, 1, 3), width(_width), height(_height),
    gen(std::random_device()()), dis(0.0, 1.0) ,taux_Naissance(0.1)
{
    bestioleConfig["Peureuse"] = 0.2;
    bestioleConfig["Grégaire"] = 0.3;
    bestioleConfig["Prévoyante"] = 0.3;
    bestioleConfig["Multiple"] = 0;
    bestioleConfig["Kamikaze"] = 0.2;
    std::cout << "const Milieu" << std::endl;
    std::cout << "const Milieu: " << _width << " x " << _height << std::endl;

}

Milieu::~Milieu()
{
    std::cout << "dest Milieu" << std::endl;
}

void Milieu::comporter(){
    for (auto& bestiole : listeBestioles) {
        if (bestiole->getComportement() != nullptr) {
            std::cout << "I am behaving" << std::endl;
            bestiole->getComportement()->behave(listeBestioles);
        } else {
            bestiole->setCouleur(0, 0, 0);
        }
    } 
}

void Milieu::step()
{
    // Remplir l'image de blanc et dessiner le carré de test...
    this->fill(255);
    int cx = width / 2;
    int cy = height / 2;
    for (int x = cx - 20; x < cx + 20; ++x) {
        for (int y = cy - 20; y < cy + 20; ++y) {
            (*this)(x, y, 0, 0) = 255; // Rouge
            (*this)(x, y, 0, 1) = 0;   // Vert
            (*this)(x, y, 0, 2) = 0;   // Bleu
        }
    }

    // Phase 1 : mettre à jour et dessiner toutes les bestioles
    for (auto& bestiole : listeBestioles) {
        bestiole->action(*this);
        bestiole->draw(*this);
    }

    // Phase 2 : traiter les collisions, suppression et comportements
    checkForCollisions();
    removeDead();
    comporter();
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
        // Calculer les probabilités de comportements à partir de la population actuelle
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

        // Choisir le comportement à affecter en fonction des probabilités et de la configuration attendue
        auto choisirComportement = [](const std::map<std::string, double>& probabilites,
                                        const std::map<std::string, double>& bestioleConfig) -> std::string {
            for (const auto& [nom, prob] : probabilites) {
                auto it = bestioleConfig.find(nom);
                if (it != bestioleConfig.end() && prob < it->second) {
                    return nom;
                }
            }
            return std::string();
        };

        // Créer le comportement en fonction du nom choisi
        auto creerComportement = [](const std::string& nom, Bestiole* b) -> std::unique_ptr<Comportement> {
            if (nom == "Peureuse") return std::make_unique<Peureuse>(b);
            if (nom == "Grégaire") return std::make_unique<Gregaire>(0.5, b);
            if (nom == "Prévoyante") return std::make_unique<Prevoyante>(0.1,b);
            // if (nom == "Multiple") return std::make_unique<PersonnalitesMultiples>(b);
            if (nom == "Kamikaze") return std::make_unique<Kamikaze>(b);
            return nullptr;
        };

        // Calculer les probabilités sur la population actuelle
        std::map<std::string, double> probabilites = calculerProbabilites(listeBestioles);
        // Choisir le comportement à affecter
        std::string comportementChoisi = choisirComportement(probabilites, bestioleConfig);

        // Créer une nouvelle bestiole via la factory
        Createur_Bestiole createur;
        Bestiole* newBestiole = createur.creerBestiole(nullptr);
        if (newBestiole) {
            // Créer et affecter le comportement
            std::unique_ptr<Comportement> comp = creerComportement(comportementChoisi, newBestiole);
            newBestiole->setComportement(std::move(comp));
            // Attribuer capteurs et accessoires
            newBestiole->initCoords(width, height);
            attribuerCapteurs(newBestiole);
            attribuerAccessoires(newBestiole);
            // Ajouter la bestiole dans la liste (une seule fois)
            listeBestioles.push_back(std::unique_ptr<Bestiole>(newBestiole));
        } else {
            std::cout << "Erreur : Impossible de créer une bestiole !" << std::endl;
        }
    }
}

void Milieu::supprimerBestiole(Bestiole* b) {
   if (b->get_age() >= b->getDureeVie()) {
      listeBestioles.erase(std::remove_if(listeBestioles.begin(), listeBestioles.end(),
      [b](const std::unique_ptr<Bestiole>& bestiolePtr) {
          return bestiolePtr.get() == b;
      }), listeBestioles.end());
   }
}

std::vector<int> Milieu::getdead() {
    std::vector<int> deadIndexes;
    for (size_t i = 0; i < listeBestioles.size(); ++i) {
        if (listeBestioles[i]->getMort()) { 
            deadIndexes.push_back(static_cast<int>(i));
        }
    }
    return deadIndexes;
}

 
void Milieu::removeDead() {
    std::vector<int> deadIndexes = getdead();

    // Trier les indices décroissants pour éviter des invalidations d'indices
    std::sort(deadIndexes.begin(), deadIndexes.end(), std::greater<int>());

    for (int indexToDelete : deadIndexes) {
        if (indexToDelete >= 0 && static_cast<size_t>(indexToDelete) < listeBestioles.size()) {
            listeBestioles.erase(listeBestioles.begin() + indexToDelete);
        }
    }
}



void Milieu::checkForCollisions() {
    int collisionRange = 7;

    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        for (auto it2 = listeBestioles.begin(); it2 != listeBestioles.end(); ++it2) {
            if (it != it2) {
                Bestiole* b1 = it->get();
                Bestiole* b2 = it2->get();

                if (std::abs(b1->getX() - b2->getX()) <= collisionRange &&
                    std::abs(b1->getY() - b2->getY()) <= collisionRange) {
                    b1->collide();
                    break; // Arrête dès que la collision est gérée pour b1
                }
            }
        }
    }
}

void Milieu::attribuerCapteurs(Bestiole* b) {
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

    //std::uniform_real_distribution<> distribDelta(20.0, 200.0); // distance entre 10 et 100
   // std::uniform_real_distribution<> distribCapacite(0.0, 1.1); // capacité entre 0 et 1

    double delta_o = distribDelta(gen);
    double capaciteDetection_o = distribCapacite(gen);

    if (nbCapteurs == 1) {
        // Choisir aléatoirement entre Yeux ou Oreilles
        std::uniform_int_distribution<int> capteurDis(0, 1);
        if (capteurDis(gen) == 0) {
            b->listedescapteurs.push_back(std::make_unique<Yeux>(b, alpha, delta_y, capaciteDetection_y));
        } else {
            b->listedescapteurs.push_back(std::make_unique<Oreilles>(b, delta_o, capaciteDetection_o));
        }
    } else if (nbCapteurs == 2) {
        b->listedescapteurs.push_back(std::make_unique<Yeux>(b, alpha, delta_y, capaciteDetection_y));
        b->listedescapteurs.push_back(std::make_unique<Oreilles>(b, delta_o, capaciteDetection_o));
    }
}


void Milieu::attribuerAccessoires(Bestiole* b) {
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
            b->listedesaccessoires.push_back(std::make_unique<Nageoires>(b, distribVitesse(gen)));
        } else if (typeAccessoire == 1) {
            b->listedesaccessoires.push_back(std::make_unique<Carapace>(b, distribProbabilite(gen), distribVitesse(gen)));
        } else {
            b->listedesaccessoires.push_back(std::make_unique<Camouflage>(b,distribCamouflage(gen)));
        }
    }
}

    


    




