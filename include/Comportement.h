#ifndef COMPORTEMENT_H
#define COMPORTEMENT_H

#include <string>
#include <vector>
#include <memory>

class Bestiole;
class Milieu;

class Comportement
{
public:
    virtual void behave(Milieu& milieu, std::vector<Bestiole>& ListeBestiole) = 0;
    virtual ~Comportement() = default;
    virtual std::string getNom() = 0;
    virtual std::unique_ptr<Comportement> clone() = 0;
};

#endif  // COMPORTEMENT_H
