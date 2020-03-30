#include <iostream>
#include "core/Fantome.h"
#include "core/Soin.h"

using namespace std ;

int main () 
{
    Pacman pakito;
    Fantome fan ;
    Soin s;

    cout<< "Test Regression Joueur :" <<endl;
    pakito.testRegression();

    cout << "Test Regression Fantome :" << endl ;
    fan.testRegression();

    cout << "Test Regression Soin :" << endl ;
    s.testRegression();

    return 0 ;
}