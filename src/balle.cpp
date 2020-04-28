#include "balle.h"

balle ::balle() : objet()
{
    angle = 0;
    f = 0.005;
    DestRect.h = 22;
    DestRect.w = 22;
    DestRect.x = (SCREEN_WIDTH - 64) / 2;
    DestRect.y = (SCREEN_HEIGHT - 64) / 2;
    vit = new Complex(0, 0);
    fire = false;
}

balle ::~balle() {}

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
    return DestRect.x;
}

float balle ::getDestRectY()
{
    return DestRect.y;
}

void balle ::setDestRectX(float x)
{
    DestRect.x = x;
}

void balle ::setDestRectY(float y)
{
    DestRect.y = y;
}

bool balle ::getFire()
{
    return fire;
}

void balle :: setFire(bool s)
{
    fire = s ;
}

void balle ::setFire(bool s, personnage j)
{
    fire = s;

    posObj = *j.getPos() ;
    std::cout << "post = " << getPosX() << ", " << getPosY() << std::endl;
    vit = j.getVit();
    std::cout << " vit= " << getVit()->getComplexX() << ", " << getVit()->getComplexY() << std::endl;
}

void balle ::LoadBalle(SDL_Renderer *ren)
{
    setFile("Data/balle.png");
    setTexture(ren, getFileName());
}

void balle::updateBalle(SDL_Renderer *ren)
{
    if (fire)
    {
        // std::cout << "balle affiché" << std::endl;
        if ((DestRect.x >= SCREEN_WIDTH || DestRect.y >= SCREEN_HEIGHT) ||
            (DestRect.x <= 0 || DestRect.y <= 0))
        {
            setFire(false);
            DestRect.x = (SCREEN_WIDTH - 64) / 2;
            DestRect.y = (SCREEN_HEIGHT - 64) / 2;
        }
        else
        {
            std::cout << "angle = " << angle << std::endl;
            // Complex e(sin(angle * 3.14 / 180), cos(angle * 3.14 / 180));
            // std::cout << "e = " << e.getComplexX() << ", " << e.getComplexY() << std::endl;

            // std::cout << " vit= " << vit.getComplexX() << ", " << vit.getComplexY() << std::endl;
            // vit.setComplexXY(    
            //     ((vit.getComplexX() - post.getComplexX()) * e.getComplexX()) + post.getComplexX(),
            //     ((vit.getComplexY() - post.getComplexY()) * e.getComplexY()) + post.getComplexY());
            // //vit = ((vit - post) * e) + post;
            // std::cout << " vit= " << vit.getComplexX() << ", " << vit.getComplexY() << std::endl;

            Complex postmp = posObj;

            Complex tr = *vit - posObj;
            std::cout << " tr= " << tr.getComplexX() << ", " << tr.getComplexY() << std::endl;
    
            posObj = posObj + tr * f;

             std::cout << "post = " << getPosX() << ", " << getPosY() << std::endl;
            setDestRectX((getPosX() - postmp.getComplexX() + 6) * 64);
            setDestRectY((getPosY() - postmp.getComplexY() + 6) * 64);

            std::cout << "posBalle = " << getDestRectX() << ", " << getDestRectY() << std::endl;
            
            std::cout << " " << std::endl;
        }
    }
}

void balle :: renderBalle(SDL_Renderer *ren)
{
    s->renderTexture(s->getTexture(), ren, DestRect);
}