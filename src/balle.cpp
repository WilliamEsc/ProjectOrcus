#include "balle.h"

balle ::balle() 
{
    // setPos(400, 300);
    pos = j.getPos();
    vit = j.getVit();
    //o->setDest(j.getRect());
    angle = 0;
    tr = new Complex(0, 0);
    f = 1;
    b1 = false;
    b2 = false;
}

balle ::~balle() {}

Complex *balle::getPos() const
{
    return pos;
}

// float balle :: getPosX() const
// {
//     return pos.getComplexX();
// }

// float balle :: getPosY() const
// {
//     return pos.getComplexY();
// }

Complex *balle::getVit() const
{
    return vit;
}

double balle::getAngle() const
{
    return angle;
}

float balle ::getDistanceX()
{
    return distanceX;
}

float balle ::getDistanceY()
{
    return distanceY;
}

bool balle ::getB1()
{
    return b1;
}

bool balle ::getB2()
{
    return b2;
}

void balle::ajoutAngle(double deg)
{
    Complex e(cos(-deg * 3.14 / 180), sin(-deg * 3.14 / 180));
    *vit = ((*vit - *pos) * e) + *pos;
    angle += deg;
}

void balle ::tireBalle()
{
    float x;
    float y;

    //déplacement par rapport position écran

    *tr = (*vit - *pos);

    *pos = *pos + *tr * f;
    *vit = *vit + *tr * f;

    //déplacement par rapport position carte

    // x = o->getRectX() + tr->getComplexX() * f;
    // y = o->getRectY() + tr->getComplexY() * f;

    // o->setDest(x, y);
}

// o->renderTexture(o->getTexture(),ren,o->getRect2());

void balle::updateBalle()
{
}