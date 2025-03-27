#include "kamikaze.h"
#include "Bestiole.h"
#include "Milieu.h"

Kamikaze::Kamikaze(Bestiole* bestiole) : bestiole(bestiole) {
}

void Kamikaze::behave(Milieu& milieu, std::vector<Bestiole>& ListeBestiole) {
    // Implémentez ici le comportement spécifique de Kamikaze
}

std::string Kamikaze::getNom() {
    return "Kamikaze";
}

std::unique_ptr<Comportement> Kamikaze::clone() {
    return std::make_unique<Kamikaze>(bestiole);
}
   