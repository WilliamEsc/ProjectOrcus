#ifndef SOIN_H
#define SOIN_H

#include "objet.h"
#include "hero.h"

class soin : public objet
{
private:

public:

    soin(float x,float y);

    ~soin();

    void soignerPersos(hero & Joueur);
};
#endif 
