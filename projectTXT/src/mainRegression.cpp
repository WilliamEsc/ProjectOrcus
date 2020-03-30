#include <iostream>
#include "core/Fantome.h"
#include "core/Soin.h"
#include "core/Pacman.h"

using namespace std ;

int main () 
{
    Fantome fan ;
    Soin s;
    Pacman p;

    cout << "Test Regression Ennemie :" << endl ;
    fan.testRegression();

    cout << " " << endl;

    cout << "Test Regression Soin :" << endl ;
    s.testRegression();

    cout << " " << endl;

    cout << "Test Regression Joueur :" << endl ;
    p.testRegression();

    return 0 ;
}