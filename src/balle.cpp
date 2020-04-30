#include "balle.h"

balle ::balle() : objet()
{
    angle = 0;
    f = 0.05;
    s->setDest((SCREEN_WIDTH - 64) / 2,(SCREEN_HEIGHT - 64) / 2,22,22);
    posInit= new Complex(0, 0);
    vit = new Complex(0, 0);
    pop= false;
}

balle ::~balle() {}

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
    s->setDest(x,s->getDestY());
}

void balle ::setDestRectY(float y)
{
    s->setDest(s->getDestX(),y);
}

bool balle ::getFire()
{
    return pop;
}

void balle :: setFire(bool s)
{
    pop = s ;
}

void balle ::Fire(const personnage & j)
{
    if(!pop)
    {
    pop = true;
    posObj = *j.getPos() ;
    *posInit = *j.getPos() ;
    std::cout << "post = " << getPosX() << ", " << getPosY() << std::endl;
    *vit = *j.getVit();
    std::cout << " vit= " << getVit()->getComplexX() << ", " << getVit()->getComplexY() << std::endl;
    }
}

void balle ::LoadBalle(SDL_Renderer *ren)
{
    setTexture(ren, "Data/balle.png");
}

void balle::updateBalle(SDL_Renderer *ren)
{
    if (pop)
    {
        Complex tr=*vit-posObj;
        posObj=posObj+tr*f;
        *vit=posObj+tr;
    }
    if((posObj-*posInit).norme()>5)
        pop=false;
}

void balle :: renderBalle(SDL_Renderer *ren,Complex posJ)
{
    if(pop)
     {
        s->setDest((posObj.getComplexX() - posJ.getComplexX() + 6) * 64,(posObj.getComplexY() - posJ.getComplexY() + 6) * 64);
        s->renderTextureNoSrc(ren);
    }
}
