#ifndef MAP_H
#define MAP_H

#include "def.h"
#include "texture.h"
#include "complex.h"

class map 
{
    public:
        map();
        map(SDL_Renderer* rend);
        ~map();

        void loadCalque(const char* str,int calque[124][124]);
        void drawMap(SDL_Renderer* rend,const Complex &posJ);
        void operator>>(std::istream& is);

        int collision[124][124];


    private:

        SDL_Rect src, dest;

        // texture * dirt;
        // texture * water=new texture();
        // texture * stone;

        // texture * tileset= new texture();
        texture * mappng= new texture();
        // texture * error= new texture();

        // int calque1[100][100];
    	// int calque2[100][100];
	    // int calque3[100][100];

};

#endif
