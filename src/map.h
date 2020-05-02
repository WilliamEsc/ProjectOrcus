#ifndef MAP_H
#define MAP_H

#include "def.h"
#include "texture.h"
#include "complex.h"

/*! \class map
* \brief classe représentant la carte et les collisions
*/
class map
{

    private:
    int *Collision = new int[15376]; ///< pointer de tableau d'int alloué sur le tas, maping des collision
    texture *mappng = new texture(); ///< texture de la carte alloué sur le tas


public:
    /**
     *\brief constructeur de la classe map
     */
    map();
    /**
     *\brief constructeur de la classe map
     * @param rend SDL_Renderer: le renderer de la fenetre SDL.
     */
    map(SDL_Renderer *rend);
    /**
     *\brief destructeur de la classe map
     */
    ~map();

    /**
     *\brief mutateur de la texture mappng
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     * @param file pointeur de char: nom du fichier.
     */
    void setMapPng(SDL_Renderer *renderer, const char *file);
    /**
     *\brief accesseur de la texture mappng
     */
    texture *getMapPNG() const;

    /**
     *\brief change la valeur de la case en position x(abscisse) y (ordonnée) par val
     * @param y int: position y de la case.
     * @param x int: position x de la case.
     * @param val int: valeur qui sera mise a la position defini par x et y
     */
    void setCollision(const int &y, const int &x, const int &val);
    /**
     *\brief accesseur du pointer de tableau d'int Collision
     */
    int *getCollision() const;
    /**
     *\brief accesseur de la valeur de la case en position x(abscisse) y (ordonnée)
     * @param y int: position y de la case.
     * @param x int: position x de la case.
     */
    int getCollision(const int &y, const int &x) const;

    /**
     *\brief recopie les données du fichier file dans Collision (les valeurs doivent être des entiers et séparé par des espaces et 124*124 valeur)
     * @param file pointer de char:nom du fichier
     */
    void loadCollision(const char *file);

    /**
     *\brief affiche la carte dans la fenetre SDL (seul les coordonnées x et y de la src est changé)
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     * @param posJ Complex: sert pour calculer l'affichage par rapport au joueur.
     */
    void drawMap(SDL_Renderer *rend, const Complex &posJ);
};

#endif
