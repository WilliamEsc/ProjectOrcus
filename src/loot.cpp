#include "loot.h"

loot::loot(const int & t,const float & x,const float & y) : objet(x, y)
{
    type = t;
}

loot::~loot()
{
}

void loot::setTexture(SDL_Renderer *ren)
{
    switch (type)
    {
    case 0:
        objet::setTexture(ren, "Data/ak47.png");
        break;

    default:
        break;
    }
}

void loot::looting(SDL_Renderer *ren, hero &J)
{
    switch (type)
    {
    case 0:
        J.getArme()->setCadence(0.1);
        J.getArme()->setForce(0.1);
        J.getArme()->setDegat(50);
        J.setTexture(ren, "Data/persos2.png", "Data/balle.png");
        break;

    default:
        break;
    }
}