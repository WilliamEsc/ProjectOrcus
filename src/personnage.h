#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "complex.h"
#include "texture.h"
#include "def.h"


class personnage{
protected:

    bool pop;
    Complex* pos;
    Complex* vit;
    double angle;
    int pdv;
    texture* persos=new texture;


public:

    personnage();
    personnage(const float & x,const float & y);
    ~personnage();

    void setPdv(const int & n);
    void setPop(const bool b);
    void setTexture(SDL_Renderer* renderer,const char* file);
    void setDest(const float & x,const float & y);

    texture* getTexture()const;
    SDL_Rect* getRect() const;
    Complex* getPos()const;
    Complex* getVit()const;
    double getAngle()const;
    int getPdv()const;
    bool getPop()const;

    void drawPersonnage(SDL_Renderer* renderer);
    bool Collision(const Complex & pos,const int* collision) const;
    void getHit(const int & dmg);
};




#endif
