#include "objet.h"

objet::objet()
{
    pop =true;
}

bool objet::getPop() const
{
    return pop ;
}

void objet::setPop(bool b)
{
    pop = b ;
}

float objet::getPosX()
{
    return posX;
}

float objet::getPosY()
{
    return posY;
}

void objet::setPos(float x, float y)
{
    posX = x;
    posY = y;
}

void objet::setTexture(SDL_Renderer *ren, const char* file, float x, float y)
{
    o->setTexture(o->loadTexture(file,ren));
    o->renderTexture(o->getTexture(),ren,o->getRect2(),x,y);
}

SDL_Rect* objet::getRect()
{
    return o->getRect();
}

void objet :: setFile(const char* file)
{
    name = file ;
}

const char* objet :: getFileName()
{
    return name ;
}

objet::~objet(){}