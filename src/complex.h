#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
    private:
    float x,y;

    public:

    Complex();
    Complex(const float x,const float y);

    void setComplexXY(const float x,const float y);
    void setComplexX(const float x);
    void setComplexY(const float y);
    float getComplexX()const ;
    float getComplexY()const ;

    float norme()const ;
    Complex normalize()const ;


/**modifie le complex directement
 * */
    void Ajout(const Complex* cplx);
    void AjoutX(const float x);
    void AjoutY(const float y);
    void Soustrait(const Complex* cplx);
    void Multiplie(const Complex* cplx);
    void Multiplie(const float f);
    void Divise(const float f);
};

/**renvoie un complex
 * */
Complex operator+(const Complex& cplx1,const Complex& cplx2);
Complex operator-(const Complex& cplx1,const Complex& cplx2);
Complex operator*(const Complex& cplx1,const Complex& cplx2);
Complex operator*(const Complex& cplx1,const float f);
Complex operator*(const float f,const Complex& cplx1);
Complex operator/(const Complex& cplx1,const float f);
#endif 