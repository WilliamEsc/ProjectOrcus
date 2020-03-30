#include "Jeu.h"

Jeu::Jeu () : ter(), pac() {
	nbF=2;
	fan=new Fantome [nbF];
	fan[1].setX(8);
	fan[1].setY(14);
}

Jeu::~Jeu(){
	delete[] fan;
}

Terrain& Jeu::getTerrain () { return ter; }

Pacman& Jeu::getPacman () {	return pac; }

const Terrain& Jeu::getConstTerrain () const { return ter; }

const Pacman& Jeu::getConstPacman () const { return pac; }

const Fantome& Jeu::getConstFantome (int i) const { return fan[i]; }

const Soin& Jeu::getConstSoin() const { return s ;}

int Jeu::getNombreDeFantome() const { return nbF; }


void Jeu::actionClavier (const char touche) {
	switch(touche) {
		case 'g' :
				pac.gauche(ter);
				pac.canonG();
				break;
		case 'd' :
				pac.droite(ter);
				pac.canonD();
				break;
		case 'h' :
				pac.haut(ter);
				pac.canonH();
				break;
		case 'b' :
				pac.bas(ter);
				pac.canonB();
				break;
		case 't' :
				pac.tir(ter);
				break;
	}
	if (ter.getXY(pac.getX(),pac.getY())=='+') {
	    ter.prendKit(pac.getX(),pac.getY());
		s.soignerPac(pac);
	}
}

void Jeu::actionsAutomatiques () {
	pac.updateBalle(ter,fan,nbF);
	for(int i=0;i<2;i++){
    fan[i].bougeAuto(ter);
	if (pac.getX() == fan[i].getX() && pac.getY() == fan[i].getY() && fan[i].getPop()) {
		s.hitPac(pac);
	}
	}
}