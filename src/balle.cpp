#include "balle.h"

balle ::balle(const float &fl) : objet()
{
    angle = 0;
    f = fl;
    s->setDest((SCREEN_WIDTH - 64) / 2, (SCREEN_HEIGHT - 64) / 2, 16, 16);
    posInit = new Complex(0, 0);
    vit = new Complex(0, 0);
    pop = true;
}

balle ::~balle()
{
    delete posInit;
    delete vit;
}

Complex *balle::getVit() const
{
    return vit;
}

void balle ::setVit(Complex *j)
{
    vit = j;
}

double balle::getAngle() const
{
    return angle;
}

void balle ::setAngle(double ang)
{
    angle = ang;
}

float balle ::getDestRectX()
{
    return s->getDestX();
}

float balle ::getDestRectY()
{
    return s->getDestY();
}

void balle ::setDestRectX(float x)
{
    s->setDest(x, s->getDestY());
}

float balle::getForce() const
{
    return f;
}
void balle::setForce(const float &fl)
{
    f = fl;
}

void balle ::setDestRectY(float y)
{
    s->setDest(s->getDestX(), y);
}

void balle ::Fire(const Complex &posJ, const Complex &vitJ)
{
    posObj.setComplexXY(posJ.getComplexX() + 0.5, posJ.getComplexY() + 0.5);
    posInit->setComplexXY(posJ.getComplexX() + 0.5, posJ.getComplexY() + 0.5);
    vit->setComplexXY(vitJ.getComplexX() + 0.5, vitJ.getComplexY() + 0.5);
}

void balle::updateBalle(SDL_Renderer *ren)
{
    if (pop)
    {
        Complex tr = *vit - posObj;
        posObj = posObj + tr * f;
        *vit = posObj + tr;
    }
    if ((posObj - *posInit).norme() > 5)
        pop = false;
}

void balle ::renderBalle(SDL_Renderer *ren, const Complex &posJ, SDL_Texture *texture)
{
    s->setDest((posObj.getComplexX() - posJ.getComplexX() + 6) * 64, (posObj.getComplexY() - posJ.getComplexY() + 5) * 64);
    s->renderTextureNoSrc(ren, texture);
}

bool balle::Hit(const Complex &pos)
{
    Complex posBalle(posObj.getComplexX() + 0.125, posObj.getComplexY() + 0.125);
    Complex posCible(pos.getComplexX() + 0.5, pos.getComplexY() + 0.5);
    if ((posBalle - posCible).norme() < 0.625)
    {
        pop = false;
        return true;
    }
    return false;
}