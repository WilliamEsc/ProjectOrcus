#include "soin.h"

soin::soin()
{
    pop =true;
}

bool soin::getPop() const
{
    return pop ;
}

void soin::setPop(bool b)
{
    pop = b ;
}

float soin::getPosX()
{
    return posX;
}

float soin::getPosY()
{
    return posY;
}

void soin::setPos(float x, float y)
{
    posX = x;
    posY = y;
}

void soin::setTexture(SDL_Renderer *ren, float x, float y)
{
    s->setTexture(s->loadTexture("Data/kitDeSoin.png",ren));
    s->renderTexture(s->getTexture(),ren,s->getRect2(),x,y);
}

SDL_Rect* soin::getRect()
{
    return s->getRect();
}

soin::~soin(){}