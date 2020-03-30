#include "Soin.h"

Soin::Soin()
{
    x = 10 ;
    y = 20 ;
    heal = 10 ;
}

void Soin :: soignerPac(Pacman &p)
{
    p.setPdv(p.getPdv()+heal) ;
}

void Soin :: hitPac(Pacman &p) 
{
    p.setPdv(p.getPdv()-5);
}

void Soin :: testRegression()
{
    Soin s ;
    Pacman p;
    int i = 1 ;

    assert(s.x == 10 && s.y == 20 && s.heal == 10);
    std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;
    
    int t = p.getPdv();
    s.soignerPac(p);
    assert(p.getPdv() == t+10);
    std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;

    t = p.getPdv();
    s.hitPac(p);
    assert(p.getPdv() == t-5);
    std::cout << "test " << i << " reussi" << std::endl ;
    i++ ;
}