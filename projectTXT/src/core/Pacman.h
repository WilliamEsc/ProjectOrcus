/**
@brief Module g�rant un Pacman

@file Pacman.h
@date 2017/01/17
*/

#ifndef _PACMAN_H
#define _PACMAN_H

#include "Personnage.h"
#include "iostream"

/**
@brief Un Pacman = sa position 2D
*/
class Pacman : public Personnage {

protected :

// int x,y ;
int pdv ;

public:

    Pacman ();
    void setPdv(int p);
    int getPdv()const;
    char *affichePdv(char *str)const;
};

#endif
