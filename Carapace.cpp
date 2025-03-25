/**
 * @file Carapace.cpp
 * @brief Implements the Carapace class.
 */
#include "Carapace.h"
#include "Bestiole.h"
#include <cstring>
#include <cmath>

Carapace::Carapace(Bestiole* b, double eta, double omega)
{
    this->bestiole = b;
    this->eta = eta;
    this->omega = omega;

    couleur = new unsigned char[3];
    couleur[0] = 255; // Rouge
    couleur[1] = 0;
    couleur[2] = 0;

    applyEffect();
}

Carapace::~Carapace()
{
    delete[] couleur;
}

void Carapace::applyEffect()
{
    bestiole->setVitesse( bestiole->getVitesse() / eta );
    bestiole->setMortProb( bestiole->getMortProb() / omega );
}

void Carapace::drawEffect(UImg &support)
{
    support.draw_circle(bestiole->x, bestiole->y, 15, couleur, 0.1);
}


Carapace* Carapace::clone(Bestiole* b) const
{   
    return new Carapace(b, eta, omega);
}
