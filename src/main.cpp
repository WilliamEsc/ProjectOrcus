#include "def.h"
#include "texture.h"
#include "game.h"

int main(int argc, const char *argv[])
{

    game g;
    SDL_Event event;
    bool game = true;

    g.init("écran", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 832, 704, false);
    g.Music();

    while (game) //game is running
    {
        /* handle any user input
        update all object...
        render changes to the display */

        g.renderMenu();

        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            game = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                game = false;
                break;

            case SDLK_SPACE: // On lance le jeu 
                g.pauseMusic();
                while (g.running())
                {
                    g.handleEvents();
                    g.update();
                    g.render();
                }
                g.setRunning(true);
                g.pauseMusic();
                break;
            }
            break;
        }
    }

    g.clean();

    return 0;
}
