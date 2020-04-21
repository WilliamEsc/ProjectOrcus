#include "personnage.h"

personnage::personnage(){
    pos=new Complex(20,20);
    vit=new Complex(20,19);
    angle=0;
    pdv=100;
    destRect.h=64;
    destRect.w=64;
    destRect.x=(SCREEN_WIDTH-64)/2;
    destRect.y=(SCREEN_HEIGHT-64)/2;
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

void personnage::deplace(float f,double ang,int collision[124][124],SDL_Renderer* renderer){
    ajoutAngle(ang);
    Complex postmp=*pos;
    Complex tr=*vit-postmp;
    postmp=postmp-tr*f;
    bool collide=false;
    for(int i=0;i<200;i++){
    bt[i]=false;}

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
                    collide=true;
                }
            }
        }
    }
    
    // printf("tmp x %f \n", postmp.getComplexX());
    // printf("tmp y %f \n", postmp.getComplexY());
    // printf("tr x %f \n",tr.getComplexX());
    // printf("tr y %f \n",tr.getComplexY());
    if(!collide){
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
