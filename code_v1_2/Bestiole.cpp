#include "Bestiole.h"

const double Bestiole::AFF_SIZE = 8.;
const double Bestiole::MAX_VITESSE = 10.;
const double Bestiole::LIMITE_VUE = 30.;

int Bestiole::next = 0;

Bestiole::Bestiole(std::unique_ptr<Comportement> comportement) : comportement(std::move(comportement))
{
   identite = ++next;
   std::cout << "const Bestiole (" << identite << ") par defaut" << std::endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>(rand()) / RAND_MAX * 2. * M_PI;
   vitesse = static_cast<double>(rand()) / RAND_MAX * MAX_VITESSE;
   dureeVie = 20;
   age=10;

   couleur = new unsigned char[3];
   couleur[0] = static_cast<unsigned char>(rand() % 230);
   couleur[1] = static_cast<unsigned char>(rand() % 230);
   couleur[2] = static_cast<unsigned char>(rand() % 230);
}

Bestiole::Bestiole(const Bestiole &b): comportement(b.comportement ? b.comportement->clone() : nullptr) 
{
    identite = ++next;
    std::cout << "const Bestiole (" << identite << ") par copie" << std::endl;

<<<<<<< HEAD
    x = b.x + 1;
    y = b.y + 1;
    cumulX = cumulY = 0.;
    orientation = b.orientation;
    vitesse = b.vitesse;
    dureeVie = b.dureeVie;
    age = b.age;
=======
   x = b.x + 1;
   y = b.y + 1;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   comportement = b.comportement;
   dureeVie = b.dureeVie;
   age=b.age;
>>>>>>> 190583cf5849345e9f7cf7ae76a4d2235bc9af27

    couleur = new unsigned char[3];
    std::copy(b.couleur, b.couleur + 3, couleur);
}


Bestiole::~Bestiole()
{
   delete[] couleur;
   std::cout << "dest Bestiole" << std::endl;
}

void Bestiole::initCoords(int xLim, int yLim)
{
   x = rand() % xLim;
   y = rand() % yLim;
}

Comportement* Bestiole::getComportement() const {
   return comportement.get();
}
void Bestiole::bouge(int xLim, int yLim)
{
   double nx, ny;
   double dx = cos(orientation) * vitesse;
   double dy = -sin(orientation) * vitesse;
   int cx = static_cast<int>(cumulX);
   int cy = static_cast<int>(cumulY);

   cumulX -= cx;
   cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if (nx < 0 || nx > xLim - 1) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   } else {
      x = static_cast<int>(nx);
      cumulX += nx - x;
   }

   if (ny < 0 || ny > yLim - 1) {
      orientation = -orientation;
      cumulY = 0.;
   } else {
      y = static_cast<int>(ny);
      cumulY += ny - y;
   }
}

void Bestiole::action(Milieu &monMilieu)
{
   bouge(monMilieu.getWidth(), monMilieu.getHeight());
}

void Bestiole::draw(UImg &support)
{
   double xt = x + cos(orientation) * AFF_SIZE / 2.1;
   double yt = y - sin(orientation) * AFF_SIZE / 2.1;

   support.draw_ellipse(x, y, AFF_SIZE, AFF_SIZE / 5., -orientation / M_PI * 180., couleur);
   support.draw_circle(xt, yt, AFF_SIZE / 2., couleur);
}

bool Bestiole::jeTeVois(const Bestiole &b) const
{
   double dist = std::sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
   return (dist <= LIMITE_VUE);
}

bool Bestiole::victoire(const Bestiole &autre)
{
   return this->dureeVie > autre.dureeVie;
}

Bestiole* Bestiole::clone() const
{
   return new Bestiole(*this); 
}

bool operator==(const Bestiole &b1, const Bestiole &b2)
{
   return (b1.identite == b2.identite);
}

int Bestiole::get_age() const {
   return this->age;
}

int  Bestiole::get_dureeVie() const{
   return this->dureeVie;
}
void Bestiole::preUpdate(int minX, int minY) {}
void Bestiole::update(int minX, int minY) {}
void Bestiole::collide() {}
bool Bestiole::see(int entity) {}