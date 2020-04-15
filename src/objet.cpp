#include "objet.h"

objet::objet()
{
    pop =true;
    posX = 20 ;
    posY = 20 ;
    src.w = 41 ;
    src.h = 40 ;
    src.x = 0 ;
    src.y = 0 ;
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

void objet::setTexture(SDL_Renderer *ren, const char* file)
{
    o->setTexture(o->loadTexture(file,ren));
}

void objet::renderTexture(SDL_Renderer *ren)
{
      o->renderTexture(o->getTexture(),ren,src, o->getRect2());
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