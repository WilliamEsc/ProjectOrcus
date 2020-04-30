#include "hero.h"

hero::hero() : personnage()
{
    persos->setDest((SCREEN_WIDTH-64)/2,(SCREEN_HEIGHT-64)/2);
}

hero::~hero()
{

}

void hero::ajoutAngle(const double & deg){
    Complex e(cos(-deg*3.14/180),sin(-deg*3.14/180));
    *vit=((*vit-*pos)*e)+*pos;
    angle+=deg;
}

void hero::deplace(const float & f,const double & ang,const int* collision){
    ajoutAngle(ang);
    Complex postmp=*pos;
    Complex tr=*vit-postmp;
    postmp=postmp-tr*f;
    
    // printf("tmp x %f \n", postmp.getComplexX());
    // printf("tmp y %f \n", postmp.getComplexY());
    // printf("tr x %f \n",tr.getComplexX());
    // printf("tr y %f \n",tr.getComplexY());
    if(!Collision(postmp,collision)){
        pos->setComplexX(postmp.getComplexX());
        pos->setComplexY(postmp.getComplexY());
        vit->setComplexX(postmp.getComplexX()+tr.getComplexX());
        vit->setComplexY(postmp.getComplexY()+tr.getComplexY());
    }
    // printf("Position: ");
    // printf("pos x %f \n", pos->getComplexX());
    // printf("pos y %f \n", pos->getComplexY());
    // printf("Vitesse: ");
    // printf("%f \n", vit->getComplexX());
    // printf("%f \n", vit->getComplexY());
}