#include "Kamikaze.h"
#include <vector>
#include "Milieu.h"
Kamikaze::Kamikaze(Bestiole *bestiole) : bestiole(bestiole)
{
}
void Kamikaze::behave()
{
    //bestiole->setCouleur(255, 0, 0);   // Red color for Kamikaze
    // Identify the nearest bestiole and find it
    Bestiole *target = getTarget();
    if ((target) ) 
    {
        // Move in order to collide with it
        chase(target);
    }
}
Bestiole *Kamikaze::getTarget()
    {
        double minDistance=1000000;
        Bestiole* target=nullptr;
        for (std::vector<Bestiole>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it)

            if (bestiole->jeTeVois(*it))
            {
                double distance = calculateDistance(*bestiole, *it);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    target = &(*it);
                }
            }
        return target;
        }
        
    
void Kamikaze::chase(Bestiole *target)
    {
        double dx = target->getX() - bestiole->getX();
        double dy = target->getY() - bestiole->getY();
        double norm = sqrt(dx * dx + dy * dy);
        if (norm>0)
        {
            dx = dx / norm;
            dy = dy / norm;
        }
        double direction= -std::atan2(dy, dx); //angle inversed becasue it's in flipped coordinates
        bestiole->setOrientation(direction);
   
    }
double Kamikaze::calculateDistance(const Bestiole &b1, const Bestiole &b2)
    {
        double dx = b1.getX() - b2.getX();
        double dy = b1.getY() - b2.getY();
        return sqrt(dx * dx + dy * dy);
    }

Comportement *Kamikaze::clone(Bestiole *bestiole) const
{
    return new Kamikaze(bestiole);
}