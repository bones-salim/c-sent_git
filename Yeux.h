#ifndef YEUX_H
#define YEUX_H

#include "SensorDecorator.h"

class Yeux : public CapteurDecorator {
private:
    double alpha;       // Champ angulaire de vision (en radians)
    double delta;       // Distance maximale de détection
    double capaciteDetection; // γy, capacité de détection (entre 0 et 1)
public:
    Yeux(Bestiole* b, double alpha, double delta, double capaciteDetection);
    virtual ~Yeux();

    // Méthode de détection (à compléter selon la logique de la simulation)
    virtual void detecter() override;
    
    // Méthode de clonage
    virtual BestioleDecorator* clone() const override;

    // Vérifie si une bestiole cible est dans le champ de vision
    bool dansChampVision(const Bestiole& cible) const;

    // Vérifie si A détecte B : A voit B (dansChampVision) et γy(A) > ψ(B)
    bool jeTeDetecte(const Bestiole& cible) const;
};

#endif // YEUX_H
