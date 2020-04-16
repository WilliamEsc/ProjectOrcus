 #include "map.h"

map::map()
{

}

map::map(SDL_Renderer* renderer)
{
    // dirt->setFileName("Data/dirt.png");
    // water->setFileName("Data/water.png");
    // stone->setFileName("Data/stone.png");

    // dirt->setTexture(dirt->loadTexture(dirt->getFileName(),renderer));
    // water->setTexture(water->loadTexture(water->getFileName(),renderer));
    // stone->setTexture(stone->loadTexture(stone->getFileName(),renderer));


    mappng->setFileName("Data/carte2.png");
    mappng->setTexture(mappng->loadTexture(mappng->getFileName(),renderer));
    // tileset->setFileName("Data/tilesheetcomplete.png");
    // error->setFileName("Data/kitDeSoin.png");
    // tileset->setTexture(tileset->loadTexture(tileset->getFileName(),renderer));
    // error->setTexture(error->loadTexture(error->getFileName(),renderer));

    // loadCalque("Data/calque1.txt",calque1);
    // loadCalque("Data/calque2.txt",calque2);
    // loadCalque("Data/calque3.txt",calque3);
    loadCalque("Data/collision.txt",collision);
    dest.w = 32;
    dest.h = 32;
    src.w = SCREEN_WIDTH;
    src.h = SCREEN_HEIGHT;   
}

map::~map()
{

}

void map::loadCalque(const char* str,int calque[124][124])
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
        // int type1;
        // int type2;
        // int type3;
        // int i=0;
        // for (int row = posJ.getComplexY()-11 ; row < posJ.getComplexY()+12 ; row++)
        // {
        //     int j=0;
        //     for ( int column = posJ.getComplexX()-14 ; column < posJ.getComplexX()+12 ; column++ )
        //     {
        //         type1=0;
        //         type2=0;
        //         type3=0;

        //         dest.x = j * 32;
        //         dest.y = i * 32;

        //         if(row>=0 && column>=0 && row<100 && column<100){

        //             type1 =(int) calque1[row][column];
        //             type2 =(int) calque2[row][column];
        //             type3 =(int) calque3[row][column];
                    

        //             if(type1==-1 || type1>540){
        //                 error->renderTexture(error->getTexture(),rend,dest);
        //             }

        //             src.x=type1%27*64;
        //             src.y=type1/27*64;
        //             tileset->renderTexture(tileset->getTexture(),rend,src,dest);

        //             if(type2!=-1 || type2<540){
        //                 src.x=type2%27*64;
        //                 src.y=type2/27*64;
        //                 tileset->renderTexture(tileset->getTexture(),rend,src,dest);
        //             }

        //             if(type3!=-1 || type1<540){
        //                 src.x=type3%27*64;
        //                 src.y=type3/27*64;
        //                 tileset->renderTexture(tileset->getTexture(),rend,src,dest);
        //             }
        //         }
        //         else{
        //             water->renderTexture(water->getTexture(),rend,dest);
        //         }
        //          j++;
        //     }
        //     i++;
        // }
        src.x=posJ.getComplexX()*64-(SCREEN_WIDTH-64)/2;
        src.y=posJ.getComplexY()*64-(SCREEN_HEIGHT-64)/2;
        mappng->renderTextureSrc(mappng->getTexture(),rend,src);
}  
