#ifndef LOOT_H
#define LOOT_H

#include "def.h"
#include "hero.h"

class loot : public objet
{
private:
    int type;

public:
    loot(int t, float x, float y);
    ~loot();

    void setTexture(SDL_Renderer *ren);
    void looting(SDL_Renderer* renderer,hero & J);
};

#endif