#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "complex.h"
#include "texture.h"
#include "def.h"


class personnage{
protected:
    Complex* pos;
    Complex* vit;
    double angle;
    int pdv;
    texture* persos=new texture;


public:

    personnage();
    personnage(const float & x,const float & y);
    ~personnage();
    texture* getTexture()const;
    void setDest(const float & x,const float & y);
    SDL_Rect* getRect() const;
    Complex* getPos()const;
    Complex* getVit()const;
    double getAngle()const;
    int getPdv()const;
    void setPdv(const int & n);
    void setTexture(SDL_Renderer* renderer,const char* file);
    void drawPersonnage(SDL_Renderer* renderer);
    bool Collision(const Complex & pos,const int collision[][124]) const;
    bool Collision(const Complex & pos,const int* collision) const;
};




#endif
