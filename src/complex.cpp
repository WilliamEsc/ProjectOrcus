#include "complex.h"
#include <math.h>

Complex::Complex()
{
    this->x = 0.0f;
    this->y = 0.0f;
}

Complex::Complex(const float xpos, const float ypos)
{
    this->x = xpos;
    this->y = ypos;
}

void Complex::setComplexXY(const float xpos, const float ypos)
{
    this->x = xpos;
    this->y = ypos;
}

void Complex::setComplexX(const float xpos)
{
    this->x = xpos;
}

void Complex::setComplexY(const float ypos)
{
    this->y = ypos;
}

float Complex::getComplexX() const
{
    return x;
}

float Complex::getComplexY() const
{
    return y;
}

float Complex::norme() const
{
    return sqrt(x * x + y * y);
}

Complex Complex::normalize() const
{
    return *this / norme();
}

void Complex::Ajout(const Complex *cplx)
{
    x += cplx->getComplexX();
    y += y + cplx->getComplexY();
}

void Complex::AjoutX(const float x2)
{
    x += x2;
}

void Complex::AjoutY(const float y2)
{
    y += y2;
}

void Complex::Soustrait(const Complex *cplx)
{
    x -= cplx->getComplexX();
    y -= cplx->getComplexY();
}

void Complex::Multiplie(const Complex *cplx)
{
    x = x * cplx->getComplexX() - y * cplx->getComplexY();
    y = x * cplx->getComplexY() + y * cplx->getComplexX();
}

void Complex::Multiplie(const float f)
{
    x *= f;
    y *= f;
}

void Complex::Divise(const float f)
{
    x /= f;
    y /= f;
}

bool Collision(const Complex &postmp, const int *collision,const float &min,const float &max)
{
    for (int i = postmp.getComplexY() - 1; i < postmp.getComplexY() + 1; i++)
    {
        for (int j = postmp.getComplexX() - 1; j < postmp.getComplexX() + 1; j++)
        {
            if (collision[(i * 124) + j] != -1)
            {
                if (( ///en haut a gauche
                        (j < postmp.getComplexX() + min && j + 1 > postmp.getComplexX() + min) &&
                        (i < postmp.getComplexY() + min && i + 1 > postmp.getComplexY() + min)) ||
                    ( ///en bas a droite
                        (j < postmp.getComplexX() + max && j + 1 > postmp.getComplexX() + max) &&
                        (i < postmp.getComplexY() + max && i + 1 > postmp.getComplexY() + max)) ||
                    ( ///en haut a droite
                        (j < postmp.getComplexX() + max && j + 1 > postmp.getComplexX() + max) &&
                        (i < postmp.getComplexY() + min && i + 1 > postmp.getComplexY() + min)) ||
                    ((j < postmp.getComplexX() + min && j + 1 > postmp.getComplexX() + min) &&
                     (i < postmp.getComplexY() + max && i + 1 > postmp.getComplexY() + max)))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

Complex operator+(const Complex &cplx1, const Complex &cplx2)
{
    Complex ret(cplx1.getComplexX() + cplx2.getComplexX(), cplx1.getComplexY() + cplx2.getComplexY());
    return ret;
}

Complex operator-(const Complex &cplx1, const Complex &cplx2)
{
    Complex ret(cplx1.getComplexX() - cplx2.getComplexX(), cplx1.getComplexY() - cplx2.getComplexY());
    return ret;
}

Complex operator*(const Complex &cplx1, const Complex &cplx2)
{
    float x = cplx1.getComplexX() * cplx2.getComplexX() - cplx1.getComplexY() * cplx2.getComplexY();
    float y = cplx1.getComplexX() * cplx2.getComplexY() + cplx1.getComplexY() * cplx2.getComplexX();
    Complex ret(x, y);
    return ret;
}

Complex operator*(const Complex &cplx1, const float f)
{
    Complex ret(cplx1.getComplexX() * f, cplx1.getComplexY() * f);
    return ret;
}

Complex operator*(const float f, const Complex &cplx1)
{
    Complex ret(cplx1.getComplexX() * f, cplx1.getComplexY() * f);
    return ret;
}

Complex operator/(const Complex &cplx1, const float f)
{
    Complex ret(cplx1.getComplexX() / f, cplx1.getComplexY() / f);
    return ret;
}