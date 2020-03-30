#include "Fantome.h"

Fantome::Fantome () {
	x = y = 10;
	dir = 0;
    pop=true;
}

Fantome::Fantome(int PosX, int PosY)
{
    x = PosX ;
    y = PosY ;
    dir = 0 ;
    pop=true;
}

void Fantome::versPacman (const Terrain & t, const Pacman & p) {
    if(pop){
    int dx = p.getX()-x;
    int dy = p.getY()-y;
    if (dx>0) dx=1;
    if (dx<0) dx=-1;
    if (dy>0) dy=1;
    if (dy<0) dy=-1;
    if (t.estPositionPersoValide(x+dx,y+dy)) {
        x = x+dx;
        y = y+dy;
    }
    }
}

void Fantome::bougeAuto (const Terrain & t) {
    if(pop){
    int dx [4] = { 1, 0, -1, 0};
    int dy [4] = { 0, 1, 0, -1};
    int xtmp,ytmp;
    xtmp = x + dx[dir];
    ytmp = y + dy[dir];
    if (t.estPositionPersoValide(xtmp,ytmp)) {
        x = xtmp;
        y = ytmp;
    }
    else dir = rand()%4;}
}

void Fantome::setPop(bool b){
    pop=b;
}
bool Fantome::getPop()const{
    return pop;
}