 #include "map.h"

map::map()
{

}

map::map(SDL_Renderer* renderer)
{

    mappng->setFileName("Data/carte2.png");
    mappng->setTexture(mappng->loadTexture(renderer));
    // tileset->setFileName("Data/tilesheetcomplete.png");
    // error->setFileName("Data/kitDeSoin.png");
    // tileset->setTexture(tileset->loadTexture(tileset->getFileName(),renderer));
    // error->setTexture(error->loadTexture(error->getFileName(),renderer));

    loadCollision("Data/collision.txt");
    mappng->setSrc(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
}

map::~map()
{
    delete Collision;
    delete mappng;
    mappng=NULL;
}

void map::setMapPng(SDL_Renderer* renderer,const char * file)
{
    mappng->setFileName(file);
    mappng->setTexture(mappng->loadTexture(renderer));
}

texture* map::getMapPNG()const
{
    return mappng;
}

void map::setCollision(const int & i,const int & j,const int & val)
{
    int x=(i*124)+j;
    Collision[x]=val;
}

int* map::getCollision()const
{
    return Collision;
}
int map::getCollision(const int & i,const int & j)const
{
    int x=(i*124)+j;
    return Collision[x];
}

void map::loadCollision(const char* str)
{
    std::ifstream MonFichier(str);
    if(!MonFichier.is_open())
    {printf("erreur");
        exit(EXIT_FAILURE);}
    else{
    	for (int i=0;i<15376;i++){
                MonFichier >> Collision[i];
                // printf("%i ",calque[i][j]);
        }
    }
    MonFichier.close();
}


void map::loadCalque(const char* str,int calque[][124])
{
    std::ifstream MonFichier(str);
    if(!MonFichier.is_open())
    {printf("erreur");
        exit(EXIT_FAILURE);}
    else{
    	for (int i=0;i<124;i++){
            for (int j=0;j<124;j++){
                MonFichier >> calque[i][j];
                // printf("%i ",calque[i][j]);
            }
        }
    }
    MonFichier.close();
}

void map::drawMap(SDL_Renderer* rend,const Complex &posJ)
{
        mappng->setSrc(posJ.getComplexX()*64-(SCREEN_WIDTH-64)/2,posJ.getComplexY()*64-(SCREEN_HEIGHT-64)/2);
        mappng->renderTextureNoDest(rend);
}