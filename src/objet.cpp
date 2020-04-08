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
    s->setTexture(s->loadTexture(file,ren));
    s->renderTexture(s->getTexture(),ren,s->getRect2());
}

SDL_Rect* objet::getRect()
{
    return s->getRect();
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