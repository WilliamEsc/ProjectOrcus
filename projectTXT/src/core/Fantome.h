/**
@brief Module gérant un fantome
@file Fantome.h
@date 2017/01/17
*/

#ifndef _FANTOME_H
#define _FANTOME_H

#include <stdlib.h>

#include "Pacman.h"
#include "Terrain.h"
#include "Personnage.h"



/**
@brief Un fantome = sa position 2D
*/
class Pacman;
class Fantome : public Personnage {

protected :

	//int x,y;
	int dir;
    bool pop;

public:

    Fantome();
    Fantome(int x, int y);

    void setPop(bool b);
    bool getPop()const;
    void versPacman (const Terrain & t, const Pacman & p);
    void bougeAuto (const Terrain & t);

};

#endif
