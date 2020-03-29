#include "Personnage.h"

Personnage :: Personnage() {
    
}

int Personnage::getX () const { return x; }

int Personnage::getY () const { return y; }

int Personnage::setX (int x) { return this->x = x; }

int Personnage::setY (int y) { return this->y = y; }

    void Personnage::gauche (const Terrain & t) {
	    if (t.estPositionPersoValide(x-1,y)) x--;
    }

    void Personnage::droite (const Terrain & t) {
	    if (t.estPositionPersoValide(x+1,y)) x++;
    }

    void Personnage::haut (const Terrain & t) {
	    if (t.estPositionPersoValide(x,y-1)) y--;
    }

    void Personnage::bas(const Terrain & t) {
	    if (t.estPositionPersoValide(x,y+1)) y++;
    }
