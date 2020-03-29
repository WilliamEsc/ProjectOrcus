#include "Soin.h"

Soin::Soin()
{
    x = 10 ;
    y = 20 ;
    heal = 10 ;
}

void Soin :: soignerPac(Pacman &p)
{
    p.setPdv(p.getPdv()+heal) ;
}

void Soin :: hitPac(Pacman &p) 
{
    p.setPdv(p.getPdv()-5);
}