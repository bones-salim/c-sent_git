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

<<<<<<< HEAD
    // Méthodes abstraites à implémenter par les décorateurs
    virtual bool jeTeDetecte(const Bestiole &autre) = 0;
    virtual void applyEffect() = 0;
    virtual void drawEffect(UImg &support) = 0;
=======
    
>>>>>>> 86249425fee87e2ab26c88c03c736d7b5760fc59

    /**
     * @brief Clone le décorateur pour une nouvelle instance de Bestiole.
     * @param b Nouvelle bestiole à décorer.
     * @return Pointeur sur le décorateur cloné.
     */
    virtual BestioleDecorator* clone(Bestiole* b) const = 0;
};

#endif // BESTIOLE_DECORATOR_H
