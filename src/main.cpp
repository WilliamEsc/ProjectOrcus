#include "game.h" 

int main(int argc, const char* argv[]) {
    
    game g ;

    g.init("écran", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while (g.running()) //game is running 
    {
        /* handle any user input
        update all object...
        render changes to the display */

        g.handleEvents();
        g.heal();
        g.update();
        g.render();

    }
    
    g.clean();

    return 0;

}
