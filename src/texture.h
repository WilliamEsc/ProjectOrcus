#ifndef TEXTURE_H
#define TEXTURE_H
#include "def.h" 

class texture
{
private:
    
   const char *fileName ;
   SDL_Texture * tex;


public:
    
    texture();
    SDL_Texture* loadTexture(const char *file, SDL_Renderer *ren);
    SDL_Texture* loadTextureText(const char * texte, TTF_Font *font, SDL_Color color, SDL_Renderer *ren);
    void renderTexture(SDL_Texture*tex, SDL_Renderer *ren, int x, int y);
    
    const char *getFileName();
    void setFileName(char * file);

    SDL_Texture *getTexture();
    void setTexture(SDL_Texture *t);

};




#endif