#include "soin.h"

soin::soin(float x,float y): objet(x,y)
{

}

soin::~soin()
{

}

void soin::soignerPersos(hero & Joueur)
{
    Joueur.setPdv(Joueur.getPdv()+10);
    pop=false;
}