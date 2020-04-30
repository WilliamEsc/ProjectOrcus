#include "game.h"

game::game(){};
game::~game(){};

void game::init(const char *title, int posX, int posY, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialised! ..." << std::endl;

        window = SDL_CreateWindow(title, posX, posY, width, height, flags);
        if (window)
        {
            std::cout << " window created! " << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << " renderer created! " << std::endl;
        }

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    if (TTF_Init() < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }

    // Initialisation joueur
    joueur.setTexture(renderer, "Data/persos1.png");

    //initialisation de la map
    m = new map(renderer);

    //initialisation des ennemies
    for (int i = 0; i < 20; i++)
    {
        int x, y;
        do
        {
            x = rand() % 112 - 12;
            y = rand() % 112 - 12;
        } while (m->getCollision(y, x) != -1);
        int t = rand() % 2;
        ennemie *spawn = new ennemie(x, y, *joueur.getPos(), t);
        spawn->setTexture(renderer, "Data/asset.png");
        target.push_back(spawn);
    }

    // Initialisation du kit de soin
    Complex tabSpawnSoin[5];
    tabSpawnSoin[0].setComplexXY(40, 31);
    tabSpawnSoin[1].setComplexXY(66, 42);
    tabSpawnSoin[2].setComplexXY(21, 70);
    tabSpawnSoin[3].setComplexXY(103, 48);
    tabSpawnSoin[4].setComplexXY(92, 85);

    for (int i = 0; i < 5; i++)
    {
        soin *newSoin = new soin(tabSpawnSoin[i].getComplexX(), tabSpawnSoin[i].getComplexY());
        newSoin->setTexture(renderer, "Data/kitDeSoin.png");
        heal.push_back(newSoin);
    }

    key=new cles(25,25);
    key->setTexture(renderer,"Data/testTile.png");

    // s.setPos(48,79);
    // s.setTexture(renderer, "Data/kitDeSoin.png");
    // t = new text() ;

    //Initialisation de la balle
    b.LoadBalle(renderer);
}

void game::handleEvents()
{
    SDL_Event events;
    SDL_PollEvent(&events);
    float f = 0;
    double ang = 0;
    const Uint8 *keystates;
    keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_W])
    {
        f = -0.005;
    }
    if (keystates[SDL_SCANCODE_S])
    {
        f = 0.005;
    }
    if (keystates[SDL_SCANCODE_A])
    {
        ang = 0.6;
    }
    if (keystates[SDL_SCANCODE_D])
    {
        ang = -0.6;
    }
    if (keystates[SDL_SCANCODE_ESCAPE])
    {
        isRunning = false;
    }
    joueur.deplace(f, ang, m->getCollision());
       if (keystates[SDL_SCANCODE_SPACE])
    {
        b.Fire(joueur);
        b.setAngle(joueur.getAngle());
    }

    if (events.type == SDL_QUIT)
        isRunning = false; // Si l'utilisateur a clique sur la croix de fermeture
}

void game::update()
{
    for (size_t i = 0;i < heal.size(); i++)
    {
        if (heal[i]->getPop())
        {
            if ((*joueur.getPos() - heal[i]->getPos()).norme() < 1)
            {
                heal[i]->soignerPersos(joueur);
            }
            heal[i]->getTexture()->setDest((heal[i]->getPosX() - joueur.getPos()->getComplexX() + 6) * 64, (heal[i]->getPosY() - joueur.getPos()->getComplexY() + 5) * 64);
        }
    }
    if(key->getPop())
    {
        if ((*joueur.getPos() - key->getPos()).norme() < 1)
        {
            key->ouvrePorte(renderer, *m);
        }
    }
    key->getTexture()->setDest((key->getPosX() - joueur.getPos()->getComplexX() + 6) * 64, (key->getPosY() - joueur.getPos()->getComplexY() + 5) * 64);
    for (size_t i = 0; i < target.size(); i++)
    {
        target[i]->setDest((target[i]->getPos()->getComplexX() - joueur.getPos()->getComplexX() + 6) * 64, (target[i]->getPos()->getComplexY() - joueur.getPos()->getComplexY() + 5) * 64);
        if (target[i]->aggro(*joueur.getPos()))
        {
            target[i]->tourneVersJoueur(*joueur.getPos());
            target[i]->deplaceVersJoueur(*joueur.getPos(), m->getCollision());
            target[i]->setDepl(NULL);
            if (target[i]->atckJoueur(*joueur.getPos()))
            {
                joueur.setPdv(joueur.getPdv() - 10);
            }
        }
        else
        {
            target[i]->deplacement(m->getCollision());
        }
    }

    b.updateBalle(renderer);
}

void game::render()
{
    SDL_RenderClear(renderer);
    //this is where we would add stuff to render
    m->drawMap(renderer, *joueur.getPos());

    for (size_t i = 0;i < heal.size(); i++)
    {
    if (heal[i]->getPop())
    {
        heal[i]->drawObjet(renderer);
    }
    }
    if(key->getPop())
    {
        key->drawObjet(renderer);
    }
    b.renderBalle(renderer,*joueur.getPos());

    // t.setTexte("Point de vie",renderer,0,0);
    // std::string txtPdv=std::to_string(joueur.getPdv());
    // t.setTexte(txtPdv.c_str(),renderer,0,20);
    //SDL_RenderCopy(renderer,joueur.getTexture(),NULL,joueur.getRect());

    joueur.drawPersonnage(renderer);

    for (size_t i = 0; i < target.size(); i++)
    {
        target[i]->drawPersonnage(renderer);
    }

    // TTF_CloseFont(t.getFont());
    SDL_RenderPresent(renderer);
}

void game::clean()
{
    for (size_t i = 0; i < target.size(); i++)
        delete target[i];
    for (size_t i = 0; i < heal.size(); i++)
        delete heal[i];
    delete m;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();
    std::cout << " Game Cleaned " << std::endl;
}

bool game::running()
{
    return isRunning;
}
