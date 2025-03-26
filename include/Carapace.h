#ifndef CARAPACE_H
#define CARAPACE_H

#include "AccessoireDecorator.h"
#include "UImg.h"

/**
 * @brief Classe Carapace.
 *
 * Réduit la vitesse de la bestiole et diminue sa probabilité de mourir lors d'une collision.
 */
class Carapace : public AccessoireDecorator {
private:
    double eta;    ///< Facteur de réduction de vitesse (η ∈ [1 ; η_max])
    double omega;  ///< Facteur de réduction de la probabilité de mort (ω ∈ [1 ; ω_max])
    unsigned char* couleur; ///< Couleur utilisée pour le dessin de l'indicateur visuel (allouée dynamiquement)
public:
    /**
     * @brief Constructeur.
     * @param bestiole Pointeur vers la bestiole décorée.
     * @param eta Facteur de réduction de vitesse.
     * @param omega Facteur de réduction de la probabilité de mort.
     */
    Carapace(Bestiole *bestiole, double eta, double omega);

    /**
     * @brief Destructeur.
     */
    virtual ~Carapace();

    /**
     * @brief Applique l'effet de la carapace sur la bestiole.
     *
     * Réduit la vitesse et la probabilité de mort en fonction de eta et omega.
     */
    virtual void applyEffect() override;

    /**
     * @brief Dessine l'effet visuel de la carapace.
     *
     * Affiche, par exemple, un cercle autour de la bestiole.
     * @param x Abscisse de la bestiole.
     * @param y Ordonnée de la bestiole.
     * @param orientation Orientation de la bestiole (non utilisé ici).
     * @param support Référence vers le support graphique UImg.
     */
    virtual void drawEffect(int x, int y, double orientation, UImg &support) override;

    /**
     * @brief Clone la carapace pour une autre bestiole.
     * @param b Pointeur vers la nouvelle bestiole à décorer.
     * @return Un pointeur vers la nouvelle instance clonée.
     */
    virtual Carapace* clone(Bestiole *b) const override;
};

#endif // CARAPACE_H
