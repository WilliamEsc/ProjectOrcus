#include "Pacman.h"
#include "Fantome.h"

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

void Pacman::updateBalle(const Terrain & t,Fantome fan[],int nbF){
	if(a.getPop()){
		a.bougeBalle(t,fan,nbF,x,y);
	}
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
	Terrain t;

	int i=1;
	
	assert(x==1 && y==2 && pdv==50 && a.getPosX()==x && a.getPosY()==y && a.getIncX()==0 && a.getIncY()==1 && !a.getPop());
	std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;

	bas(t);
	canonB();
	assert(x==1 && y==3 && a.getPosX()==x && a.getPosY()==y);
	std::cout << "test " << i << " reussi" << std::endl ;
	std::cout << "descend! " << std::endl ;
    i++ ;


	setPdv(99);
	assert(pdv==99);
	std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;

	Arme b=getArme();

	assert(b.getPosX()==a.getPosX() && b.getPosY()==a.getPosY() && b.getIncX()==a.getIncX() && b.getIncY()==a.getIncY() && !b.getPop());
	std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;

	Fantome fan[3];
	fan[0].setX(1);
	fan[0].setY(4);
	fan[1].setX(2);
	fan[1].setY(3);
	fan[2].setX(3);
	fan[2].setY(3);

	tir(t);
	assert(fan[0].getPop() && fan[1].getPop() && fan[2].getPop() && a.getPop());
	std::cout << "test " << i << " reussi" << std::endl ;
	std::cout << "tir,balle active,aucun update de la balle,tous fantome vivant"<< std::endl;
    i++ ;


	updateBalle(t,fan,3);
	assert(!fan[0].getPop() && fan[1].getPop() && fan[2].getPop() && !a.getPop());
	std::cout << "test " << i << " reussi" << std::endl ;
	std::cout << "update de la balle,fan1 mort, fan2 vivant,fan3 vivant, balle inactive"<< std::endl;
    i++ ;

	canonD();
	assert(!fan[0].getPop() && fan[1].getPop() && fan[2].getPop() && !a.getPop());
	std::cout << "test " << i << " reussi" << std::endl ;
	std::cout << "tourne a droite, balle inactive"<< std::endl;
    i++ ;

	tir(t);
	updateBalle(t,fan,3);
	assert(!fan[0].getPop() && !fan[1].getPop() && fan[2].getPop() && !a.getPop());
	std::cout << "test " << i << " reussi" << std::endl ;
	std::cout << "tir,update,fan1 toujours mort,fan2 mort,fan3 vivant, balle inactive"<< std::endl;
    i++ ;

	updateBalle(t,fan,3);
	assert(!fan[0].getPop() && !fan[1].getPop() && fan[2].getPop() && !a.getPop());
	std::cout << "test " << i << " reussi" << std::endl ;
	std::cout << "update balle inactive,fan1 mort,fan2 mort,fan3 toujours vivant"<< std::endl;
    i++ ;

	tir(t);
	updateBalle(t,fan,3);
	canonG();
	tir(t);
	assert(a.getPosX()==2 && a.getPosY()==3 && a.getPop());
	std::cout << "test " << i << " reussi" << std::endl ;
	std::cout << "tir,update de la balle (active),tourne,tir impossible balle toujours a droite"<< std::endl;
    i++ ;

	a.setPop(false);
	assert(!a.getPop());
	std::cout << "test " << i << " reussi" << std::endl ;
	std::cout << "desactive la balle"<< std::endl;
    i++ ;
 }


