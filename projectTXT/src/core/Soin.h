#ifndef _SOIN_H
#define _SOIN_H

#include "object.h"
#include "Pacman.h"

class Soin : public Object
{
    protected :

    int heal ;

    public:

    Soin();
    void soignerPac(Pacman &p) ;
    void hitPac(Pacman &p) ;

};

#endif