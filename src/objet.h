#ifndef OBJET_H
#define OBJET_H

#include "def.h"
#include "texture.h"
#include "complex.h"

class objet
{
protected:
    bool pop;
    texture *s = new texture();
    Complex posObj;

public:

    objet();

    bool getPop()const;
    void setPop(bool b);

    void setPos(float x,float y);
    float getPosX() const;
    float getPosY() const;

    // SDL_Texture *getTexture();
    void setTexture(SDL_Renderer *ren, const char* file);
    void drawObjet(SDL_Renderer *ren, float x, float y) const;

    SDL_Rect* getRect();

    void setFile(char* file);
    const char* getFileName();

    ~objet();
};
#endif 