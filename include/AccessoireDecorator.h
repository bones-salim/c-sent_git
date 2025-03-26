#ifndef ACCESSOIRE_DECORATOR_H
#define ACCESSOIRE_DECORATOR_H

#include "Bestiole.h"
#include "UImg.h"

/**
 * @brief Interface abstraite pour les accessoires.
 *
 * Chaque accessoire décorateur modifie les attributs de la Bestiole (par exemple,
 * la vitesse ou la probabilité de mort) et propose un rendu visuel.
 */
class AccessoireDecorator {
protected:
    Bestiole* bestiole; ///< Bestiole décorée
public:
    AccessoireDecorator(Bestiole* b) : bestiole(b) {}
    virtual ~AccessoireDecorator() {}
    
    /**
     * @brief Applique l'effet de l'accessoire sur la Bestiole.
     */
    virtual void applyEffect() = 0;
    
    /**
     * @brief Dessine l'effet visuel de l'accessoire sur le support graphique.
     * @param support Référence vers le support UImg.
     */
    virtual void drawEffect(UImg &support) = 0;
    
    /**
     * @brief Clone l'accessoire pour une nouvelle instance de Bestiole.
     * @param b Nouvelle Bestiole à décorer.
     * @return Pointeur sur le clone de l'accessoire.
     */
    virtual AccessoireDecorator* clone(Bestiole* b) const = 0;
};

#endif // ACCESSOIRE_DECORATOR_H
