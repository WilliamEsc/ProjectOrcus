#include "arme.h"

arme::arme()
{
    lastAtck = 0.0;
    force = 0.05;
    cadence = 0.8;
    degat = 35;
}

arme::~arme()
{
    for (size_t i = 0; i < bul.size(); i++)
        delete bul[i];
}

int arme::getDegat() const
{
    return degat;
}

float arme::getForce() const
{
    return force;
}

void arme::setForce(const float &f)
{
    force = f;
}

float arme::getlastAtck() const
{
    return lastAtck;
}

balle *arme::getBalle(const unsigned int &i) const
{
    if (bul.size() < i)
        return bul[i];
    return NULL;
}

float arme::getCadence() const
{
    return cadence;
}

void arme::setDegat(const int &dmg)
{
    degat = dmg;
}

void arme::setLastAtck(const float &f)
{
    lastAtck = f;
}

void arme::setBalle(const balle &b)
{
    balle *newBalle = new balle(force);
    *newBalle = b;
    bul.push_back(newBalle);
}

void arme::setCadence(const float &f)
{
    cadence = f;
}

void arme::tir(SDL_Renderer *render, const Complex &pos, const Complex &vit, const float &angle)
{
    float ti = (clock() - lastAtck);
    if (ti / CLOCKS_PER_SEC > cadence)
    {
        balle *newBalle = new balle(force);
        newBalle->Fire(pos, vit);
        newBalle->setAngle(angle);
        bul.push_back(newBalle);
        lastAtck = clock();
    }
}

void arme::update(SDL_Renderer *render)
{
    for (size_t i = 0; i < bul.size(); i++)
    {
        bul[i]->updateBalle(render);
        if (!bul[i]->getPop())
        {
            delete bul[i];
            bul.erase(bul.begin() + i);
        }
    }
}

void arme::rendering(SDL_Renderer *render, const Complex &pos)
{
    for (size_t i = 0; i < bul.size(); i++)
    {
        bul[i]->renderBalle(render, pos, tex);
    }
}

bool arme::Hit(const Complex &pos)
{

    for (size_t i = 0; i < bul.size(); i++)
    {
        if (bul[i]->Hit(pos))
            return true;
    }
    return false;
}

SDL_Texture * arme::getTexture() const
{
    return tex;
}

void arme::setTexture(SDL_Renderer *ren,const char *file)
{
    SDL_Surface *surface = IMG_Load(file);

    if (surface != nullptr)
    {
        tex = SDL_CreateTextureFromSurface(ren, surface);
        SDL_FreeSurface(surface);
        if (tex == nullptr)
        {
            std::cout << " error CreateTextureFromSurface " << std::endl;
        }
        else
        {
            std::cout << file << " Image load " << std::endl;
        }
    }
    else
    {
        std::cout << file << " Erreur Surface " << std::endl;
    }
}