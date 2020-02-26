#include "game.h"


game::game(){};
game::~game(){};

void game::init(const char* title, int posX, int posY, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
   
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialised! ..." << std::endl;

        window = SDL_CreateWindow(title, posX, posY, width, height, flags);
        if(window)
        {
            std::cout << " window created! " << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << " renderer created! " << std::endl;
        }

        isRunning = true ;
    } else {
        isRunning = false ;
    }
}

void game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false ;
        break;
    
    default:
        break;
    }
}

void game::update()
{

}

void game::render()
{
    SDL_RenderClear(renderer);
    //this is where we would add stuff to render
    SDL_RenderPresent(renderer);
}

void game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << " Game Cleaned " << std::endl ;
}

bool game::running()
{
    return isRunning;
}

