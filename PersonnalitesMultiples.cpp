#include "PersonnalitesMultiples.h"
#include <cstdlib>
#include <ctime>

PersonnalitesMultiples::PersonnalitesMultiples(double probaChangement)
    : probaChangement(probaChangement), comportementActuel(nullptr) {
    srand(time(0));
}

void PersonnalitesMultiples::ajouterComportement(Comportement* comportement) {
    comportements.push_back(comportement);
}

void PersonnalitesMultiples::appliquer(Bestiole& b, const std::vector<Bestiole>& environnement) {
    if (!comportements.empty() && (rand() / (double)RAND_MAX < probaChangement)) {
        int index = rand() % comportements.size();
        comportementActuel = comportements[index];
    }

    if (comportementActuel) {
        comportementActuel->appliquer(b, environnement);
    }
}