#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32

#include "winTxt.h"
#include "Jeu.h"

using namespace std;

char str[2];

void txtAff(WinTXT & win, const Jeu & jeu) {
	const Terrain& ter = jeu.getConstTerrain();
	const Pacman& pac = jeu.getConstPacman();
	const Fantome& fan = jeu.getConstFantome();
	const Fantome& fan2 = jeu.getConstFantome2();
	
	win.clear();

    // Affichage des murs et des pastilles
	for(int x=0;x<ter.getDimX();++x)
		for(int y=0;y<ter.getDimY();++y)
			win.print(x,y,ter.getXY(x,y));

    // Affichage de Pacman
	win.print(pac.getX(),pac.getY(),'P');
	// Affichage du Fantome
	
	win.print(fan.getX(),fan.getY(),'F');
	win.print(fan2.getX(),fan2.getY(),'F');

	win.print(15,0,pac.affichePdv(str));
	
	//win.print(15,0,'V');
	//cout << "Point de vie " << endl ;
	
	win.draw();
}

void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getConstTerrain().getDimX(),jeu.getConstTerrain().getDimY());

	const Pacman& pac = jeu.getConstPacman();

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		c = win.getCh();
		switch (c) {
			case 'a':
				jeu.actionClavier('g');
				break;
			case 'd':
				jeu.actionClavier('d');
				break;
			case 'w':
				jeu.actionClavier('h');
				break;
			case 's':
				jeu.actionClavier('b');
				break;
			case 'q':
				ok = false;
				break;
		}

		jeu.actionsAutomatiques();

		win.print(15,0,pac.affichePdv(str));

	} while (ok);

}
