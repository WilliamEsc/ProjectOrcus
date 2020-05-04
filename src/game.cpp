#include "game.h"

game::game()
{
}
game::~game()
{
    for (size_t i = 0; i < target.size(); i++)
        delete target[i];
    for (size_t i = 0; i < heal.size(); i++)
        delete heal[i];
    delete m;
    delete GameOver;
    delete Victory;
    delete drop;
    delete key;
    delete menu;
}

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

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
        printf("%s", Mix_GetError());
    }

    // Initialisation joueur
    joueur.setTexture(renderer, "Data/persos1.png", "Data/balle.png");

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

    // Initialisation des objets
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

    drop = new loot(0, 48, 78);
    drop->setTexture(renderer);

    key = new cles(51, 82);
    key->setTexture(renderer, "Data/key.png");

    //Initialisation des écrans de fin
    GameOver->setFileName("Data/GameOver.png");
    GameOver->setTexture(GameOver->loadTexture(renderer));
    success = false;
    Victory->setFileName("Data/Victory.jpg");
    Victory->setTexture(Victory->loadTexture(renderer));

    //Initialisation de l´écran du debut
    menu->setFileName("Data/menu.png");
    menu->setTexture(menu->loadTexture(renderer));

    //Initialisation de la musique
    musique = Mix_LoadMUS("Data/musiqueIntro.mp3");
    if (musique == NULL)
    {
        printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    else
        printf("Music load !");

    //Initialisation des sons
    bite = Mix_LoadWAV("Data/Bite.mp3");
    fire = Mix_LoadWAV("M4A1.wav");
}

void game::handleEvents()
{
    SDL_Event events;
    SDL_PollEvent(&events);
    float f = 0;
    double ang = 0;
    const Uint8 *keystates;
    keystates = SDL_GetKeyboardState(NULL);
    if (joueur.getPop() && !success)
    {
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
        joueur.deplace(f, ang, m->getCollision());
        if (keystates[SDL_SCANCODE_SPACE])
        {
            // if(cad == 0.1) {
            //     fire = NULL ;
            //     fire = Mix_LoadWAV("Data/AK47.mp3");
            // } 
            float ti = (clock() - last);
            joueur.tir();
            if (ti / CLOCKS_PER_SEC > cad){
                Mix_PlayChannel(1, fire, 0);
                last = clock();
            }
        }
    }
    if (keystates[SDL_SCANCODE_ESCAPE])
    {
        isRunning = false;
    }
    if (events.type == SDL_QUIT)
        isRunning = false; // Si l'utilisateur a clique sur la croix de fermeture
}

void game::update()
{
    if (joueur.getPop() && !success)
    {
        for (size_t i = 0; i < heal.size(); i++)
        {
            heal[i]->getTexture()->setDest((heal[i]->getPosX() - joueur.getPos()->getComplexX() + 6) * 64, (heal[i]->getPosY() - joueur.getPos()->getComplexY() + 5) * 64);
            if (joueur.getPdv() < 100 && (*joueur.getPos() - heal[i]->getPos()).norme() < 1)
            {
                heal[i]->soignerPersos(joueur);
                delete heal[i];
                heal.erase(heal.begin() + i);
            }
        }
        if (key != NULL)
        {
            key->getTexture()->setDest((key->getPosX() - joueur.getPos()->getComplexX() + 6) * 64, (key->getPosY() - joueur.getPos()->getComplexY() + 5) * 64);

            if ((*joueur.getPos() - key->getPos()).norme() < 1)
            {
                key->ouvrePorte(renderer, *m);
                delete key;
                key = NULL;
            }
        }
        if (drop != NULL)
        {
            drop->getTexture()->setDest((drop->getPosX() - joueur.getPos()->getComplexX() + 6) * 64, (drop->getPosY() - joueur.getPos()->getComplexY() + 5) * 64);

            if ((*joueur.getPos() - drop->getPos()).norme() < 1)
            {
                drop->looting(renderer, joueur);
                cad = 0.1 ;
                delete drop;
                drop = NULL;
            }
        }
        for (size_t i = 0; i < target.size(); i++)
        {
            target[i]->setDest((target[i]->getPos()->getComplexX() - joueur.getPos()->getComplexX() + 6) * 64, (target[i]->getPos()->getComplexY() - joueur.getPos()->getComplexY() + 5) * 64);
            if (target[i]->aggro(*joueur.getPos()))
            {
                target[i]->tourneVers(*joueur.getPos());
                target[i]->deplaceVersJoueur(*joueur.getPos(), m->getCollision());
                target[i]->setDepl(NULL);
                if (target[i]->atckJoueur(*joueur.getPos()))
                {
                    joueur.getHit(target[i]->getDegat());
                    Mix_PlayChannel(-1, bite, 0);
                }
            }
            else
            {
                target[i]->deplacement(m->getCollision());
            }
            if (joueur.Hit(*target[i]->getPos()))
            {
                target[i]->getHit(joueur.getArme()->getDegat());
                if (!target[i]->getPop())
                {
                    delete target[i];
                    target.erase(target.begin() + i);
                }
            }
        }
        success = joueur.estArrive();
        joueur.getArme()->update(renderer, m->getCollision());
    }
}

void game::render()
{
    SDL_RenderClear(renderer);
    if (success)
    {
        Victory->renderTextureNothing(renderer);
    }
    if (joueur.getPop() && !success)
    {
        //this is where we would add stuff to render
        m->drawMap(renderer, *joueur.getPos());

        for (size_t i = 0; i < heal.size(); i++)
        {
            heal[i]->drawObjet(renderer);
        }
        if (key != NULL)
        {
            key->drawObjet(renderer);
        }
        if (drop != NULL)
        {
            drop->drawObjet(renderer);
        }
        //SDL_RenderCopy(renderer,joueur.getTexture(),NULL,joueur.getRect());

        joueur.drawPersonnage(renderer);
        // SDL_RenderDrawPoint(renderer,(b.getPosX()+0.125 - joueur.getPos()->getComplexX() + 6) * 64,(b.getPosY()+0.125 - joueur.getPos()->getComplexY() + 5) * 64);

        for (size_t i = 0; i < target.size(); i++)
        {
            target[i]->drawPersonnage(renderer);
            // SDL_RenderDrawPoint(renderer,(target[i]->getPos()->getComplexX()+0.5 - joueur.getPos()->getComplexX() + 6) * 64,(target[i]->getPos()->getComplexY()+0.5 - joueur.getPos()->getComplexY() + 5) * 64);
        }
    }
    if (!joueur.getPop())
    {
        GameOver->renderTextureNothing(renderer);
    }

    SDL_RenderPresent(renderer);
}

void game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    Mix_FreeMusic(musique);
    //Free the sound effects
    Mix_FreeChunk(bite);
    Mix_FreeChunk(fire);
    fire = NULL;
    bite = NULL;
    musique = NULL;
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();
    std::cout << " Game Cleaned " << std::endl;
}

bool game::running()
{
    return isRunning;
}

void game ::setRunning(bool i)
{
    isRunning = i;
}

void game ::renderMenu()
{
    SDL_RenderClear(renderer);
    menu->renderTextureNothing(renderer);
    SDL_RenderPresent(renderer);
}

void game ::Music()
{
    Mix_PlayMusic(musique, -1);
}

void game ::pauseMusic()
{
    //If there is no music playing
    if (Mix_PlayingMusic() == 0)
    {
        //Play the music
        Mix_PlayMusic(musique, -1);
    }
    //If music is being played
    else
    {
        //If the music is paused
        if (Mix_PausedMusic() == 1)
        {
            //Resume the music
            Mix_ResumeMusic();
        }
        //If the music is playing
        else
        {
            //Pause the music
            Mix_PauseMusic();
        }
    }
}