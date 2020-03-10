#include "map.h"

int map1[20][25] = {

    { 0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,2,2,1,2,2,1,2,2,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,2,2,1,2,2,1,2,2,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,2,2,1,2,2,1,2,2,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,2,2,1,2,2,1,2,2,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,2,2,1,2,2,1,2,2,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,1,1,1,1,1,1,1,1,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,1,2,2,1,1,2,2,1,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,1,2,2,1,1,2,2,1,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,1,1,1,1,1,1,1,1,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0 },
    { 0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0 }
};

map::map()
{

}

map::map(SDL_Renderer* renderer)
{
    SDL_Surface* surface1 = IMG_Load("Data/dirt.png");
    SDL_Surface* surface2 = IMG_Load("Data/water.png");
    SDL_Surface* surface3 = IMG_Load("Data/stone.png");
    dirt = SDL_CreateTextureFromSurface(renderer,surface1);
    water = SDL_CreateTextureFromSurface(renderer,surface2);
    stone = SDL_CreateTextureFromSurface(renderer,surface3);
    SDL_FreeSurface(surface1);
    SDL_FreeSurface(surface2);
    SDL_FreeSurface(surface3);

    loadMap(map1);

    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;

    dest.x = dest.y = 0;   
}

map::~map()
{

}

void map::loadMap(int arr[20][25])
{
    for (int row = 0 ; row < 20 ; row++)
    {
        for ( int column = 0 ; column < 25 ; column++ )
        {
            carte[row][column] = arr[row][column];
        }
    }

}

void map::drawMap(SDL_Renderer* rend)
{
        int type = 0 ;
        for (int row = 0 ; row < 20 ; row++)
        {
            for ( int column = 0 ; column < 25 ; column++ )
            {
                type = carte[row][column];

                dest.x = column * 32;
                dest.y = row * 32;

                switch (type)
                {
                    case 0:
                        SDL_RenderCopy(rend, water, &src, &dest);
                        break;
                    
                    case 1: 
                        SDL_RenderCopy(rend, dirt, &src, &dest);
                        break;
                    
                    case 2: 
                        SDL_RenderCopy(rend, stone, &src, &dest);
                        break;

                    default: 
                        break;
                }
            }
        }    
}


