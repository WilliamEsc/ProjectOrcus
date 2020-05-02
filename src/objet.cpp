#include "objet.h"

objet::objet(const float &x,const float &y)
{
    posObj.setComplexXY(x, y);
    pop = true;
    s->setDest(0, 0, 64, 64);
}

objet::objet()
{
    posObj.setComplexXY(0, 0);
    pop = true;
    s->setDest(0, 0, 64, 64);
}

bool objet::getPop() const
{
    return pop;
}

void objet::setPop(bool b)
{
    pop = b;
}

void objet::setPos(const float &x,const float &y)
{
    posObj.setComplexXY(x, y);
}

Complex objet::getPos() const
{
    return posObj;
}

float objet::getPosX() const
{
    return posObj.getComplexX();
}

float objet::getPosY() const
{
    return posObj.getComplexY();
}

texture *objet::getTexture() const
{
    return s;
}

void objet::setTexture(SDL_Renderer *ren, const char *file)
{
    s->setFileName(file);
    s->setTexture(s->loadTexture(ren));
}

void objet::drawObjet(SDL_Renderer *ren) const
{
    s->renderTextureNoSrc(ren);
}

SDL_Rect objet::getRect()
{
    return s->getDest();
}

void objet ::setFile(const char *file)
{
    s->setFileName(file);
}

const char *objet ::getFileName()
{
    return s->getFileName();
}

objet::~objet()
{
    delete s;
    s = NULL;
}