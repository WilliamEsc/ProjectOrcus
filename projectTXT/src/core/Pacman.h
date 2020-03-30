/**
@brief Module g�rant un Pacman

@file Pacman.h
@date 2017/01/17
*/

#ifndef _PACMAN_H
#define _PACMAN_H

#include "Arme.h"
#include "Personnage.h"
#include <cassert>
#include "iostream"

/**
@brief Un Pacman = sa position 2D
*/

class Fantome;
class Pacman : public Personnage {

protected :

// int x,y ;
Arme a;
int pdv ;

public:

    Pacman ();
    void setPdv(int p);
    int getPdv()const;
    Arme getArme() const;
    char *affichePdv(char *str)const;
    void tir(const Terrain & t);

    void updateBalle(const Terrain & t,Fantome fan[],int nbF);
    // void updateBalle(const Terrain & t,Fantome& fan,Fantome& fan2);
    void canonB();
    void canonG();
    void canonH();
    void canonD();

     void testRegression() ;
};

#endif
