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

    void texture::renderTexture(SDL_Texture*tex, SDL_Renderer *ren, int x, int y){
        SDL_Rect dst;
        dst.x = x;
        dst.y = y;
        SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
        SDL_RenderCopy(ren, tex, NULL, &dst);
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