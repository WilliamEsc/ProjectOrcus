#ifndef HERO_H
#define HERO_H

#include "complex.h"
#include "personnage.h"

class hero: public personnage
{
    private:


    public:

    hero();
    ~hero();

    void ajoutAngle(const double & deg);
    void deplace(const float & f,const double & ang,const int* collision);
};

#endif 