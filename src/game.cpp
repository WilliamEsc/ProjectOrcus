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
    SDL_Surface *tmpsurface = IMG_Load("Data/persos1.png");
    joueur.setTexture(renderer, tmpsurface);
    SDL_FreeSurface(tmpsurface);

    //initialisation de la map
    map m2(renderer);
    m = m2;

    //Initialisation du kit de soin
    s.setPos(25, 25);
    s.setFile("Data/kitDeSoin.png");
    s.setTexture(renderer, "Data/kitDeSoin.png");
    // t = new text() ;

    //Initialisation de la balle
    b.LoadBalle(renderer);
}

// void game::handleEvents()
// {
//     SDL_Event events;
//     float f=0;
//     double ang=0;
//     while(SDL_PollEvent(&events))
//     {
//         if (events.type == SDL_QUIT) isRunning=false;// Si l'utilisateur a clique sur la croix de fermeture
//         if (events.type == SDL_KEYDOWN)
//         {
//             if (events.key.keysym.sym == SDLK_w) {
//                 f=0.01;
//                 joueur.deplace(f,ang);
//             }
//             if (events.key.keysym.sym == SDLK_s) {
//                 f=-0.01;
//                 joueur.deplace(f,ang);
//             }
//             if (events.key.keysym.sym == SDLK_a) {
//                 ang=0.6;
//                 joueur.deplace(f,ang);
//             }
//             if (events.key.keysym.sym == SDLK_d) {
//                 ang=-0.6;
//                 joueur.deplace(f,ang);
//             }
//             if (events.key.keysym.sym == SDLK_ESCAPE){
//                 isRunning=false;
//             }
//             if (events.type == SDLK_x)
//             {
//                 //s.setPointDeVie(s.getPointDeVie()-10);
//                 //std::cout << "Point de vie : " << s.getPointDeVie() << std::endl ;
//                 std::cout << "pdv : " << joueur.getPdv() << std::endl ;

//                 std::cout << "position perso : " << joueur.getPos()->getComplexX() <<" "<< joueur.getPos()->getComplexY() << std::endl ;
//                 std::cout << "position kit x: " << s.getPosX() << "y :"<< s.getPosY() << std::endl ;
//             }
//         }
//         //joueur.deplace(f,ang);
//     }
// }

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
        f = -0.01;
    }
    if (keystates[SDL_SCANCODE_S])
    {
        f = 0.01;
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
    joueur.deplace(f, ang, m.collision, renderer);

    if (events.type == SDL_QUIT)
        isRunning = false; // Si l'utilisateur a clique sur la croix de fermeture
    if (keystates[SDL_SCANCODE_X])
    {
        //s.setPointDeVie(s.getPointDeVie()-10);
        //std::cout << "Point de vie : " << s.getPointDeVie() << std::endl ;
        std::cout << "pdv : " << joueur.getPdv() << std::endl;

        std::cout << "position perso : " << joueur.getPos()->getComplexX() << " " << joueur.getPos()->getComplexY() << std::endl;
        std::cout << "position kit x: " << s.getPosX() << "y :" << s.getPosY() << std::endl;
    }
    if (events.type == SDL_MOUSEBUTTONDOWN)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        // std::cout << "position souris : " << x << ", "<< y <<std::endl ;
        // b.setTexture(renderer,"Data/balle.png");
    }
    if (keystates[SDL_SCANCODE_SPACE])
    {
        b.setFire(true);
        b.setAngle(joueur.getAngle());
        b.setVit(joueur.getVit());
    }
}

// void game::heal()
// {
//      //SDL_bool col = SDL_HasIntersection(joueur.getRect(), s.getRect());
// }

void game::update()
{
    Complex pos = *joueur.getPos();
    Complex posS(s.getPosX(), s.getPosY());
    pos.Soustrait(&posS);
    if (pos.norme() < 1 && s.getPop())
    {
        joueur.setPdv(joueur.getPdv() + 10);
        s.setPop(false);
    }
    //b.tireBalle();
}

void game::render()
{
    SDL_RenderClear(renderer);
    //this is where we would add stuff to render
    m.drawMap(renderer, *joueur.getPos());

    if (s.getPop())
    {
        SDL_Rect testRct;
        testRct.x = (s.getPosX() - joueur.getPos()->getComplexX() + 6) * 64;
        testRct.y = (s.getPosY() - joueur.getPos()->getComplexY() + 5) * 64;
        testRct.h = testRct.w = 64;
        float x = (s.getPosX() - joueur.getPos()->getComplexX() + 6) * 64;
        float y = (s.getPosY() - joueur.getPos()->getComplexY() + 5) * 64;
        s.drawObjet(renderer, x, y);
        SDL_RenderDrawRect(renderer, &testRct);
    }

    b.updateBalle(renderer);
    //b.renderTexture(renderer);

    // t.setTexte("Point de vie",renderer,0,0);
    // std::string txtPdv=std::to_string(joueur.getPdv());
    // t.setTexte(txtPdv.c_str(),renderer,0,20);
    //SDL_RenderCopy(renderer,joueur.getTexture(),NULL,joueur.getRect());

    SDL_RenderCopyEx(renderer, joueur.getTexture(), NULL, joueur.getRect(), -joueur.getAngle(), NULL, SDL_FLIP_NONE);

    // TTF_CloseFont(t.getFont());
    SDL_RenderPresent(renderer);
}

void game::clean()
{
    s.~soin();
    //b.~balle();
    joueur.~personnage();
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
