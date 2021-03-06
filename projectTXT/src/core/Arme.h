#ifndef _ARME_H
#define _ARME_H


#include "Terrain.h"
#include "iostream"

class Fantome;
class Pacman;
class Arme{

protected:

int tx,ty;
int Incx,Incy;
int Savx,Savy;
bool pop;

public:
    Arme();

    void setPos(int x,int y);
    void setInc(int x,int y);
    void setSav(int x,int y);
    int getPosX()const;
    int getPosY()const;
    int getIncX()const;
    int getIncY()const;
    int getSavX()const;
    int getSavY()const;
    void setPop(bool b);
    bool getPop()const;

    void bougeBalle(const Terrain & t,Fantome fan[],int size,const int & pacx,const int & pacy);

};

#endif
