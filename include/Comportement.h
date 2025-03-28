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
    virtual void behave(std::vector<std::unique_ptr<Bestiole>>& listeBestioles)=0;
    virtual ~Comportement() = default;
    virtual std::string getNom() const = 0;
    virtual std::unique_ptr<Comportement> clone(Bestiole* bestiole) const = 0;
};

#endif  // COMPORTEMENT_H
