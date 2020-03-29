#include "Pacman.h"

Pacman::Pacman () : Personnage() {
 	x = 1 ;
	y = 2 ;	
	pdv = 50 ;
}

void Pacman::setPdv (int p)
{
	pdv = p ;
}

int Pacman::getPdv() const 
{
	return pdv;
}

char *Pacman::affichePdv(char *str)const
{
	int temp = pdv;
	sprintf(str, "%d", temp);
	return str ;
}




