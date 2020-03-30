#include "Arme.h"

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
    Incx=tx-x;
    Incy=ty-y;
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

bool Arme::getPop()const{
    return pop;
}

void Arme::bougeBalle(const Terrain & t,int fanx,int fany,bool & fanb, int fan2x,int fan2y,bool & fan2b,const int & pacx,const int & pacy){
    if(t.estPositionPersoValide(tx+Incx,ty+Incy) && pop){
    tx+=Incx;
    ty+=Incy;}
    else{
        pop=false;
        tx=pacx;
        ty=pacy;
        setInc(Savx,Savy);
    }
    if(tx==fanx && ty==fany && fanb){
        pop=false;
        fanb=false;
        tx=pacx;
        ty=pacy;
        setInc(Savx,Savy);}
    if(tx==fan2x && ty==fan2y && fan2b){
        pop=false;
        fan2b=false;
        tx=pacx;
        ty=pacy;
        setInc(Savx,Savy);}
}