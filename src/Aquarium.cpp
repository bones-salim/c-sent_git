#include "Aquarium.h"

#include "Milieu.h"


Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{
   // Initialisation des valeurs limites pour la vision
   alpha_min = M_PI/12  ;      // par exemple, 15°
   alpha_max = M_PI / 2.0;        // par exemple, 90° en radians
   delta_min_y = 50.0;          // distance minimale de détection visuelle
   delta_max_y = 200;         // distance maximale de détection visuelle
   gamma_min_y = 0.1;
   gamma_max_y = 0.9;           // capacité de détection entre 0 et 1

   // Initialisation des valeurs limites pour l'audition
   delta_min_o = 40. ;          // distance minimale de détection auditive
   delta_max_o = 170.0;         // distance maximale de détection auditive
   gamma_min_o = 0.2;
   gamma_max_o = 0.8;           // capacité de détection entre 0 et 1

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   cout << "const Aquarium" << endl;

   flotte = new Milieu( width, height );
   assign( *flotte, "Simulation d'ecosysteme" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}


Aquarium::~Aquarium( void )
{

   delete flotte;

   cout << "dest Aquarium" << endl;

}


void Aquarium::run( void )
{

   cout << "running Aquarium" << endl;

   while ( ! is_closed() )
   {

      // cout << "iteration de la simulation" << endl;

      if ( is_key() ) {
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();
      }

      flotte->step();
      display( *flotte );

      wait( delay );

   } // while

}