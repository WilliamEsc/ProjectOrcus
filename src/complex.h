#ifndef COMPLEX_H
#define COMPLEX_H

/*! \class Complex
* \brief Une classe complexe qui contient tout les opérateurs de calculs
*/
class Complex
{
private:
    float x, y; ///< Un complexe possède une composante en x et une en y

public:
    Complex();                             ///< constructeur par défault
    Complex(const float x, const float y); ///< constructeur avec un x et y passé en paramètre

    void setComplexXY(const float x, const float y); ///< procédure qui permet de changer les valeurs en x et y d'un complexe
    void setComplexX(const float x);                 ///< procédure qui permet de changer la valeur en x d'un complexe
    void setComplexY(const float y);                 ///< procédure qui permet de changer la valeur en y d'un complexe
    float getComplexX() const;                       ///< fonction qui retourne la valeur en x
    float getComplexY() const;                       ///< fonction qui retourne la valeur en y

    float norme() const;       ///< fonction qui retourne la norme d'un complexe
    Complex normalize() const; ///< ...

    /**modifie le complex directement
 * */

    void Ajout(const Complex *cplx);
    ///< procédure qui additionne le complexe avec celui passé en paramètre
    void AjoutX(const float x);
    ///< procédure qui additione la composante x du complexe avec une constante passée en paramètre
    void AjoutY(const float y);
    ///< procédure qui additione la composante y du complexe avec une constante passée en paramètre
    void Soustrait(const Complex *cplx);
    ///< procédure qui soustrait le complexe avec celui passé en paramètre
    void Multiplie(const Complex *cplx);
    ///< procédure qui multiplie le complexe avec celui passé en paramètre
    void Multiplie(const float f);
    ///< procédure qui multiplie le complexe avec une constante passée en paramètre
    void Divise(const float f);
    ///< pprocédure qui divise le complexe avec une constante passée en paramètre
};

/**renvoie un complex
 * */

Complex operator+(const Complex &cplx1, const Complex &cplx2);
///< somme de deux complexes
Complex operator-(const Complex &cplx1, const Complex &cplx2);
///< soustraction de deux complexes
Complex operator*(const Complex &cplx1, const Complex &cplx2);
///< produit de deux complexes
Complex operator*(const Complex &cplx1, const float f);
///< produit d'un complex et d'une constante
Complex operator*(const float f, const Complex &cplx1);
///< produit d'une constante et d'un complexe
Complex operator/(const Complex &cplx1, const float f);
///< division d'un complexe et d'une constante

/**
 *\brief verifie que pos est dans un endroit valide
 * @param pos complex: position a testé.
 * @param collision pointer de tableau d'int: map des endroit non valide.
 * @param min float: deplacement necessaire pour avoir le côté superieur gauche de la hitbox par rapport au complex postmp.
 * @param max float: deplacement necessaire pour avoir le côté inferieur droit de la hitbox par rapport au complex postmp.
 */
bool Collision(const Complex &postmp, const int *collision, const float &min, const float &max);
#endif
