#ifndef SENSOR_DECORATOR_H
#define SENSOR_DECORATOR_H

#include "Bestiole.h"
#include "UImg.h"

/**
 * @brief Interface abstraite pour les capteurs.
 *
 * Chaque capteur décorateur contient un pointeur vers la Bestiole décorée
 * et doit implémenter la méthode de détection, ici sous la forme de jeTeDetecte.
 */
class SensorDecorator {
protected:
    Bestiole* bestiole; ///< Bestiole décorée
public:
    SensorDecorator(Bestiole* b) : bestiole(b) {}
    virtual ~SensorDecorator() {}
    
    /**
     * @brief Détermine si le capteur détecte une bestiole cible.
     * @param autre La bestiole cible.
     * @return true si détectée, false sinon.
     */
    virtual bool jeTeDetecte(const Bestiole &autre) = 0;
    
    /**
     * @brief Clone le capteur pour une nouvelle instance de Bestiole.
     * @param b Nouvelle Bestiole à décorer.
     * @return Pointeur sur le clone du capteur.
     */
    virtual SensorDecorator* clone(Bestiole* b) const = 0;
};

#endif // SENSOR_DECORATOR_H
