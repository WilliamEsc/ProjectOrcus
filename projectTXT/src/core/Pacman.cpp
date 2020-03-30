#include "Pacman.h"

Pacman::Pacman () : Personnage(){
 	x = 1 ;
	y = 2 ;	
	pdv = 50 ;
	a.setPos(x,y+1);
	a.setInc(x,y);
}

void Pacman::setPdv (int p)
{
	pdv = p ;
}

int Pacman::getPdv() const 
{
	return pdv;
}

Arme Pacman::getArme() const{
	return a;
}

void Pacman::tir(const Terrain & t) 
{
	if(!a.getPop()){
		a.setPop(true);
	}
}

void Pacman::updateBalle(const Terrain & t,Fantome& fan,Fantome& fan2){
	bool fanb=fan.getPop();
	bool fan2b=fan2.getPop();
	if(a.getPop()){
		a.bougeBalle(t,fan.getX(),fan.getY(),fanb,fan2.getX(),fan2.getY(),fan2b);
		if(!a.getPop())
			a.setPos(x+a.getIncX(),y+a.getIncY());
	}
	fan.setPop(fanb);
	fan2.setPop(fan2b);
}

void Pacman::canonG(){
	if(!a.getPop()){
		a.setPos(x-1,y);
		a.setInc(x,y);}
}

void Pacman::canonD(){
	if(!a.getPop()){
	a.setPos(x+1,y);
	a.setInc(x,y);}
}

void Pacman::canonH(){
	if(!a.getPop()){
	a.setPos(x,y-1);
	a.setInc(x,y);}
}

void Pacman::canonB(){
	if(!a.getPop()){
	a.setPos(x,y+1);
	a.setInc(x,y);}
}

char *Pacman::affichePdv(char *str)const
{
	int temp = pdv;
	sprintf(str, "%d", temp);
	return str ;
}




