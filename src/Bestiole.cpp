#include "Bestiole.h"

const double Bestiole::AFF_SIZE = 8.;
const double Bestiole::MAX_VITESSE = 10.;
const double Bestiole::LIMITE_VUE = 30.;

int Bestiole::next = 0;

Bestiole::Bestiole(std::unique_ptr<Comportement> comportement) : comportement(std::move(comportement))
{
   identite = ++next;
   std::cout << "const Bestiole (" << identite << ") par defaut" << std::endl;
   mortProb = 0.5; 
   x = y = 2;
   cumulX = cumulY = 0.4;
   orientation = static_cast<double>(rand()) / RAND_MAX * 2. * M_PI;
   vitesse = static_cast<double>(rand()) / RAND_MAX * MAX_VITESSE;
   dureeVie = 20;
   age=10;
   couleur = new unsigned char[3];
   couleur[0] = static_cast<unsigned char>(rand() % 230);
   couleur[1] = static_cast<unsigned char>(rand() % 230);
   couleur[2] = static_cast<unsigned char>(rand() % 230);
}

Bestiole::Bestiole(const Bestiole &b)
    : comportement(nullptr)  // On initialise à nullptr
{
    identite = ++next;
    std::cout << "const Bestiole (" << identite << ") par copie" << std::endl;

    x = b.x + 1;
    y = b.y + 1;
    cumulX = cumulY = 0.;
    orientation = b.orientation;
    vitesse = b.vitesse;
    dureeVie = b.dureeVie;
    age = b.age;

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


void Bestiole::dessiner(UImg &support) {
   support.draw_circle(x, y, 5, this->couleur);
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


void Bestiole::setCouleur(int r, int g, int b) {
   couleur[0] = static_cast<unsigned char>(r);
   couleur[1] = static_cast<unsigned char>(g);
   couleur[2] = static_cast<unsigned char>(b);
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

    // Dessiner les accessoires
    for (const auto& accessoire : listedesaccessoires) {
        accessoire->drawEffect(support);
    }

    // Dessiner les capteurs
    for (const auto& capteur : listedescapteurs) {
        capteur->drawEffect(support);
    }
}


bool Bestiole::jeTeVois(Bestiole &autre) const {
   for (const auto& capteur : listedescapteurs) { // Changer le nom pour éviter confusion
       if (capteur->jeTeDetecte(autre)) {
           return true; // `true` en C++
       }
   }
   return false; // `false` en C++
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

std::string Bestiole::getNom() const {
   return this->nom;
}

double  Bestiole::getVitesse() const {
   return this->vitesse;
}

void  Bestiole::setVitesse(double x) {
   this->vitesse = x ;
}
void Bestiole::collide() {
   {
      // Roll a dice to see if the Bestiole dies
      double ran = static_cast<double>(std::rand()) / RAND_MAX;
      if (ran > mortProb)
      {
         orientation = std::fmod(orientation + M_PI, 2 * M_PI);
         
      }
      else
      {
         dureeVie= -1;
      }
   }
}
double Bestiole::getMortProb() const {
   return this->mortProb;
}

void Bestiole::setMortProb(double p)  {
   this->mortProb = p;
}
void Bestiole::setComportement(std::unique_ptr<Comportement> comp) {
   comportement = std::move(comp);
}
void Bestiole::preUpdate(int minX, int minY) {}
void Bestiole::update(int minX, int minY) {}
unsigned char Bestiole::getcouleur() const {
   return (couleur != nullptr) ? couleur[0] : 0;}
