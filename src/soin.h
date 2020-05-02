#ifndef SOIN_H
#define SOIN_H

#include "objet.h"
#include "hero.h"

/*! \class balle
* \brief classe représentant les objets de soin
*/
class soin : public objet
{
private:
public:
    /**
     *\brief constructeur de la classe soin
     * @param x float: position x de l'objet soin.
     * @param y float: position y de l'objet soin.
     */
    soin(const float &x, const float &y);

    /**
     *\brief destructeur de la classe soin
     */
    ~soin();

    /**
     *\brief soigne le hero passer en parametre
     * @param Joueur hero: personnage qui va recevoir les effets du soin.
     */
    void soignerPersos(hero &Joueur);
};
#endif
