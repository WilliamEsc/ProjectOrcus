#ifndef GAME_H
#define GAME_H

#include "hero.h"
#include "ennemie.h"
#include "def.h"
#include "map.h"
#include "soin.h"
#include "cles.h"
#include "balle.h"
#include "text.h"
#include <iostream>

class game
{
private:
    /* data */
    bool isRunning;
    hero joueur;
    std::vector<ennemie*> target;
    SDL_Window * window;
    SDL_Renderer *renderer;
    std::vector<soin*> heal;
    cles* key;
    balle b;
    text t;
    map* m;

 
    

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
