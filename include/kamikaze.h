#ifndef KAMIKAZE_H
#define KAMIKAZE_H
#include <cmath>
#include "Bestiole.h"
#include "Comportement.h"
class Bestiole;

class Kamikaze : public Comportement //heritage
{

    private:
        Bestiole *bestiole;
        void chase(Bestiole *target);
        


    protected:
    public:
        Kamikaze(Bestiole *bestiole);
        void behave(Milieu& milieu, std::vector<Bestiole>& ListeBestiole) override;
        virtual std::unique_ptr<Comportement> clone()  override;
        //reference vs pointers
        Bestiole* getTarget(std::vector<Bestiole>& ListeBestiole);
        void chase(Bestiole& target);
        ~Kamikaze() = default;
        std::string getNom() override;
        //change with new implementation
        double calculateDistance(const Bestiole &b1, const Bestiole &b2);

}
;
#endif



