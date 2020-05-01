#include "ennemie.h"

ennemie::ennemie(const float &x, const float &y, const Complex &posJ, const int &t) : personnage(x, y)
{
    depl = NULL;
    type = t;
    rangeAtck = 2;
    delayAtck = 3;
    rangeAgro = 4;
    degat=10;
    lastAtck = 0.0;
    vitDepl = 0.002;
    persos->setDest((pos->getComplexX() - posJ.getComplexX() + 6) * 64, (pos->getComplexY() - posJ.getComplexY() + 5) * 64);
}

ennemie::~ennemie()
{
    delete depl;
    depl = NULL;
}

void ennemie::setDepl(Complex *cplx)
{
    if (cplx == NULL)
        delete depl;
    depl = cplx;
}
void ennemie::setType(const int &t)
{
    type = t;
}
void ennemie::setRangeAtck(const int &t)
{
    rangeAtck = t;
}
void ennemie::setDelayAtck(const int &t)
{
    delayAtck = t;
}
void ennemie::setRangeAgro(const int &t)
{
    rangeAgro = t;
}
void ennemie::setVitDepl(const float &t)
{
    vitDepl = t;
}
void ennemie::setLastAtck(const float &t)
{
    lastAtck = t;
}
void ennemie::setDegat(const int & i)
{
    degat=i;
}

Complex *ennemie::getDepl() const
{
    return depl;
}
int ennemie::getType() const
{
    return type;
}
int ennemie::getRangeAtck() const
{
    return rangeAtck;
}
int ennemie::getDelayAtck() const
{
    return delayAtck;
}
int ennemie::getRangeAgro() const
{
    return rangeAgro;
}
int ennemie::getDegat() const
{
    return degat;
}
float ennemie::getVitDepl() const
{
    return vitDepl;
}
float ennemie::getLastAtck() const
{
    return lastAtck;
}

void ennemie::deplaceVersJoueur(const Complex &posJ, const int *collision)
{
    Complex tr = posJ - *pos;
    if (tr.norme() > 1)
    {
        Complex postmp = *pos + tr.normalize() * vitDepl;
        if (!Collision(postmp, collision))
        {
            pos->setComplexX(postmp.getComplexX());
            pos->setComplexY(postmp.getComplexY());
        }
    }
}

void ennemie::tourneVersJoueur(const Complex &posJ)
{
    Complex tr = posJ - *pos;
    double cos = acos(tr.getComplexX() / tr.norme());
    if (tr.getComplexY() <= 0)
        angle = -90 + cos * 180 / 3.14;
    else
    {
        angle = -90 - cos * 180 / 3.14;
    }
}

bool ennemie::aggro(const Complex &posJ) const
{
    return (posJ - *pos).norme() < rangeAgro;
}

bool ennemie::atckJoueur(const Complex &posJ)
{
    if ((posJ - *pos).norme() < rangeAtck)
    {
        if ((clock() - lastAtck)/CLOCKS_PER_SEC >= delayAtck)
        {
            lastAtck = clock();
            return true;
        }
        return false;
    }
    return false;
}

void ennemie::deplacement(const int *collision)
{
    switch (type)
    {
    case 0:
        deplacementDebilos(collision);
        break;

    case 1:
        deplacementRando(collision);
        break;

    default:
        break;
    }
}

void ennemie::deplacementDebilos(const int *collision)
{
    if (depl == NULL)
    {
        float x = ((rand() % 3) - 1);
        float y = ((rand() % 3) - 1);
        if (x == 0)
            x += 0.001;
        if (y == 0)
            y += 0.001;
        depl = new Complex(pos->getComplexX() + x / 3, pos->getComplexY() + y / 3);
    }
    if ((pos->getComplexX() >= depl->getComplexX() - 0.1 &&
         pos->getComplexX() <= depl->getComplexX() + 0.1) &&
        (pos->getComplexY() >= depl->getComplexY() - 0.1 &&
         pos->getComplexY() <= depl->getComplexY() + 0.1))
    {
        float x = ((rand() % 3) - 1);
        float y = ((rand() % 3) - 1);
        if (x == 0)
            x += 0.001;
        if (y == 0)
            y += 0.001;
        depl->setComplexXY(pos->getComplexX() + x / 3, pos->getComplexY() + y / 3);
    }
    Complex tr = *depl - *pos;
    Complex postmp = *pos + tr.normalize() * vitDepl / 5;
    if (!Collision(postmp, collision))
    {
        pos->setComplexX(postmp.getComplexX());
        pos->setComplexY(postmp.getComplexY());
    }
    else
    {
        delete depl;
        depl = NULL;
    }
}

void ennemie::deplacementRando(const int *collision)
{
    if (depl == NULL)
    {
        float x = ((rand() % 123) + 1);
        float y = ((rand() % 123) + 1);
        depl = new Complex(x, y);
    }
    if ((pos->getComplexX() >= depl->getComplexX() - 1 &&
         pos->getComplexX() <= depl->getComplexX() + 1) &&
        (pos->getComplexY() >= depl->getComplexY() - 1 &&
         pos->getComplexY() <= depl->getComplexY() + 1))
    {
        float x = ((rand() % 123) + 1);
        float y = ((rand() % 123) + 1);
        depl->setComplexXY(x, y);
    }
    Complex tr = *depl - *pos;
    Complex postmp = *pos + tr.normalize() * vitDepl / 2;
    double cos = acos(tr.getComplexX() / tr.norme());
    if (tr.getComplexY() <= 0)
        angle = -90 + cos * 180 / 3.14;
    else
    {
        angle = -90 - cos * 180 / 3.14;
    }
    if (!Collision(postmp, collision))
    {
        pos->setComplexX(postmp.getComplexX());
        pos->setComplexY(postmp.getComplexY());
    }
    else
    {
        delete depl;
        depl = NULL;
    }
}
