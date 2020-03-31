#include "map.h"

map::map()
{

}

map::map(SDL_Renderer* renderer)
{
    dirt->setFileName("Data/dirt.png");
    water->setFileName("Data/water.png");
    stone->setFileName("Data/stone.png");

    dirt->setTexture(dirt->loadTexture(dirt->getFileName(),renderer));
    water->setTexture(water->loadTexture(water->getFileName(),renderer));
    stone->setTexture(stone->loadTexture(stone->getFileName(),renderer));

    loadCalque("Data/calque1.txt");
    dest.w = 32;
    dest.h = 32;   
}

map::~map()
{

}

void map::loadCalque(const char* str)
{
    	// for (int i=0;i<100;i++){
        //     for (int j=0;j<100;j++){
        //         carte[i][j]=1;
        //     }
        // }

    std::ifstream MonFichier(str);
    if(!MonFichier.is_open())
    {printf("erreur");
        exit(EXIT_FAILURE);}
    else{
    	for (int i=0;i<100;i++){
            for (int j=0;j<100;j++){
                MonFichier >> carte[i][j];
                printf("%i ",carte[i][j]);
            }
        }
    }
    MonFichier.close();
}

void map::drawMap(SDL_Renderer* rend,const Complex &posJ)
{
        char type;
        int i=0;
        for (int row = posJ.getComplexY()-12 ; row < posJ.getComplexY()+12 ; row++)
        {
            int j=0;
            for ( int column = posJ.getComplexX()-12 ; column < posJ.getComplexX()+12 ; column++ )
            {
                type=0;
                if(row>=0 && column>=0 && row<100 && column<100){
                type =carte[row][column];}

                dest.x = j * 32;
                dest.y = i * 32;
                j++;

                switch (type)
                {
                    case 0:
                        water->renderTexture(water->getTexture(),rend,water->getRect2(),dest.x,dest.y);
                        break;
                    
                    case 1: 
                        stone->renderTexture(stone->getTexture(),rend,stone->getRect2(),dest.x,dest.y);
                        break;
                    
                    case 66: 
                        dirt->renderTexture(dirt->getTexture(),rend,dirt->getRect2(),dest.x,dest.y);
                        break;

                    default:
                        water->renderTexture(water->getTexture(),rend,water->getRect2(),dest.x,dest.y);
                        break;
                }
            }
            i++;
        }    
}


