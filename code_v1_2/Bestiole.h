#ifndef BESTIOLE_H
#define BESTIOLE_H

#include "UImg.h"
#include "Comportement.h"
#include "IBestiole.h"
#include "Clonable.h"
#include "Milieu.h"
#include <memory>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>

class Milieu;

class Bestiole : public Interface_Bestiole, public Clonable
{
private:
   static const double AFF_SIZE;
   static const double MAX_VITESSE;
   static const double LIMITE_VUE;

   static int next;

   int identite;
   int x, y;
   double cumulX, cumulY;
   double orientation;
   double vitesse;
   double mortProb;
   int dureeVie;
   int age;
   std::string nom;
   std::unique_ptr<Comportement> comportement;
   unsigned char* couleur;

   void bouge(int xLim, int yLim);

public:
   Bestiole(std::unique_ptr<Comportement> comportement);
   Bestiole(const Bestiole & b);
   Bestiole(int initX, int initY);
   ~Bestiole();

   void action(Milieu &monMilieu);
   void draw(UImg &support);
   int  get_age() const;
   double getVitesse() const;
   void setVitesse(double x);
   int  get_dureeVie() const;

   bool jeTeVois(const Bestiole &b) const;

   void initCoords(int xLim, int yLim);
   bool victoire(const Bestiole &autre);
   Comportement* getComportement() const;
   Bestiole* clone() const override;
   void preUpdate(int minX, int minY) override;
   void update(int minX, int minY) override;
   void collide() override;
   bool see(int entity) override;
   
   friend bool operator==(const Bestiole &b1, const Bestiole &b2);
};

#endif // BESTIOLE_H
