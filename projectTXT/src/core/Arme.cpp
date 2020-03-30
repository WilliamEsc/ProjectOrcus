#include "Arme.h"
#include "Fantome.h"
#include "Pacman.h"

Arme::Arme(){
    pop=false;
    Savx=0;
    Savy=0;
}

void Arme::setPos(int x,int y){
    tx=x;
    ty=y;
}

void Arme::setInc(int x,int y){
    Incx=x;
    Incy=y;
}

void Arme::setSav(int x,int y){
    Savx=x;
    Savy=y;
}

void Arme::setPop(bool b){
    pop=b;
}

int Arme::getPosX()const{
    return tx;
}

int Arme::getPosY()const{
    return ty;
}

int Arme::getIncX()const{
    return Incx;
}

int Arme::getIncY()const{
    return Incy;
}

int Arme::getSavX()const{
    return Savx;
}

int Arme::getSavY()const{
    return Savy;
}

bool Arme::getPop()const{
    return pop;
}

void Arme::bougeBalle(const Terrain & t,Fantome fan[],int size,const int & pacx,const int & pacy){
    if(t.estPositionPersoValide(tx+Incx,ty+Incy) && pop){
    tx+=Incx;
    ty+=Incy;}
     else{
        pop=false;
        tx=pacx;
        ty=pacy;
        Incx=Savx;
        Incy=Savy;
    }
    for(int i=0;i<size;i++){
    if(tx==fan[i].getX() && ty==fan[i].getY() && fan[i].getPop()){
        pop=false;
        fan[i].setPop(false);
        tx=pacx;
        ty=pacy;
        Incx=Savx;
        Incy=Savy;}
    }
}