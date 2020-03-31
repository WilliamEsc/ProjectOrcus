#include "personnage.h"

personnage::personnage(){
    pos=new Complex(20,20);
    vit=new Complex(20,21);
    angle=0;
    pdv=100;
    destRect.h=32;
    destRect.w=32;
    destRect.x=400;
    destRect.y=300;
}

personnage::~personnage(){
    delete pos;
    delete vit;
    pos=NULL;
    vit=NULL;
}

SDL_Texture* personnage::getTexture()const {
    return Pion;
}

SDL_Rect* personnage::getRect(){
    return &destRect;
}

Complex* personnage::getPos()const {
    return pos;
}

Complex* personnage::getVit()const{
    return vit;
}

double personnage::getAngle()const{
    return angle;
}

int personnage::getPdv()const{
    return pdv;
}

void personnage::setPdv(int n){
    pdv=n;
}

void personnage::setTexture(SDL_Renderer* renderer,SDL_Surface* surface){
    Pion=SDL_CreateTextureFromSurface(renderer,surface);
    if(Pion==NULL)
    {
        printf("erreur Pion");
        exit(EXIT_FAILURE);
    }
}

void personnage::ajoutAngle(double deg){
    Complex e(cos(-deg*3.14/180),sin(-deg*3.14/180));
    *vit=((*vit-*pos)*e)+*pos;
    angle+=deg;
}

void personnage::deplace(float f,double ang){
    ajoutAngle(ang);
    Complex postmp= *pos;
    Complex tr=*vit-postmp;
    postmp=postmp-tr*f;
    if(postmp.getComplexX()>0 && postmp.getComplexX()<=100){
    pos->setComplexX(postmp.getComplexX());
    vit->setComplexX(postmp.getComplexX()+tr.getComplexX());
    }
    else{
        vit->setComplexX(pos->getComplexX()+tr.getComplexX());
    }
    if(postmp.getComplexY()>=0 && postmp.getComplexY()<=100){
    pos->setComplexY(postmp.getComplexY());
    vit->setComplexY(postmp.getComplexY()+tr.getComplexY());
    }
    else{
        vit->setComplexY(pos->getComplexY()+tr.getComplexY());
    }
    printf("Position: ");
    printf("%f \n", pos->getComplexX());
    printf("%f \n", pos->getComplexY());
    printf("Vitesse: ");
    printf("%f \n", vit->getComplexX());
    printf("%f \n", vit->getComplexY());
}

void personnage::update(){

}