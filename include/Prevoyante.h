#ifndef PREVOYANTE_H
#define PREVOYANTE_H

#include "Comportement.h"
#include <memory>
#include <string>
#include <vector>

class Bestiole;
class Milieu;

class Prevoyante : public Comportement {
private:
    Bestiole* bestiole;
public:
    Prevoyante(Bestiole* bestiole);

    void behave(Milieu& milieu, std::vector<Bestiole>& environnement) override;
    std::string getNom() override;
    std::unique_ptr<Comportement> clone() override;
};

#endif
