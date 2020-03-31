#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "complex.h"
#include "def.h"

class personnage{
private:
    Complex* pos;
    Complex* vit;
    double angle;
    int pdv;
    SDL_Texture* Pion;
    SDL_Rect destRect;

public:

    personnage();
    ~personnage();
    SDL_Texture* getTexture()const;
    SDL_Rect* getRect();
    Complex* getPos()const;
    Complex* getVit()const;
    double getAngle()const;
    int getPdv()const;
    void setPdv(int n);
    void setTexture(SDL_Renderer* renderer,SDL_Surface* surface);
    void ajoutAngle(double deg);
    void deplace(float f,double ang);
    void update();
};




#endif
