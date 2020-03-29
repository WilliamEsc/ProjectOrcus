/**
@brief Module gérant un fantome
@file Fantome.h
@date 2017/01/17
*/

#ifndef _FANTOME_H
#define _FANTOME_H

#include "Terrain.h"
#include "Personnage.h"
#include "Pacman.h"


/**
@brief Un fantome = sa position 2D
*/
class Fantome : public Personnage {

protected :

	//int x,y;
	int dir;

public:

    Fantome();
    Fantome(int x, int y);

    void versPacman (const Terrain & t, const Pacman & p);
    void bougeAuto (const Terrain & t);

};

#endif
