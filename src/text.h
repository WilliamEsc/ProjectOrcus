#ifndef TEXT_H
#define TEXT_H

#include "def.h"
#include "texture.h"

class text
{

private:
    const char *texte;
    SDL_Color color;
    TTF_Font *font;
    float posX;
    float posY;
    texture *t = new texture();

public:
    text();
    ~text();

    const char *getTexte();
    SDL_Color getColor();
    TTF_Font *getFont();
    float getPosX();
    float getPosY();

    void setTexte(const char *t1, SDL_Renderer *ren, float x, float y);
    void setColor(SDL_Color c);
    void setFont(TTF_Font *f);
    void setPosText(float x, float y);
};

#endif
