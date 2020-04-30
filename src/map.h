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

        void setMapPng(SDL_Renderer* renderer,const char * file);
        texture* getMapPNG()const;

        void setCollision(const int & i,const int & j,const int & val);
        int* getCollision()const;
        int getCollision(const int & i,const int & j)const;

        void loadCollision(const char* str);

        void loadCalque(const char* str,int calque[][124]);
        void drawMap(SDL_Renderer* rend,const Complex &posJ);
        void operator>>(std::istream& is);


    private:

        int * Collision=new int[15376];
        // texture * tileset= new texture();
        texture * mappng= new texture();
        // texture * error= new texture();
};

#endif
