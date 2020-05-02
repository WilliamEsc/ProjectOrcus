#ifndef LOOT_H
#define LOOT_H

#include "def.h"
#include "hero.h"

/*! \class loot
* \brief classe représentant les équipements au sol
*/
class loot : public objet
{
private:
    int type; ///<type du loot

public:
    /**
     *\brief constructeur de la classe loot
     * @param t int: type du loot 0:ak47
     * @param x float: position x de l'objet
     * @param y float: position y de l'objet
     */
    loot(const int &t, const float &x, const float &y);
    /**
     *\brief destructeur de la classe loot
     */
    ~loot();

    /**
     *\brief change la texture suivant le type du loot
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     */
    void setTexture(SDL_Renderer *ren);
    /**
     *\brief choisi les effets du loot suivant son type
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     * @param J hero: personnage qui va recevoir les effets du loot.
     */
    void looting(SDL_Renderer *ren, hero &J);
};

#endif