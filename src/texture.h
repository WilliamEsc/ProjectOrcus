#ifndef TEXTURE_H
#define TEXTURE_H
#include "def.h" 

class texture
{
private:
    
   const char *fileName ;
   SDL_Texture * tex;
   SDL_Rect dest;
   SDL_Rect src;

public:
    
    texture();
    SDL_Texture* loadTexture(SDL_Renderer *ren);
    SDL_Texture* loadTextureText(const char * texte, TTF_Font *font, SDL_Color color, SDL_Renderer *ren);
    void renderTextureNoDest(SDL_Renderer *ren);
    void renderTextureNoSrc(SDL_Renderer *ren);
    void renderTextureNoSrc(SDL_Renderer *ren,SDL_Texture* texture);
    void renderTexture(SDL_Renderer *ren);
    void renderTextureNothing(SDL_Renderer *ren);
    void renderTextureEx(SDL_Renderer *ren,double ang);
    
    const char *getFileName();
    void setFileName(const char * file);

    SDL_Texture *getSDLTexture();
    void setTexture(SDL_Texture *t);

    SDL_Rect* getDest();
    SDL_Rect getDest2();
    int getDestX();
    int getDestY();

    void setDest(float x,float y, float w, float h);
    void setDest(float x, float y);
    void setDest(const SDL_Rect rect);

    void setSrc(float x,float y, float w, float h);
    void setSrc(float x, float y);
    void setSrc(const SDL_Rect rect);

};




#endif