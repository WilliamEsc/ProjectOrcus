#include "personnage.h"

personnage::personnage()
{
    pos = new Complex(20, 20);
    vit = new Complex(20, 19);
    pop = true;
    angle = 0;
    pdv = 100;
    persos->setDest(0, 0, 64, 64);
}

personnage::personnage(const float &x, const float &y)
{
    pos = new Complex(x, y);
    vit = new Complex(x, y - 1);
    pop = true;
    angle = 0;
    pdv = 100;
    persos->setDest(0, 0, 64, 64);
}

personnage::~personnage()
{
    delete pos;
    delete vit;
    delete persos;
    persos = NULL;
    pos = NULL;
    vit = NULL;
}

void personnage::setTexture(SDL_Renderer *renderer, const char *file)
{
    persos->setFileName(file);
    persos->setTexture(persos->loadTexture(renderer));
}

texture *personnage::getTexture() const
{
    return persos;
}

void personnage::setDest(const float &x, const float &y)
{
    persos->setDest(x, y);
}

SDL_Rect personnage::getRect() const
{
    return persos->getDest();
}

Complex *personnage::getPos() const
{
    return pos;
}

Complex *personnage::getVit() const
{
    return vit;
}

double personnage::getAngle() const
{
    return angle;
}

int personnage::getPdv() const
{
    return pdv;
}

void personnage::setPdv(const int &n)
{
    pdv = n;
}

void personnage::drawPersonnage(SDL_Renderer *renderer)
{
    persos->renderTextureEx(renderer, -angle);
}

void personnage::getHit(const int &dmg)
{
    pdv -= dmg;
    if (pdv <= 0)
    {
        pop = false;
    }
}

void personnage::setPop(const bool b)
{
    pop = b;
}

bool personnage::getPop() const
{
    return pop;
}