#include <string>
#include <vector>
#ifndef comportement_h
#define comportement_h
class Bestiole;
class Comportement
{
    private:
    protected:
        Bestiole *bestiole;
    public:
        virtual void behave(std::vector<Bestiole>& ListeBestiole) = 0;
        //virtual Comportement *clone(Bestiole *bestiole) const = 0;
        //pure virtual function  default Beahaviour de
        virtual ~Comportement() = default;
      virtual std::string getNom() =0;
      virtual std::unique_ptr<Comportement> clone() const = 0;
      
    } ;
#endif