#ifndef MAP_H
#define MAP_H

#include "game.h"
#include "def.h"
#include "texture.h"

class map 
{
    public:

        map();
        map(SDL_Renderer* rend);
        ~map();

        void loadMap(int arr[36][64]);
        void drawMap(SDL_Renderer* rend);


    private:

        SDL_Rect src, dest;
        
        // SDL_Texture* dirt;
        // SDL_Texture* water;
        // SDL_Texture* stone;

        texture *dirt = new texture() ;
        texture *water = new texture() ;
        texture *stone = new texture() ;

        int carte[36][64];

};

#endif