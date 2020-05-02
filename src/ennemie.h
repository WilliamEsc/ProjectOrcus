#ifndef ENNEMIE_H
#define ENNEMIE_H

#include "complex.h"
#include "personnage.h"

/*! \class ennemie
* \brief classe représentant les ennemies
*/
class ennemie : public personnage
{
protected:
    int type, rangeAtck, delayAtck, rangeAgro, degat; ///< type, portée de l'attaque, delais entre le attaque, portée de l'agro, dégat de l'ennemie
    float vitDepl;                                    ///< vitesse de deplacement de l'ennemie
    clock_t lastAtck;                                 ///< temps de la derniere attaque
    Complex *depl;                                    ///< position vers laquelle se dirige l'ennemie en cas de deplacement debilos ou rando

public:
    /**
     *\brief constructeur de la classe ennemie
     * @param x float: position x du personnage.
     * @param y float: position y du personnage.
     * @param posJ Complex: positionnement du rect dest de la texture par rapport a posJ.
     * @param t int: type de l'ennemie 0:debilos 1:rando.
     */
    ennemie(const float &x, const float &y, const Complex &posJ, const int &t);
    /**
     *\brief destructeur de la classe ennemie
     */
    ~ennemie();
    /**
     *\brief mutateur du pointer de complex depl de l'ennemie
     * @param cplx pointer de complex: doit être alloué sur le tas l'addresse sera donné a depl.
     */
    void setDepl(Complex *cplx);
    /**
     *\brief mutateur du type de l'ennemie
     * @param t int: t sera donné au type de l'ennemie.
     */
    void setType(const int &t);
    /**
     *\brief mutateur de rangeAtck de l'ennemie
     * @param t int: t sera donné a rangeAtck de l'ennemie
     */
    void setRangeAtck(const int &t);
    /**
     *\brief mutateur de delayAtck de l'ennemie
     * @param t int: t sera donné a delayAtck de l'ennemie
     */
    void setDelayAtck(const int &t);
    /**
     *\brief mutateur de rangeAgro de l'ennemie
     * @param t int: t sera donné a rangeAgro de l'ennemie
     */
    void setRangeAgro(const int &t);
    /**
     *\brief mutateur de vitDepl de l'ennemie
     * @param t float: t sera donné a vitDepl de l'ennemie
     */
    void setVitDepl(const float &t);
    /**
     *\brief mutateur de lastAtck de l'ennemie
     * @param t float: t sera donné a lastAtck de l'ennemie
     */
    void setLastAtck(const float &t);
    /**
     *\brief mutateur de degat de l'ennemie
     * @param i int: i sera donné a degat de l'ennemie
     */
    void setDegat(const int &i);

    /**
     *\brief accesseur du pointer de Complex Depl de l'ennemie
     */
    Complex *getDepl() const;
    /**
     *\brief accesseur de l'int type de l'ennemie
     */
    int getType() const;
    /**
     *\brief accesseur de l'int rangeAtck de l'ennemie
     */
    int getRangeAtck() const;
    /**
     *\brief accesseur de l'int delayAtck de l'ennemie
     */
    int getDelayAtck() const;
    /**
     *\brief accesseur de l'int rangeAgro de l'ennemie
     */
    int getRangeAgro() const;
    /**
     *\brief accesseur de l'int degat de l'ennemie
     */
    int getDegat() const;
    /**
     *\brief accesseur du float vitDepl de l'ennemie
     */
    float getVitDepl() const;
    /**
     *\brief accesseur du float rangeAtck de l'ennemie
     */
    float getLastAtck() const;

    /**
     *\brief Deplacement de l'ennemie vers le complex posJ
     * l'ennemie sera stopé si il rencontre un obstacle durant sa course
     * @param posJ Complex: position vers laquelle l'ennemie doit s'approcher.
     * @param collision pointer de tableau int: tableau des collisions de la carte.
     */
    void deplaceVersJoueur(const Complex &posJ, const int *collision);
    /**
     *\brief calcul l'angle pour l'affichage de l'ennemie
     * @param posJ Complex: position vers laquelle l'ennemie doit se tourner.
     */
    void tourneVers(const Complex &posJ);
    /**
     *\brief renvoie true si la position du joueur est assez proche de la position de l'ennemie
     * @param posJ complex: position du joueur.
     */
    bool aggro(const Complex &posJ) const;
    /**
     *\brief renvoie true si le joueur est assez proche et si le temps depuis la derniere attaque(lastAtck) est > a delayAtck, false sinon
     * @param x float: position x de la cles.
     */
    bool atckJoueur(const Complex &posJ);
    /**
     *\brief choisi le deplacement selon le type de l'ennemie
     * @param collision pointer de tableau int: tableau des collisions de la carte.
     */
    void deplacement(const int *collision);

    /**
     *\brief deplacement des ennemies de type=0 les debilos
     * @param collision pointer de tableau int: tableau des collisions de la carte.
     */
    void deplacementDebilos(const int *collision);
    /**
     *\brief deplacement des ennemies de type=1 les rando
     * @param collision pointer de tableau int: tableau des collisions de la carte.
     */
    void deplacementRando(const int *collision);
};

#endif