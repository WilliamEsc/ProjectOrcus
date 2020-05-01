#ifndef GAME_H
#define GAME_H

#include "hero.h"
#include "ennemie.h"
#include "def.h"
#include "map.h"
#include "soin.h"
#include "cles.h"
#include "loot.h"
#include <iostream>

class game
{
private:
    /* data */
    bool success;
    bool isRunning;
    hero joueur;
    SDL_Window * window;
    SDL_Renderer *renderer;
    std::vector<ennemie*> target;
    std::vector<soin*> heal;
    loot* drop;
    cles* key;
    map* m;
    texture* GameOver=new texture;
    texture* Victory=new texture;
 
    

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
