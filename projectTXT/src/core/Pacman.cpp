#include "Pacman.h"

Pacman::Pacman () : Personnage(){
 	x = 1 ;
	y = 2 ;	
	pdv = 50 ;
	a.setPos(x,y);
	a.setInc(0,1);
	a.setSav(0,1);
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
	if(t.estPositionPersoValide(a.getPosX(),a.getPosY()) && !a.getPop())
		a.setPop(true);
}

void Pacman::updateBalle(const Terrain & t,Fantome& fan,Fantome& fan2){
	bool fanb=fan.getPop();
	bool fan2b=fan2.getPop();
	if(a.getPop()){
		a.bougeBalle(t,fan.getX(),fan.getY(),fanb,fan2.getX(),fan2.getY(),fan2b,x,y);
	}
	fan.setPop(fanb);
	fan2.setPop(fan2b);
}

void Pacman::canonG(){
	if(!a.getPop()){
		a.setPos(x,y);
		a.setInc(-1,0);
		a.setSav(-1,0);}
	else{
		a.setSav(-1,0);
	}
}

void Pacman::canonD(){
	if(!a.getPop()){
	a.setPos(x,y);
	a.setInc(1,0);
	a.setSav(1,0);}
	else{
		a.setSav(1,0);
	}
}

void Pacman::canonH(){
	if(!a.getPop()){
	a.setPos(x,y);
	a.setInc(0,-1);
	a.setSav(0,-1);}
	else{
		a.setSav(0,-1);
	}
}

void Pacman::canonB(){
	if(!a.getPop()){
	a.setPos(x,y);
	a.setInc(0,1);
	a.setSav(0,1);}
	else{
		a.setSav(0,1);
	}
}

char* Pacman::affichePdv(char *str)const
{
	int temp = pdv;
	sprintf(str, "%d", temp);
	return str ;
}

 void Pacman::testRegression(){
	
	int i=1;
	
	assert(x==1 && y==2 && pdv==50 && a.getPosX()==x && a.getPosY()==y && a.getIncX()==0 && a.getIncY()==1 && !a.getPop());
	std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;

	setPdv(99);
	assert(pdv==99);
	std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;

	Arme b=getArme();

	assert(b.getPosX()==a.getPosX() && b.getPosY()==a.getPosY() && b.getIncX()==a.getIncX() && b.getIncY()==a.getIncY() && !b.getPop());
	std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;
 }


