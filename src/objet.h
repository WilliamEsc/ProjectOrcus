#ifndef OBJET_H
#define OBJET_H

#include "def.h"
#include "texture.h"
#include "complex.h"

/*! \class objet
* \brief Une classe pour les objets du jeu
*/
class objet
{
protected:
    bool pop;                   ///< true si l'objet est actif
    texture *s = new texture(); ///< pointer de texture de l'objet alloué sur le tas
    Complex posObj;             ///< position de l'objet

public:
    /**
     *\brief constructeur de l'objet
     */
    objet();
    /**
     *\brief constructeur de l'objet
     * @param x float: position x a donné a l'objet.
     * @param y float: position y a donné a l'objet.
     */
    objet(const float &x, const float &y);

    /**
     *\brief accesseur du booleen pop de l'objet
     */
    bool getPop() const;
    /**
     *\brief mutateur du booleen pop de l'objet
     * @param b bool: booleen a donné a l'objet.
     */
    void setPop(bool b);

    /**
     *\brief mutateur des composant x et y du complex posObj
     * @param x float: position x a donné a l'objet.
     * @param y float: position y a donné a l'objet.
     */
    void setPos(const float &x, const float &y);
    /**
     *\brief accesseur du complex posObj de l'objet
     */
    Complex getPos() const;
    /**
     *\brief accesseur de la position y de l'objet
     */
    float getPosX() const;
    /**
     *\brief accesseur de la position y de l'objet
     */
    float getPosY() const;

    /**
     *\brief accesseur du pointer de texture s de l'objet
     */
    texture *getTexture() const;
    /**
     *\brief mutateur de la texture s de l'objet
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     * @param file pointer de char: nom de l'image.
     */
    void setTexture(SDL_Renderer *ren, const char *file);
    /**
     *\brief affiche l'objet dans la fenetre SDL
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     */
    void drawObjet(SDL_Renderer *ren) const;

    /**
     *\brief accesseur de SDL_Rect de la texture s de l'objet
     */
    SDL_Rect getRect();

    /**
     *\brief mutateur de SDL_Texture tex de la texture
     * @param file pointer de char: nom de l'image.
     */
    void setFile(const char *file);
    /**
     *\brief accesseur du nom de l'image
     */
    const char *getFileName();

    /**
     *\brief destructeur de la classe objet
     */
    ~objet();
};
#endif