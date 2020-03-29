#ifndef _PERSONNAGE_H
#define _PERSONNAGE_H

#include "Terrain.h"

class Personnage {

protected:

    int x,y;

public:

    Personnage() ;
    
    int getX () const;
    int getY () const;

    int setX (int x) ;
    int setY (int y) ;

    void gauche (const Terrain & t);
    void droite (const Terrain & t);
    void haut (const Terrain & t);
    void bas (const Terrain & t);
    

};

#endif