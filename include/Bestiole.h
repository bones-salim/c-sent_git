#ifndef BESTIOLE_H
#define BESTIOLE_H
#include "AccessoireDecorator.h"
#include "UImg.h"
#include "Comportement.h"
#include "SensorDecorator.h"
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
   double Visibilite;
   std::string nom;
   std::unique_ptr<Comportement> comportement;
   unsigned char* couleur;
   bool mort=false; 

public:
   std::vector<std::unique_ptr<SensorDecorator>> listedescapteurs;
   std::vector<std::unique_ptr<AccessoireDecorator>> listedesaccessoires;
   Bestiole();
   Bestiole(std::unique_ptr<Comportement> comportement);
   Bestiole(const Bestiole & b);
   Bestiole(int initX, int initY);
   ~Bestiole();

   void action(Milieu &monMilieu);
   void draw(UImg &support);

   bool jeTeVois(Bestiole &b) const;

   void initCoords(int xLim, int yLim);
   bool victoire(const Bestiole &autre);

   Bestiole* clone() const override;
   void preUpdate(int minX, int minY) override;
   void update(int minX, int minY) override;
   void collide() override;

   // Getters et setters
   int getX() const { return x; };
   int getY() const { return y; };
   double getOrientation() const { return orientation; };
   int getDureeVie() const { return dureeVie; };
   int getAge() const { return age; };
   double getVitesse() const;
   int get_dureeVie() const;
   Comportement* getBehavior() const { 
      return comportement.get(); 
  }
   Comportement* getComportement() const;

   int get_age() const;
   unsigned char getcouleur() const ;
   double getMortProb() const;
   std::string getNom() const;
   double getVisibilite() const { return Visibilite; };
   double getAFF_SIZE() const {return AFF_SIZE;};
   bool getMort() const { return mort; };
   void setVisibilite(double x) { Visibilite = x; };
   void setX(int _x) { x = _x; };
   void setY(int _y) { y = _y; };
   void setCouleur(int r, int g, int b);
   void setOrientation(double o) { orientation = o; };
   void setOrientation_cart(int x, int y) { orientation = -std::atan2(y, x) * 180.0 / M_PI; };
   void setVitesse(double x);
   void setMortProb(double p);
   void setDureeVie(int dureeVie_) { dureeVie = dureeVie_; };
   void setMort(bool m) { mort = m; };
   void setAge(int age_) { age = age_; };
   void bouge(int xLim, int yLim);
   void setComportement(std::unique_ptr<Comportement> comp) ;
   void dessiner(UImg &support);
   friend bool operator==(const Bestiole &b1, const Bestiole &b2);
};

#endif // BESTIOLE_H

