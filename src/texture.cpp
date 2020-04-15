#include "texture.h"

    
    texture::texture()
    {
        fileName = nullptr ;
        tex = nullptr ;
    }

    SDL_Texture* texture::loadTexture(const char *file, SDL_Renderer *ren)
    {
        SDL_Texture *texture = nullptr;
        SDL_Surface *surface = IMG_Load(file);

        if (surface != nullptr)
        {
            texture = SDL_CreateTextureFromSurface(ren, surface);
            SDL_FreeSurface(surface);
            if(texture == nullptr)
            {
               std::cout << " error CreateTextureFromSurface " << std::endl;
            }
        }
        else 
        {
             std::cout << " Image load " << std::endl;
        }
        return texture ;
    }

       SDL_Texture* texture::loadTextureText(const char * texte, TTF_Font *font, SDL_Color color, SDL_Renderer *ren)
    {
        SDL_Texture *texture = nullptr;
        SDL_Surface *surface = TTF_RenderText_Solid(font, texte, color);

        if (surface != nullptr)
        {
            texture = SDL_CreateTextureFromSurface(ren, surface);
            SDL_FreeSurface(surface);
            if(texture == nullptr)
            {
               std::cout << " error CreateTextureFromSurface " << std::endl;
            }
        }
        else 
        {
             std::cout << " Font load " << std::endl;
        }
        return texture ;
    }

    void texture::renderTexture(SDL_Texture*tex, SDL_Renderer *ren, SDL_Rect dst){
        dest=dst;
        SDL_RenderCopy(ren, tex, NULL, &dest);
    }

    void texture::renderTexture(SDL_Texture*tex, SDL_Renderer *ren,SDL_Rect src, SDL_Rect dst){
        dest=dst;
        SDL_RenderCopy(ren, tex, &src, &dest);
    }

    const char *texture::getFileName()
    {
        return fileName;
    }

    void texture::setFileName(char * file)
    {
        fileName = file ;
    }
    
    void texture::setTexture(SDL_Texture *t)
    {
        tex = t ;
    }

    SDL_Texture *texture::getTexture()
    {
        return tex;
    }

    SDL_Rect* texture::getRect()
    {
        return &dest;
    }

    SDL_Rect texture::getRect2()
    {
        return dest;
    }

    int texture::getRectX()
    {
        return dest.x ;
    }

    int texture::getRectY()
    {
        return dest.y ;
    }

    void texture :: setDest(float x,float y, float w, float h)
    {
        dest.x = x;
        dest.y = y;
        dest.w = w;
        dest.h = h;
    }

    void texture :: setDest(float x, float y)
    {
        dest.x = x;
        dest.y = y;
    }

    void texture :: setDest(const SDL_Rect rect)
    {
        dest = rect ;
    }
