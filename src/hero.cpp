#include "hero.h"

hero::hero() : personnage()
{
    persos->setDest((SCREEN_WIDTH - 64) / 2, (SCREEN_HEIGHT - 64) / 2);
    barrePdv.x = persos->getDestX();
    barrePdv.y = persos->getDestY() - 10;
    barrePdv.h = 10;
    barrePdv.w = persos->getDest().w;
}

hero::~hero()
{
    delete wep;
}

void hero::setArme(const arme &arme)
{
    *wep = arme;
}

arme *hero::getArme() const
{
    return wep;
}

void hero::setBarrePdv(const float &x, const float &y, const float &h, const float &w)
{
    barrePdv.x = x;
    barrePdv.y = y;
    barrePdv.h = h;
    barrePdv.w = w;
}

SDL_Rect hero::getBarrePdv() const
{
    return barrePdv;
}

void hero::ajoutAngle(const double &deg)
{
    Complex e(cos(-deg * 3.14 / 180), sin(-deg * 3.14 / 180));
    *vit = ((*vit - *pos) * e) + *pos;
    angle += deg;
}

void hero::deplace(const float &f, const double &ang, const int *collision)
{
    ajoutAngle(ang);
    Complex postmp = *pos;
    Complex tr = *vit - postmp;
    postmp = postmp - tr * f;
    if (!Collision(postmp, collision))
    {
        pos->setComplexX(postmp.getComplexX());
        pos->setComplexY(postmp.getComplexY());
        vit->setComplexX(postmp.getComplexX() + tr.getComplexX());
        vit->setComplexY(postmp.getComplexY() + tr.getComplexY());
    }
}

bool hero::estArrive()
{
    return (pos->getComplexX() >= 83 && pos->getComplexX() <= 85 && pos->getComplexY() >= 107 && pos->getComplexX() <= 110);
}

void hero::drawPersonnage(SDL_Renderer *ren)
{
    personnage::drawPersonnage(ren);
    wep->rendering(ren, *pos);
    float vert = 255 * (((float)pdv) / 100);
    float rouge = 255 * (1 - ((float)pdv) / 100);
    barrePdv.w = persos->getDest().w * (((float)pdv) / 100);
    SDL_SetRenderDrawColor(ren, rouge, vert, 0, 0);
    SDL_RenderFillRect(ren, &barrePdv);
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
}

void hero::tir()
{
    wep->tir(*pos, *vit, angle);
}

bool hero::Hit(const Complex &pos)
{
    return wep->Hit(pos);
}

void hero::setTexture(SDL_Renderer *ren, const char *file, const char *file2)
{
    personnage::setTexture(ren, file);
    wep->setTexture(ren, file2);
}