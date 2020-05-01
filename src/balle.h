#ifndef BALLE_H
#define BALLE_H

#include "objet.h"
#include "personnage.h"

class balle : public objet
{
private:

    Complex* posInit;
    Complex* vit;
    double angle;
    float f ;

public:
    balle(const float & fl);

    ~balle();

    Complex* getVit() const;
    void setVit(Complex* j);

    double getAngle()const;
    void setAngle(double angle);

    float getForce()const;
    void setForce(const float & fl);

    float getDestRectX();
    float getDestRectY();

    void setDestRectX(float x);
    void setDestRectY(float y);   

    bool getFire();
    void Fire(const Complex &pos,const Complex &vit);
    void setFire(bool s); 

    void updateBalle(SDL_Renderer* ren);
    void renderBalle(SDL_Renderer *ren,const Complex & posJ,SDL_Texture* texture);

    bool Hit(const Complex & pos);
};

#endif
