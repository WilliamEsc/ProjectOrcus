#ifndef HERO_H
#define HERO_H

#include "complex.h"
#include "arme.h"
#include "personnage.h"

class hero: public personnage
{
    private:

    SDL_Rect barrePdv;
    arme* wep=new arme;

    public:

    hero();
    ~hero();

    void setArme(const arme & arme);
    arme* getArme()const;

    void setBarrePdv(const float & x,const float & y,const float & h,const float & w);
    SDL_Rect getBarrePdv()const;

    void tir(SDL_Renderer *render);
    void ajoutAngle(const double & deg);
    void deplace(const float & f,const double & ang,const int* collision);
    bool Hit(const Complex &pos);
    bool estArrive();
    void drawPersonnage(SDL_Renderer* renderer);
    void setTexture(SDL_Renderer *renderer, const char *file,const char *file2);
};

#endif 