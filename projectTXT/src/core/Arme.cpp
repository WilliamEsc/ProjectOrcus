#include "Arme.h"

Arme::Arme(){
    pop=false;
}

void Arme::setPos(int x,int y){
    tx=x;
    ty=y;
}

void Arme::setInc(int x,int y){
    Incx=tx-x;
    Incy=ty-y;
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

bool Arme::getPop()const{
    return pop;
}

void Arme::bougeBalle(const Terrain & t,int fanx,int fany,bool & fanb, int fan2x,int fan2y,bool & fan2b){
    if(t.estPositionPersoValide(tx+Incx,ty+Incy) && pop){
    tx+=Incx;
    ty+=Incy;}
    else{
        pop=false;
    }
    if(tx==fanx && ty==fany){
        pop=false;
        fanb=false;}
    if(tx==fan2x && ty==fan2y){
        pop=false;
        fan2b=false;}
}