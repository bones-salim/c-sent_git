#ifndef YEUX_H
#define YEUX_H

#include "SensorDecorator.h"

/**
 * @brief Décorateur pour ajouter un capteur visuel (Yeux) à une Bestiole.
 *
 * La détection se fait si la cible se trouve dans un champ angulaire (alpha)
 * et à une distance inférieure ou égale à delta. De plus, la capacité de détection
 * (γy) doit être supérieure à la capacité de camouflage de la cible.
 */
class Yeux : public SensorDecorator {
private:
    double alpha;            ///< Champ angulaire de vision (en radians)
    double delta;            ///< Distance maximale de détection visuelle
    double capaciteDetection;///< Capacité de détection (γy) entre 0 et 1
public:
    Yeux(Bestiole* b, double alpha, double delta, double capaciteDetection);
    virtual ~Yeux();

    virtual bool jeTeDetecte(const Bestiole &autre) override;
    virtual SensorDecorator* clone(Bestiole* b) const override;
    
    /**
     * @brief Vérifie si la cible se trouve dans le champ de vision.
     * @param cible La bestiole cible.
     * @return true si la cible est dans le champ, false sinon.
     */
    bool dansChampVision(const Bestiole &cible) const;
};

#endif // YEUX_H
