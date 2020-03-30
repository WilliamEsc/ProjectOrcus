#ifndef _ARME_H
#define _ARME_H


#include "Terrain.h"
#include "iostream"

class Arme{

protected:

int tx,ty;
int Incx,Incy;
bool pop;

public:
    Arme();

    void setPos(int x,int y);
    void setInc(int x,int y);
    int getPosX()const;
    int getPosY()const;
    int getIncX()const;
    int getIncY()const;
    void setPop(bool b);
    bool getPop()const;

    void bougeBalle(const Terrain & t,int fanx,int fany,bool& fanb,int fan2x,int fan2y,bool& fan2b);

};

#endif
