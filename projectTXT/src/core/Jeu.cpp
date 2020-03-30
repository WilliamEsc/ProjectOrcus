#include "Jeu.h"

Jeu::Jeu () : ter(), pac(), fan(), fan2(9,7) {
	// ter.mangePastille(pac.getX(),pac.getY());
}

Terrain& Jeu::getTerrain () { return ter; }

Pacman& Jeu::getPacman () {	return pac; }

const Terrain& Jeu::getConstTerrain () const { return ter; }

const Pacman& Jeu::getConstPacman () const { return pac; }

const Fantome& Jeu::getConstFantome () const { return fan; }

const Fantome& Jeu::getConstFantome2 () const { return fan2; }

const Soin& Jeu::getConstSoin() const { return s ;}

int Jeu::getNombreDeFantome() const { return 2; }


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
    //fan.versPacman(ter,pac);
	pac.updateBalle(ter,fan,fan2);
    fan.bougeAuto(ter);
	fan2.bougeAuto(ter);
	if ( (pac.getX() == fan.getX() && pac.getY() == fan.getY() && fan.getPop()) || (pac.getX() == fan2.getX() && pac.getY() == fan2.getY() && fan2.getPop()) ) {
		s.hitPac(pac);
	}
}