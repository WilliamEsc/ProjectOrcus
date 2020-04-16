#include "objet.h"

objet::objet()
{
    posObj.setComplexXY(25,25);
    pop=true;
}

bool objet::getPop() const
{
    return pop ;
}

void objet::setPop(bool b)
{
    pop = b ;
}

void objet::setPos(float x,float y)
{
    posObj.setComplexXY(x,y);
}

float objet::getPosX() const
{
    return posObj.getComplexX();
}

float objet::getPosY() const
{
    return posObj.getComplexY();
}

void objet::setTexture(SDL_Renderer *ren, const char* file)
{
    s->setTexture(s->loadTexture(s->getFileName(),ren));
}

void objet::drawObjet(SDL_Renderer *ren, float x, float y) const
{
    s->renderTextureCplx(s->getTexture(),ren,x,y);
}

SDL_Rect* objet::getRect()
{
    return s->getRect();
}

void objet :: setFile(char* file)
{
    s->setFileName(file);
}

const char* objet :: getFileName()
{
    return s->getFileName() ;
}

objet::~objet(){}