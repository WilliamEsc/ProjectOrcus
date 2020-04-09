#ifndef BALLE_H
#define BALLE_H

#include "objet.h"

class balle : public objet
{
    private: 

    public: 

    balle();
    
    ~balle();

    void tireBalle(int x, int y, SDL_Renderer *ren);
};

#endif