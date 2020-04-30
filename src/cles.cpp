#include "cles.h"

cles::cles(float x,float y): objet(x,y)
{

}

cles::~cles()
{

}

void cles::ouvrePorte(SDL_Renderer* renderer,map & m)
{
    m.setMapPng(renderer,"Data/carte2-2.png");
    m.setCollision(79,48,-1);
    for(int i=0;i<5;i++)
    {
        m.setCollision(82,87+i,-1);
    }
    pop=false;
}