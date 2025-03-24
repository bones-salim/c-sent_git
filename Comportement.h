#ifndef comportement_h
#include <vector>
#define comportement_h
class Bestiole;
class Comportement
{
    private:
    protected:
        Bestiole *bestiole;
    public:
        virtual void behave(std::vector<Bestiole>& ListeBestioles) = 0;
        virtual Comportement *clone(Bestiole *bestiole) const = 0;
        //pure virtual function  default Beahaviour de
        virtual ~Comportement() = default;
}
;
#endif