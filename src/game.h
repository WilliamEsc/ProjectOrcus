#ifndef GAME_H
#define GAME_H

#include "hero.h"
#include "ennemie.h"
#include "def.h"
#include "map.h"
#include "soin.h"
#include "cles.h"
#include "loot.h"
#include <iostream>

/*! \class game
* \brief Classe qui comporte tous les objets du jeu
*/
class game
{
private:
    /* data */
    bool success;                    ///< booleen reussite du personnage
    bool isRunning;                  ///< booleen jeu en cours
    hero joueur;                     ///< héro (personnage joueur)
    SDL_Window *window;              ///< fenetre SDL
    SDL_Renderer *renderer;          ///< render SDL
    std::vector<ennemie *> target;   ///< tableau dynamique de pointer d'ennemie alloué sur le tas
    std::vector<soin *> heal;        ///< tableau dynamique de pointer de soin alloué sur le tas
    loot *drop;                      ///< pointer de loot alloué sur le tas
    cles *key;                       ///< pointer de cles alloué sur le tas
    map *m;                          ///< pointer de carte du jeu alloué sur le tas
    texture *GameOver = new texture; ///< pointer de ecran de defaite alloué sur le tas
    texture *Victory = new texture;  ///< pointer de ecran de succes alloué sur le tas
    texture *menu = new texture;
    Mix_Music *musique;
    //The sound effects that will be used
    Mix_Chunk *bite = NULL;
    Mix_Chunk *fire = NULL ;
    float last = 0.0;
    float cad = 0.8;

public:
    /**
     *\brief constructeur du jeu
     */
    game();
    /**
     *\brief destructeur du jeu
     */
    ~game();

    /**
     *\brief initialise la fenetre SDL et les objet necessaire pour le jeu.
     */
    void init(const char *title, int posX, int posY, int width, int height, bool fullscreen);

    /**
     *\brief gere les actions du joueur
     */
    void handleEvents();
    /**
     *\brief mets a jours les positions et active les objets si besoin
     */
    void update();
    /**
     *\brief appel toutes les fonctions d'affichage
     */
    void render();
    /**
     *\brief accesseur de la position y de l'objet
     */
    void clean();

    /**
     *\brief accesseur de la position y de l'objet
     */
    bool running();
    void setRunning(bool i);

    void renderMenu();
    void Music();
    void pauseMusic();
};

#endif
