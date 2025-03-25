// Createur_Bestiole.h
#ifndef CREATEUR_BESTIOLE_H
#define CREATEUR_BESTIOLE_H

#include "Createur.h"
#include "Bestiole.h"
#include "Comportement.h"

class Createur_Bestiole : public Createur {
private:
    static Createur_Bestiole* instance;
    Createur_Bestiole() {} // Singleton
    Createur_Bestiole(const Createur_Bestiole&) ;
    Createur_Bestiole& operator=(const Createur_Bestiole&) ;

public:
    static Createur_Bestiole* getInstance();
<<<<<<< HEAD
    Bestiole* creerBestiole(std::unique_ptr<Comportement>) override;
=======
    Bestiole* creerBestiole(Comportement* comp);
>>>>>>> 190583cf5849345e9f7cf7ae76a4d2235bc9af27
};

#endif