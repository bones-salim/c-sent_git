#ifndef OREILLES_H
#define OREILLES_H

#include "SensorDecorator.h"

class Oreilles : public CapteurDecorator {
private:
    double delta;             // Distance maximale de détection par les oreilles (δo)
    double capaciteDetection;   // γo, capacité de détection par les oreilles (entre 0 et 1)
public:
    Oreilles(Bestiole* b, double delta, double capaciteDetection);
    virtual ~Oreilles();

    // Méthode de détection (à adapter selon votre logique globale)
    virtual void detecter() override;
    
    // Méthode de clonage pour permettre la duplication de la chaîne de décorateurs
    virtual BestioleDecorator* clone() const override;

    // Vérifie si la bestiole cible est dans la zone d'audition (omnidirectionnelle)
    bool dansChampAudition(const Bestiole& cible) const;

    // Vérifie si A entend B :
    // - B doit être dans la zone d'audition
    // - La capacité de détection de A (γo) doit être supérieure à la capacité de camouflage de B (ψ)
    bool jeTeDetecte(const Bestiole& cible) const;
};

#endif // OREILLES_H
