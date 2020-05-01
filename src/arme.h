#ifndef ARME_H
#define ARME_H

#include "balle.h"
#include "personnage.h"

class arme
{
    private:

        clock_t lastAtck;
        float cadence;
        float force;
        int degat;
        std::vector<balle*> bul;
        SDL_Texture* tex;

    public:

        arme();
        ~arme();

        int getDegat()const;
        float getlastAtck()const;
        balle* getBalle(const unsigned int & i)const;
        float getCadence() const;
        float getForce()const;
        SDL_Texture* getTexture()const;

        void setTexture(SDL_Renderer *render,const char* file);
        void setForce(const float & f);
        void setDegat(const int & dmg);
        void setLastAtck(const float & f);
        void setBalle(const balle & b);
        void setCadence(const float & f);
        void setTextureBalle(SDL_Renderer* render,const char * file);

        void tir(SDL_Renderer *render,const Complex &pos,const Complex &vit,const float & angle);
        void update(SDL_Renderer* render);
        void rendering(SDL_Renderer* render,const Complex & pos);
        bool Hit(const Complex & pos);
};


#endif
