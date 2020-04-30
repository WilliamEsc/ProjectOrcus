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
    objet(float x,float y);

    bool getPop()const;
    void setPop(bool b);

    void setPos(float x,float y);
    Complex getPos() const;
    float getPosX() const;
    float getPosY() const;

    texture* getTexture()const;
    void setTexture(SDL_Renderer *ren, const char* file);
    void drawObjet(SDL_Renderer *ren) const;

    SDL_Rect* getRect();

    void setFile(const char* file);
    const char* getFileName();

    ~objet();
};
#endif 