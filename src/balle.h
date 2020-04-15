#ifndef BALLE_H
#define BALLE_H

#include "objet.h"
#include "complex.h"
#include "personnage.h"

class balle : public objet
{
private:
    Complex* pos;
    Complex* vit;
    Complex* tr ;
    double angle;

    personnage j ;
    float f ;

    bool b1;
    bool b2; 
    float distanceX ;
    float distanceY ;

public:
    balle();

    ~balle();

    Complex* getPos() const;
    Complex* getVit() const;
    double getAngle()const;
    float getDistanceX();
    float getDistanceY();
    bool getB1();
    bool getB2();
    float getPosX()const;
    float getPosY()const;

    void ajoutAngle(double deg);

    void updateBalle();

    void tireBalle();
};

#endif