#ifndef BALLE_H
#define BALLE_H

#include "objet.h"
#include "personnage.h"

class balle : public objet
{
private:
    Complex* vit;
    double angle;
    float f ;
    SDL_Rect SrcRect;
    SDL_Rect DestRect;
    bool fire;

public:
    balle();

    ~balle();

    Complex* getPos() const;

    Complex* getVit() const;
    void setVit(Complex* j);

    double getAngle()const;
    void setAngle(double angle);

    float getDestRectX();
    float getDestRectY();

    void setDestRectX(float x);
    void setDestRectY(float y);   

    bool getFire();
    void setFire(bool s, personnage j);
    void setFire(bool s); 

    void updateBalle(SDL_Renderer* ren);
    void LoadBalle(SDL_Renderer* ren);
    void renderBalle(SDL_Renderer *ren);
};

#endif