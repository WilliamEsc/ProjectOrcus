#ifndef OBJET_H
#define OBJET_H

#include "def.h"
#include "texture.h"

class objet
{
protected:
    bool pop;
    texture *o = new texture();
    float posX;
    float posY;
    const char* name;

public:

    objet();

    bool getPop()const;
    void setPop(bool b);

    float getPosX();
    float getPosY();
    void setPos(float x, float y);

    // SDL_Texture *getTexture();
    void setTexture(SDL_Renderer *ren, const char* file, float x, float y);

    SDL_Rect* getRect() ;

    void setFile(const char* file);
    const char* getFileName();

    ~objet();
};
#endif 