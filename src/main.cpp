#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    const int width = 640;
    const int height = 480;
    const int delay = 10;

    // Création de l'écosystème avec la taille spécifiée
    Aquarium ecosysteme(width, height, delay);

    // Création initiale des bestioles
    for (int i = 0; i < 200; ++i) {
        ecosysteme.getMilieu().naissance();
    }

    // Lancer explicitement l'affichage graphique
    ecosysteme.run();

    return 0;
}
