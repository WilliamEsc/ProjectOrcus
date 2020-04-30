#ifndef ENNEMIE_H
#define ENNEMIE_H

#include "complex.h"
#include "personnage.h"


class ennemie: public personnage
{
    protected:
    
    int type,rangeAtck,delayAtck,rangeAgro;
    float vitDepl;
    std::time_t lastAtck;
    Complex* depl;

    public:

    ennemie(const float & x,const float & y,const Complex & posJ,const int & t);
    ~ennemie();

    void setDepl(Complex* cplx);
    void setType(const int & t);
    void setRangeAtck(const int & t);
    void setDelayAtck(const int & t);
    void setRangeAgro(const int & t);
    void setVitDepl(const float & t);
    void setLastAtck(const std::time_t & t);

    Complex* getDepl() const;
    int getType()const;
    int getRangeAtck()const;
    int getDelayAtck()const;
    int getRangeAgro()const;
    float getVitDepl()const;
    std::time_t getLastAtck()const;

    void deplaceVersJoueur(const Complex & posJ,const int* collision);
    void tourneVersJoueur(const Complex & posJ);
    bool aggro(const Complex & posJ) const;
    bool atckJoueur(const Complex & posJ);
    void deplacement(const int* collision);

    void deplacementDebilos(const int* collision);
    void deplacementRando(const int* collision);
    void deplacementGuard(const int* collision);
};

#endif 