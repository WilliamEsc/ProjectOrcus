#ifndef MAP_H
#define MAP_H

#include "game.h"
#include "def.h"

class map 
{
    public:

        map();
        map(SDL_Renderer* rend);
        ~map();

        void loadMap(int arr[20][25]);
        void drawMap(SDL_Renderer* rend);


    private:

        SDL_Rect src, dest;
        
        SDL_Texture* dirt;
        SDL_Texture* water;
        SDL_Texture* stone;

        int carte[20][25];

};

#endif