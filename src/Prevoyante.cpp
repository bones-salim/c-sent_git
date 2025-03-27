#include "Prevoyante.h"
#include "Bestiole.h"
#include "Milieu.h"

Prevoyante::Prevoyante(Bestiole* bestiole) : bestiole(bestiole) {
}

void Prevoyante::behave(Milieu& milieu, std::vector<Bestiole>& environnement) {
    // Implémentez ici le comportement spécifique de Prevoyante
    // Exemple d'implémentation :
    // bestiole->setOrientation( ... );
}

std::string Prevoyante::getNom() {
    return "Prevoyante";
}

std::unique_ptr<Comportement> Prevoyante::clone() {
    return std::make_unique<Prevoyante>(bestiole);
}

