#include "soin.h"

soin::soin()
{
    pdv = 100 ;
}

int soin::getPointDeVie()
{
    return pdv ;
}

int soin::getPosX()
{
    return posX;
}

int soin::getPosY()
{
    return posY;
}

void soin::setPos(int x, int y)
{
    posX = x;
    posY = y;
}

void soin::setTexture(SDL_Renderer *ren, int x, int y)
{
    s->setTexture(s->loadTexture("Data/kitDeSoin.png",ren));
    s->renderTexture(s->getTexture(),ren,x,y);
}

void soin::setPointDeVie(float nbv)
{
    pdv = nbv ;
}

soin::~soin(){}