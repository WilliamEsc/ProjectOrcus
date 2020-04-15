#ifndef OBJET_H
#define OBJET_H

#include "def.h"
#include "texture.h"

class objet
{
protected:
    
    texture *o = new texture();
    SDL_Rect src ;

    float posX;
    float posY;
    const char* name;
    bool pop;

public:

    objet();

    bool getPop()const;
    void setPop(bool b);

    float getPosX();
    float getPosY();
    void setPos(float x, float y);

    // SDL_Texture *getTexture();
    void setTexture(SDL_Renderer *ren, const char* file);
    void renderTexture(SDL_Renderer *ren);

    SDL_Rect* getRect() ;

    void setFile(const char* file);
    const char* getFileName();

    ~objet();
};
#endif 