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
    joueur=new personnage;
    SDL_Surface* tmpsurface=IMG_Load("Data/asset.png");
    joueur->setTexture(renderer,tmpsurface);
    SDL_FreeSurface(tmpsurface);
}

void game::handleEvents()
{
    SDL_Event events;
    SDL_PollEvent(&events);
    float f=0;
    double ang=0;
    if (events.type == SDL_KEYDOWN) { // Si une touche est enfoncee
        switch (events.key.keysym.sym) {
        case SDLK_z:
            f=1;
            break;
        case SDLK_s:
            f=-1;
            break;
        case SDLK_q:
            ang=1;
            break;
        case SDLK_d:
            ang=-1;
            break;
        case SDLK_ESCAPE:
            isRunning=false;
            break;
        default: break;
        }
    }
    joueur->deplace(f,ang);
    if (events.type == SDL_KEYUP) { // Si une touche est relaché
        switch (events.key.keysym.sym) {
        case SDLK_z:
            f=0;
            break;
        case SDLK_s:
            f=0;
            break;
        default: break;
        }
    }
    if (events.type == SDL_QUIT) isRunning=false;// Si l'utilisateur a clique sur la croix de fermeture
}

void game::update()
{
    joueur->update();
}

void game::render()
{
    SDL_RenderClear(renderer);
    //this is where we would add stuff to render
    SDL_RenderCopyEx(renderer,joueur->getTexture(),NULL,joueur->getRect(),-joueur->getAngle(),NULL,SDL_FLIP_NONE);
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

