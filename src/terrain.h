#ifndef TERRAIN_H
#define TERRAIN_H

#include "obstacle.h"

class terrain
{
private:
    /* data */
    obstacle *tab;

public:
    terrain();
    ~terrain();
    void affichage();
};

#endif