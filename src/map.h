#ifndef MAP_H
#define MAP_H

#include "game.h"
#include "def.h"
#include "texture.h"

class map 
{
    public:
        int map1[100][100];

        map();
        map(SDL_Renderer* rend);
        ~map();

        void loadCalque(const char* str,int calque[100][100]);
        void drawMap(SDL_Renderer* rend,const Complex &posJ);
        void operator>>(std::istream& is);


    private:

        SDL_Rect src, dest;

        // texture * dirt;
        texture * water=new texture();
        // texture * stone;

        texture * tileset= new texture();
        texture * error= new texture();

        int calque1[100][100];
    	int calque2[100][100];
	    int calque3[100][100];

};

#endif
