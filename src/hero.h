#ifndef HERO_H
#define HERO_H

#include "complex.h"
#include "arme.h"
#include "personnage.h"

/*! \class hero
* \brief classe représentant le personnage jouable
*/
class hero : public personnage
{
private:
    SDL_Rect barrePdv;    ///< rectangle pour representer la vie du joueur
    arme *wep = new arme; ///< pointer d'arme du joueur alloué sur le tas

public:
    /**
     *\brief constructeur de la classe hero
     */
    hero();

    /**
     *\brief destructeur de la classe hero
     */
    ~hero();

    /**
     *\brief mutateur du pointer d'arme (wep) de la classe hero
     * @param arme pointer de arme: doit être alloué sur le tas l'adresse sera donné a wep de hero.
     */
    void setArme(const arme &arme);
    /**
     *\brief accesseur du pointer d'arme (wep) dela classe hero
     */
    arme *getArme() const;

    /**
     *\brief mutateur du SDL_Rect barrePdv de la classe hero (origine en haut a gauche)
     * @param x float: position x du rectangle.
     * @param y float: position y du rectangle.
     * @param h float: hauteur du rectangle.
     * @param w float: largeur du rectangle.
     */
    void setBarrePdv(const float &x, const float &y, const float &h, const float &w);
    /**
     *\brief mutateur du SDL_Rect barrePdv de la classe hero
     */
    SDL_Rect getBarrePdv() const;

    /**
     *\brief appel la fonction tir de l'arme du hero
     */
    void tir();
    /**
     *\brief ajoute deg a angle et calcul la nouvelle position du complex vit
     * @param deg double: angle en radian a ajouté.
     */
    void ajoutAngle(const double &deg);
    /**
     *\brief deplacement du joueur
     * @param f float: augmente la vitesse, f > 0 direction en bas, <0 en haut.
     * @param deg double: angle en radian a ajouté.
     * @param collision pointer de tableau int: tableau des collisions de la carte.
     */
    void deplace(const float &f, const double &ang, const int *collision);
    /**
     *\brief appel a la fonction hit de l'arme
     * @param pos Complex: position de la cible.
     */
    bool Hit(const Complex &pos);
    /**
     *\brief verifie si le joueur est arrivé a l'objectif
     */
    bool estArrive();
    /**
     *\brief deplacement des ennemies de type=1 les rando
     * @param renderer SDL_Renderer: le renderer de la fenetre SDL.
     */
    void drawPersonnage(SDL_Renderer *ren);
    /**
     *\brief mutateur des textures du joueur
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     * @param file pointer de char: nom de l'image pour le joueur.
     * @param file2 pointer de char: nom de l'image pour la balle.
     */
    void setTexture(SDL_Renderer *ren, const char *file, const char *file2);
};

#endif