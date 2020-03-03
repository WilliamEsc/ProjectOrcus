#ifndef GAME_H
#define GAME_H

#include "personnage.h"
#include "def.h"
#include "map.h"
#include <iostream>

class game
{
private:
    /* data */
    bool isRunning;
    personnage* joueur;
    SDL_Window * window;
    SDL_Renderer *renderer;
    

public:
    game();
    ~game();

    void init(const char* title, int posX, int posY, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();
};


#endif 