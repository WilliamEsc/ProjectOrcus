#ifndef CLES_H
#define CLES_H

#include "objet.h"
#include "map.h"

class cles : public objet
{
private:

public:

    cles(float x,float y);

    ~cles();

    void ouvrePorte(SDL_Renderer* renderer,map & m);
};
#endif 
