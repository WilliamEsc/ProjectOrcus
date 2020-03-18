#ifndef SOIN_H
#define SOIN_H

#include "def.h"
#include "texture.h"

class soin
{
private:
    float pdv; 
    texture *s = new texture();
    int posX;
    int posY;

public:

    soin();

    int getPointDeVie();
    void setPointDeVie(float nbv);

    int getPosX();
    int getPosY();
    void setPos(int x, int y);

    // SDL_Texture *getTexture();
    void setTexture(SDL_Renderer *ren, int x, int y);

    ~soin();
};
#endif 
