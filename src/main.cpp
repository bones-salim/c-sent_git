#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    const int N = 1000;  // Nombre total d'étapes de simulation
    // Création de l'écosystème avec une taille d'aquarium (largeur, hauteur) et éventuellement un pas de temps
    Aquarium ecosysteme(640, 480, 1000);
    
    // Initialisation : création d'une population de départ (par exemple, 50 bestioles)
    for (int i = 0; i < 50; ++i) {
        ecosysteme.getMilieu().naissance();
    }
    
    // Boucle de simulation
    for (int step = 0; step < N; ++step) {
        // Naissance : possibilité d'ajouter de nouvelles bestioles
        ecosysteme.getMilieu().naissance();
        // Mise à jour de l'état : déplacement, interactions, etc.
        ecosysteme.getMilieu().step();
        
        // (Optionnel) On peut prévoir ici un appel à une méthode de suppression des bestioles mortes,
        // par exemple : ecosysteme.getMilieu().supprimerMorts();
        
        // Affichage périodique de l'état de la population
        if (step % 100 == 0) {
            std::cout << "Etape " << step 
                      << " - Population : " << ecosysteme.getMilieu().getPopulationSize() 
                      << std::endl;
        }
        
        // (Optionnel) Pour ralentir la simulation et observer l'évolution, vous pouvez ajouter un court délai :
        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    
    // Bilan final de la simulation
    std::cout << "Population finale : " << ecosysteme.getMilieu().getPopulationSize() << std::endl;
    
    // (Optionnel) Vous pouvez également parcourir et afficher les caractéristiques de chaque bestiole
    // par exemple, en récupérant la liste des bestioles via un getter adapté de Milieu.
    
    return 0;
}
