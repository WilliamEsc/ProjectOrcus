#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "complex.h"
#include "texture.h"
#include "def.h"

/*! \class personnage
* \brief classe représentant tous les personnages du jeu
*/
class personnage
{
protected:
    bool pop;                      ///< true si le personnage est actif
    Complex *pos;                  ///< position du joueur alloué sur le tas
    Complex *vit;                  ///< vitesse(direction) du joueur alloué sur le tas
    double angle;                  ///< angle d'affichage de l'image du personnage
    int pdv;                       ///< point de vie du personnage
    texture *persos = new texture; ///< texture du personnage alloué sur le tas

public:
    /**
     *\brief constructeur de la classe personnage
     */
    personnage();
    /**
     *\brief constructeur de la classe personnage
     * @param x float: position x du personnage.
     * @param y float: position y du personnage.
     */
    personnage(const float &x, const float &y);
    /**
     *\brief destructeur de la classe personnage
     */
    ~personnage();

    /**
     *\brief mutateur de int pdv du personnage
     * @param n int: entier qui sera donné au pdv du personnage.
     */
    void setPdv(const int &n);
    /**
     *\brief mutateur du bool pop du personnage
     * @param b bool: booleen qui sera donné a pop du personnage.
     */
    void setPop(const bool b);
    /**
     *\brief mutateur de la texture du personnage
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     * @param file pointer de char: nomde l'image.
     */
    void setTexture(SDL_Renderer *renderer, const char *file);
    /**
     *\brief mutateur de la position x et y du rectangle dest(affichage) du personnage
     * @param x float: position x du personnage.
     * @param x float: position x du personnage.
     */
    void setDest(const float &x, const float &y);

    /**
     *\brief accesseur de la texture du personnage
     */
    texture *getTexture() const;
    /**
     *\brief accesseur du rectangle dest de la texture du personnage
     */
    SDL_Rect getRect() const;
    /**
     *\brief accesseur du complex pos du personnage
     */
    Complex *getPos() const;
    /**
     *\brief accesseur du complex vit du personnage
     */
    Complex *getVit() const;
    /**
     *\brief accesseur du float angle du personnage
     */
    double getAngle() const;
    /**
     *\brief accesseur du int pdv du personnage
     */
    int getPdv() const;
    /**
     *\brief accesseur du bool pop du personnage
     */
    bool getPop() const;

    /**
     *\brief affiche la texture du personnage dans a fenetre sdl
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     */
    void drawPersonnage(SDL_Renderer *renderer);

    /**
     *\brief le personnage se fait touché
     * @param dmg int: dmg sera enlevé des pdv du personnage.
     */
    void getHit(const int &dmg);
};

#endif
