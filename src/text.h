#ifndef TEXT_H
#define TEXT_H

#include "def.h"
#include "texture.h"

class text
{

private:
    const char *texte ;
    SDL_Color color ;
    TTF_Font *font ;
    int posX;
    int posY;
    texture *t= new texture();

public:
    
    text();
    ~text();
     
    const char *getTexte();
    SDL_Color getColor();
    TTF_Font *getFont();
    int getPosX();
    int getPosY();

    void setTexte(const char *t1,SDL_Renderer *ren, int x, int y);
    void setColor(SDL_Color c);
    void setFont(TTF_Font *f);
    void setPosText(int x, int y);
};

#endif
    