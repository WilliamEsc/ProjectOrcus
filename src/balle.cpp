#include "balle.h"

balle :: balle() 
{
    setPos(400,300);
}

balle :: ~balle() {}

void balle :: tireBalle(int x,int y,SDL_Renderer *ren)
{
    o->renderTexture(o->getTexture(),ren,o->getRect2(),x,y);
}