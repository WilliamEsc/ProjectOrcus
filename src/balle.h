#ifndef BALLE_H
#define BALLE_H

#include "objet.h"

class balle : public objet
{
private:
    Complex vit;
    double angle;
    float f ;
    SDL_Rect SrcRect;
    SDL_Rect DestRect;
    bool fire;

public:
    balle();

    ~balle();

    Complex* getPos() const;
    Complex getVit() const;
    double getAngle()const;
    void setAngle(double angle);

    float getDestRectX();
    float getDestRectY();

    void setDestRectX(float x);
    void setDestRectY(float y);   

    bool getFire();
    void setFire(bool s); 

    void updateBalle(SDL_Renderer* ren, bool state);

    void LoadBalle(SDL_Renderer* ren);
};

#endif