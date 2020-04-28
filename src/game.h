#ifndef GAME_H
#define GAME_H

#include "personnage.h"
#include "def.h"
#include "map.h"
#include "soin.h"
#include "balle.h"
#include "text.h"
#include <iostream>

class game
{
private:
    /* data */
    bool isRunning;
    personnage joueur;
    SDL_Window * window;
    SDL_Renderer *renderer;
    soin s;
    balle b;
    text t;
    map m;

 
    

public:
    game();
    ~game();

    void init(const char* title, int posX, int posY, int width, int height, bool fullscreen);
    
    void handleEvents();
    // void heal();
    void update();
    void render();
    void clean();

    bool running();
};


#endif 