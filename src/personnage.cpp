#include "personnage.h"

personnage::personnage(){
    pos=new Complex(20,20);
    vit=new Complex(20,19);
    angle=0;
    pdv=100;
    persos->setDest(0,0,64,64);
}

personnage::personnage(const float & x,const float & y){
    pos=new Complex(x,y);
    vit=new Complex(x,y-1);
    angle=0;
    pdv=100;
    persos->setDest(0,0,64,64);
}

personnage::~personnage(){
    delete pos;
    delete vit;
    delete persos;
    persos=NULL;
    pos=NULL;
    vit=NULL;
}

void personnage::setTexture(SDL_Renderer* renderer,const char* file){
    persos->setFileName(file);
    persos->setTexture(persos->loadTexture(renderer));
}

texture* personnage::getTexture()const {
    return persos;
}

void personnage::setDest(const float & x,const float & y)
{
    persos->setDest(x,y);
}

SDL_Rect* personnage::getRect() const{
    return persos->getDest();
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

void personnage::setPdv(const int & n){
    pdv=n;
}

void personnage::drawPersonnage(SDL_Renderer* renderer)
{
    persos->renderTextureEx(renderer,-angle);
}

bool personnage::Collision(const Complex & postmp,const int collision[][124]) const
{
    for(int i=postmp.getComplexY()-1;i<postmp.getComplexY()+1;i++){
        for(int j=postmp.getComplexX()-1;j<postmp.getComplexX()+1;j++){
            if(collision[i][j]!=-1){
                if( (///en haut a gauche
                      (j<postmp.getComplexX()+0.25 && j+1>postmp.getComplexX()+0.25) &&
                      (i<postmp.getComplexY()+0.25 && i+1>postmp.getComplexY()+0.25)
                    ) ||
                    (///en bas a droite
                      (j<postmp.getComplexX()+0.75 && j+1>postmp.getComplexX()+0.75) &&
                      (i<postmp.getComplexY()+0.75 && i+1>postmp.getComplexY()+0.75)
                    ) ||
                    (///en haut a droite
                      (j<postmp.getComplexX()+0.75 && j+1>postmp.getComplexX()+0.75) &&
                      (i<postmp.getComplexY()+0.25 && i+1>postmp.getComplexY()+0.25)
                    ) ||
                    (
                      (j<postmp.getComplexX()+0.25 && j+1>postmp.getComplexX()+0.25) &&
                      (i<postmp.getComplexY()+0.75 && i+1>postmp.getComplexY()+0.75)
                    )
                ){
                    return true;
                }
            }
        }
    }
    return false;
}

bool personnage::Collision(const Complex & postmp,const int* collision) const
{
    for(int i=postmp.getComplexY()-1;i<postmp.getComplexY()+1;i++){
        for(int j=postmp.getComplexX()-1;j<postmp.getComplexX()+1;j++){
            if(collision[(i*124)+j]!=-1){
                if( (///en haut a gauche
                      (j<postmp.getComplexX()+0.25 && j+1>postmp.getComplexX()+0.25) &&
                      (i<postmp.getComplexY()+0.25 && i+1>postmp.getComplexY()+0.25)
                    ) ||
                    (///en bas a droite
                      (j<postmp.getComplexX()+0.75 && j+1>postmp.getComplexX()+0.75) &&
                      (i<postmp.getComplexY()+0.75 && i+1>postmp.getComplexY()+0.75)
                    ) ||
                    (///en haut a droite
                      (j<postmp.getComplexX()+0.75 && j+1>postmp.getComplexX()+0.75) &&
                      (i<postmp.getComplexY()+0.25 && i+1>postmp.getComplexY()+0.25)
                    ) ||
                    (
                      (j<postmp.getComplexX()+0.25 && j+1>postmp.getComplexX()+0.25) &&
                      (i<postmp.getComplexY()+0.75 && i+1>postmp.getComplexY()+0.75)
                    )
                ){
                    return true;
                }
            }
        }
    }
    return false;
}