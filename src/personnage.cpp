#include "personnage.h"

personnage::personnage(){
    pos=new Complex(20,20);
    vit=new Complex(20,21);
    angle=0;
    destRect.h=128;
    destRect.w=128;
    destRect.x=pos->getComplexX();
    destRect.y=pos->getComplexY();
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

void personnage::setTexture(SDL_Renderer* renderer,SDL_Surface* surface){
    Pion=SDL_CreateTextureFromSurface(renderer,surface);
}

void personnage::ajoutAngle(double deg){
    Complex e(cos(-deg*3.14/180),sin(-deg*3.14/180));
    *vit=((*vit-*pos)*e)+*pos;
    angle+=deg;
}

void personnage::deplace(float f,double ang){
    ajoutAngle(ang);
    Complex tr=*vit-*pos;
    *pos=*pos-tr*f;
    *vit=tr+*pos;
}

void personnage::update(){
    destRect.x=pos->getComplexX();
    destRect.y=pos->getComplexY();
}