#include "PersonnalitesMultiples.h"
#include <cstdlib>
#include <ctime>

// Constructeur initialisant la probabilité de changement et le générateur de nombres aléatoires
PersonnalitesMultiples::PersonnalitesMultiples(double probaChangement)
    : probaChangement(probaChangement), comportementActuel(nullptr) {
    srand(time(0));  // Initialisation du générateur de nombres aléatoires
}

// Ajouter un comportement à la liste des comportements disponibles
void PersonnalitesMultiples::ajouterComportement(Comportement* comportement) {
    comportements.push_back(comportement);
}

// Appliquer le comportement actuel ou en choisir un nouveau avec une certaine probabilité
void PersonnalitesMultiples::appliquer(Bestiole& b, const std::vector<Bestiole>& environnement) {
    // Changer de comportement avec une probabilité donnée
    if (!comportements.empty() && (rand() / (double)RAND_MAX < probaChangement)) {
        int index = rand() % comportements.size();  // Choisir un comportement aléatoire
        comportementActuel = comportements[index];
    }

    // Appliquer le comportement actuel s'il existe
    if (comportementActuel) {
        comportementActuel->appliquer(b, environnement);
    }
}
