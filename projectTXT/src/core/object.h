#ifndef _OBJECT_H
#define _OBJECT_H

#include "Personnage.h"
#include "Terrain.h"

class Object {

protected :

int x, y ;
bool pop ;
Terrain ter ;

public:

Object();
bool verifPos(int x, int y, Personnage p);

};

#endif