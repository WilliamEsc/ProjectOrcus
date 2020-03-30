#include "Fantome.h"
#include "Pacman.h"

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

Fantome::~Fantome(){
    std::cout<<"fille detruite"<<std::endl;
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

void Fantome :: testRegression()
{
    Fantome fan;
    Terrain t;
    Pacman p ;

    int i = 1 ;

    assert(fan.dir == 0);
    std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;
    assert(fan.pop == true);
    std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;
    assert(fan.x == 10);
    std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;
    assert(fan.x == 10); 
    std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;

    assert(fan.getPop() == pop) ;
    std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;
     
    int tx = fan.getX() ;
    int ty = fan.getY();
    fan.bougeAuto(t);
    assert(fan.getX() == tx+1 && fan.getY() == ty);
    std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;

    tx = fan.getX() ;
    ty = fan.getY();
    fan.versPacman(t,p) ;
    assert(fan.getX() == tx-1 && fan.getY() == ty-1);
    std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;
    
    fan.setPop(false) ;
    std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;
    
    assert(fan.getPop() == false) ;
    std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;


}