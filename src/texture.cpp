#include "texture.h"

texture::texture()
{
    fileName = nullptr;
    tex = nullptr;
}

SDL_Texture *texture::loadTexture(SDL_Renderer *ren)
{
    SDL_Texture *texture = nullptr;
    SDL_Surface *surface = IMG_Load(fileName);

    if (surface != nullptr)
    {
        texture = SDL_CreateTextureFromSurface(ren, surface);
        SDL_FreeSurface(surface);
        if (texture == nullptr)
        {
            std::cout << " error CreateTextureFromSurface " << std::endl;
        }
        else
        {
            std::cout << fileName << " Image load " << std::endl;
        }
    }
    else
    {
        std::cout << fileName << " Erreur Surface " << std::endl;
    }
    return texture;
}

void texture::renderTextureNoSrc(SDL_Renderer *ren)
{
    SDL_RenderCopy(ren, tex, NULL, &dest);
}

void texture::renderTexture(SDL_Renderer *ren)
{
    SDL_RenderCopy(ren, tex, &src, &dest);
}

void texture::renderTextureNoSrc(SDL_Renderer *ren, SDL_Texture *texture)
{
    SDL_RenderCopy(ren, texture, NULL, &dest);
}

void texture::renderTextureNothing(SDL_Renderer *ren)
{
    SDL_RenderCopy(ren, tex, NULL, NULL);
}

void texture::renderTextureNoDest(SDL_Renderer *ren)
{
    SDL_RenderCopy(ren, tex, &src, NULL);
}

void texture::renderTextureEx(SDL_Renderer *ren, double ang)
{
    SDL_RenderCopyEx(ren, tex, NULL, &dest, ang, NULL, SDL_FLIP_NONE);
}

const char *texture::getFileName() const
{
    return fileName;
}

void texture::setFileName(const char *fil)
{
    fileName = fil;
}

void texture::setTexture(SDL_Texture *t)
{
    tex = t;
}

SDL_Texture *texture::getSDLTexture() const
{
    return tex;
}

SDL_Rect texture::getDest() const
{
    return dest;
}

int texture::getDestX() const
{
    return dest.x;
}

int texture::getDestY() const
{
    return dest.y;
}

void texture ::setDest(const float &x, const float &y, const float &w, const float &h)
{
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;
}

void texture ::setDest(const float &x, const float &y)
{
    dest.x = x;
    dest.y = y;
}

void texture ::setDest(const SDL_Rect rect)
{
    dest = rect;
}

void texture ::setSrc(const float &x, const float &y, const float &w, const float &h)
{
    src.x = x;
    src.y = y;
    src.w = w;
    src.h = h;
}

void texture ::setSrc(const float &x, const float &y)
{
    src.x = x;
    src.y = y;
}

void texture ::setSrc(const SDL_Rect rect)
{
    src = rect;
}