#ifndef CLES_H
#define CLES_H

#include "objet.h"
#include "map.h"

/*! \class cles
* \brief classe représentant la cles pour ouvrir les passages
*/
class cles : public objet
{
private:
public:
    /**
     *\brief constructeur de la classe cles
     * @param x float: position x de l'objet.
     * @param y float: position y de l'objet.
     */
    cles(float x, float y);

    /**
     *\brief destructeur de la classe cles
     */
    ~cles();

    /**
     *\brief modifie la carte pour afficher les portes ouvertes et modifie les collisions pour correspondre au nouvel affichage
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     * @param m map: la map qui sera modifié.
     */
    void ouvrePorte(SDL_Renderer *renderer, map &m);
};
#endif
