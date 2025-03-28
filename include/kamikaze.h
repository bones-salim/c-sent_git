#ifndef KAMIKAZE_H
#define KAMIKAZE_H

#include "Comportement.h"
#include "Bestiole.h"
#include <vector>
#include <memory>

class Kamikaze : public Comportement
{
private:
    Bestiole *bestiole;

public:
    Kamikaze(Bestiole *bestiole);

    void behave(std::vector<std::unique_ptr<Bestiole>>& listeBestioles) override;
    Bestiole* getTarget(std::vector<std::unique_ptr<Bestiole>>& listeBestioles);
    void chase(Bestiole *target);
    double calculateDistance(const Bestiole &b1, const Bestiole &b2);

    std::string getNom() const override ;
    std::unique_ptr<Comportement> clone(Bestiole *bestiole) const override ;

};

#endif




