#ifndef TEXTURE_H
#define TEXTURE_H
#include "def.h"

/*! \class texture
* \brief Une classe pour gerer les affichages des textures avec SDL
*/
class texture
{
private:
    const char *fileName; ///< nom du fichier
    SDL_Texture *tex;     ///< pointer de SDL_Texture
    SDL_Rect dest;        ///< rectangle sdl de destination
    SDL_Rect src;         ///< rectangle sdl de source

public:
    /**
     *\brief constructeur de la classe texture
     */
    texture();
    /**
     *\brief charge la texture grâce a la variable fileName
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     */
    SDL_Texture *loadTexture(SDL_Renderer *ren);
    /**
     *\brief affiche la texture sans le parametre Dest
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     */
    void renderTextureNoDest(SDL_Renderer *ren);
    /**
     *\brief affiche la texture sans le parametre src
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     */
    void renderTextureNoSrc(SDL_Renderer *ren);
    /**
     *\brief affiche la texture passé en parametre sans parametre SRC
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     */
    void renderTextureNoSrc(SDL_Renderer *ren, SDL_Texture *texture);
    /**
     *\brief affichage de la texture
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     */
    void renderTexture(SDL_Renderer *ren);
    /**
     *\brief affichage de la texture sans Dest et SRC
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     */
    void renderTextureNothing(SDL_Renderer *ren);
    /**
     *\brief affichage de la texture en prenant en compte l'angle de rotation
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     */
    void renderTextureEx(SDL_Renderer *ren, double ang);

    /**
     *\brief accesseur de fileName de la texture
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     */
    const char *getFileName() const;
    /**
     *\brief mutateur de fileName de la texture
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     */
    void setFileName(const char *file);

    /**
     *\brief accesseur de SDL_Texture tex de la texture
     */
    SDL_Texture *getSDLTexture() const;
    /**
     *\brief mutateur de SDL_Texture tex de la texture
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     */
    void setTexture(SDL_Texture *t);

    /**
     *\brief accesseur du SDL_Rect dest de la texture
     */
    SDL_Rect getDest() const;
    /**
     *\brief accesseur de la position x du SDL_Rect dest de la texture
     */
    int getDestX() const;
    /**
     *\brief accesseur de la position y du SDL_Rect dest de la texture
     */
    int getDestY() const;

    /**
     *\brief mutateur du SDL_Rect dest de la texture
     * @param x float: position x du rectangle.
     * @param y float: position y du rectangle.
     * @param h float: hauteur du rectangle.
     * @param w float: largeur du rectangle.
     */
    void setDest(const float &x, const float &y, const float &w, const float &h);
    /**
     *\brief mutateur du SDL_Rect dest de la texture
     * @param x float: position x du rectangle.
     * @param y float: position y du rectangle.
     */
    void setDest(const float &x, const float &y);
    /**
     *\brief mutateur du SDL_Rect src de la texture
     * @param rect SDL_Rect: rectangle qui sera copié dans dest.
     */
    void setDest(const SDL_Rect rect);

    /**
     *\brief mutateur du SDL_Rect src de la texture
     * @param x float: position x du rectangle.
     * @param y float: position y du rectangle.
     * @param h float: hauteur du rectangle.
     * @param w float: largeur du rectangle.
     */
    void setSrc(const float &x, const float &y, const float &w, const float &h);
    /**
     *\brief mutateur du SDL_Rect src de la texture
     * @param x float: position x du rectangle.
     * @param y float: position y du rectangle.
     */
    void setSrc(const float &x, const float &y);
    /**
     *\brief mutateur du SDL_Rect src de la texture
     * @param rect SDL_Rect: rectangle qui sera copié dans dest.
     */
    void setSrc(const SDL_Rect rect);
};

#endif