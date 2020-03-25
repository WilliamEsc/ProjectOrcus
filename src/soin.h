#ifndef SOIN_H
#define SOIN_H

#include "def.h"
#include "texture.h"

class soin
{
private:
    bool pop;
    texture *s = new texture();
    float posX;
    float posY;

public:

    soin();

    bool getPop()const;
    void setPop(bool b);
    void setPointDeVie(float nbv);

    float getPosX();
    float getPosY();
    void setPos(float x, float y);

    // SDL_Texture *getTexture();
    void setTexture(SDL_Renderer *ren, float x, float y);

    SDL_Rect* getRect() ;

    ~soin();
};
#endif 
