#ifndef BESTIOLE_DECORATOR_H
#define BESTIOLE_DECORATOR_H

#include "Bestiole.h"
#include "UImg.h"

/**
 * @brief Classe de base pour tous les décorateurs de Bestiole.
 *
 * Chaque décorateur contient un pointeur vers la Bestiole décorée et
 * ajoute ou modifie un comportement (détection, effet sur les attributs, etc.).
 */
class BestioleDecorator {
public:
    Bestiole* bestiole;  ///< Pointeur vers la bestiole décorée

    BestioleDecorator(Bestiole* b);
    virtual ~BestioleDecorator();

    

    /**
     * @brief Clone le décorateur pour une nouvelle instance de Bestiole.
     * @param b Nouvelle bestiole à décorer.
     * @return Pointeur sur le décorateur cloné.
     */
    virtual BestioleDecorator* clone(Bestiole* b) const = 0;
};

#endif // BESTIOLE_DECORATOR_H
