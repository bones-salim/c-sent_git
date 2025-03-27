#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_


#include <iostream>
#include <CImg.h>

using namespace std;
using namespace cimg_library;


class Milieu;


class Aquarium : public CImgDisplay
{

private :
   Milieu       * flotte;

   int            delay;
   // Valeurs limites de perception pour la vision
   double alpha_min;   ///< angle minimal (en radians)
   double alpha_max;   ///< angle maximal (en radians)
   double delta_min_y; ///< distance minimale de détection visuelle
   double delta_max_y; ///< distance maximale de détection visuelle
   double gamma_min_y; ///< capacité de détection minimale pour les yeux
   double gamma_max_y; ///< capacité de détection maximale pour les yeux

   // Valeurs limites de détection pour l'audition
   double delta_min_o; ///< distance minimale de détection auditive
   double delta_max_o; ///< distance maximale de détection auditive
   double gamma_min_o; ///< capacité de détection minimale pour les oreilles
   double gamma_max_o; ///< capacité de détection maximale pour les oreilles
public :
   Aquarium( int width, int height, int _delay );
   ~Aquarium( void );

   Milieu & getMilieu( void ) { return *flotte; }

   void run( void );
   // Getters pour la configuration (utiles lors de la création des capteurs)
   double getAlphaMin() const { return alpha_min; }
   double getAlphaMax() const { return alpha_max; }
   double getDeltaMinY() const { return delta_min_y; }
   double getDeltaMaxY() const { return delta_max_y; }
   double getGammaMinY() const { return gamma_min_y; }
   double getGammaMaxY() const { return gamma_max_y; }

   double getDeltaMinO() const { return delta_min_o; }
   double getDeltaMaxO() const { return delta_max_o; }
   double getGammaMinO() const { return gamma_min_o; }
   double getGammaMaxO() const { return gamma_max_o; }
};




#endif