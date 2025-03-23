#include "Milieu.h"
#include "Createur_Bestiole.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

const T Milieu::white[] = { (T)255, (T)255, (T)255 };

Milieu::Milieu(int _width, int _height) : UImg(_width, _height, 1, 3), width(_width), height(_height)
{
    std::cout << "const Milieu" << std::endl;
    std::srand(static_cast<unsigned int>(time(nullptr)));
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
   
}


//mort_naturelle
void Milieu::supprimerBestiole(Bestiole* b) {
   if (b->get_age() >= b->get_dureeVie()) {
      listeBestioles.erase(std::remove_if(listeBestioles.begin(), listeBestioles.end(),
      [b](const std::unique_ptr<Bestiole>& bestiolePtr) {
          return bestiolePtr.get() == b;
      }), listeBestioles.end());
   }
}

