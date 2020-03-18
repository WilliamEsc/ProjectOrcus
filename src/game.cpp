#include "game.h"



game::game(){};
game::~game(){};
 map* m;

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
    
    if(TTF_Init() < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }

    joueur=new personnage;
    SDL_Surface* tmpsurface=IMG_Load("Data/asset.png");
    joueur->setTexture(renderer,tmpsurface);
    SDL_FreeSurface(tmpsurface);
    m = new map(renderer);
    s = new soin();
    s->setPos(400-16,300-16);
    t = new text() ;
}

void game::handleEvents()
{
    SDL_Event events;
    SDL_PollEvent(&events);
    float f;
    double ang;
    const Uint8* keystates;
    keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_W]) {
        f=0.10;
    }
    if (keystates[SDL_SCANCODE_S]) {
        f=-0.10;
    }
    if (keystates[SDL_SCANCODE_A]) {
        ang=0.05;
    }
    if (keystates[SDL_SCANCODE_D]) {
       ang=-0.05;
    }
    if (keystates[SDL_SCANCODE_ESCAPE]){
        isRunning=false;
    }
    joueur->deplace(f,ang);

    if (events.type == SDL_QUIT) isRunning=false;// Si l'utilisateur a clique sur la croix de fermeture
}

void game::heal()
{
    const Uint8* keystates;
    keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_X]) {
       s->setPointDeVie(s->getPointDeVie()-10);
       std::cout << "Point de vie : " << s->getPointDeVie() << std::endl ; 
    }

    if(joueur->getPos()->getComplexX() >= s->getPosX() && 
        joueur->getPos()->getComplexX() <= s->getPosX()+32 && 
        joueur->getPos()->getComplexY() >= s->getPosY() &&
        joueur->getPos()->getComplexY() <= s->getPosY()+32 
        )
    {
        s->setPointDeVie(s->getPointDeVie()+10);
        std::cout << "Point de vie : " << s->getPointDeVie() << std::endl ; 
    }


}

void game::update()
{
    joueur->update();
}

void game::render()
{
    SDL_RenderClear(renderer);
    //this is where we would add stuff to render
    m->drawMap(renderer);
    s->setTexture(renderer, s->getPosX(), s->getPosY());
    SDL_RenderCopyEx(renderer,joueur->getTexture(),NULL,joueur->getRect(),-joueur->getAngle(),NULL,SDL_FLIP_NONE);
    t->setTexte("Point de vie",renderer,0,0);
    //TTF_CloseFont(t->getFont());
    SDL_RenderPresent(renderer);
    
}

void game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();
    std::cout << " Game Cleaned " << std::endl ;
}

bool game::running()
{
    return isRunning;
}

