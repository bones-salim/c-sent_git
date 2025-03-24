#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>

using namespace std;


class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   double            mortProb;
   

   T               * couleur;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );
   void setCouleur( int r, int g, int b );
   //added
   int getX() const { return x; };
   int getY() const { return y; };
   void setX(int _x) { x = _x; };
   void setY(int _y) { y = _y; };
   void setOrientation(double o) { orientation = o; };
   void setOrientation_cart(int x, int y){orientation = -std::atan2(y, x);};
   double getOrientation() const { return orientation; };
   void setVitesse(double v) { vitesse = v; };
   double getVitesse() const { return vitesse; };
   void collision();
   double setMortProb(double deathProb) { mortProb = deathProb; };
   double getMortProb() const { return mortProb; };

};


#endif
