/**
@brief Module g�rant un Jeu (de Pacman)

@file Jeu.h
@date 2017/01/17
*/

#ifndef _JEU_H
#define _JEU_H

#include <string>

#include "Pacman.h"
#include "Terrain.h"
#include "Fantome.h"
#include "Soin.h"


/**
@brief Un jeu (de pacman) = un terrain et un pacman
*/
class Jeu {

private :

	Terrain ter;
	Pacman pac;
	Fantome fan;
    Fantome fan2;
    Soin s ;

public :

    Jeu ();

    Terrain& getTerrain ();
    Pacman& getPacman ();

    const Terrain& getConstTerrain () const;
    const Pacman& getConstPacman () const;
    const Fantome& getConstFantome () const;
    const Fantome& getConstFantome2 () const;
    const Soin& getConstSoin() const;

    int getNombreDeFantome() const;

    void actionsAutomatiques ();
    void actionClavier(const char touche); // rend vrai si mange une pastille, faux sinon

};

#endif
