#ifndef BALLE_H
#define BALLE_H

#include "objet.h"
#include "personnage.h"

class balle : public objet
{
private:

    Complex* posInit;
    Complex* vit;
    double angle;
    float f ;

public:

    /**
     *\brief Constructeur de la classe balle
     */
    balle();

    /**
     *\brief Constructeur de la classe balle
     * @param fl float: force qui sera donner a la balle.
     */
    balle(const float & fl);

    /**
     *\brief Destructeur de la classe balle
     */
    ~balle();

    /**
     *\brief accesseur du pointer Vit
     */
    Complex* getVit() const;

    /**
     *\brief mutateur du pointer Vit
     * @param j pointer de complex: un pointer sur un complex qui sera donné au pointer Vit de la balle.
     */
    void setVit(Complex* j);

    /**
     *\brief accesseur de l'angle de la balle
     */
    double getAngle()const;
    /**
     *\brief mutateur de l'angle de la balle
     * @param angle double: angle de rotation de l'image de la balle.
     */
    void setAngle(double angle);

    /**
     *\brief accesseur de la force de la balle
     */
    float getForce()const;

    /**
     *\brief mutateur de la force de la balle
     * @param fl reel: force qui sera donner a la balle.
     */
    void setForce(const float & fl);

    /**
     *\brief accesseur de la position x du rectangle sdl de destination
     */
    float getDestRectX();
    /**
     *\brief accesseur de la position y du rectangle sdl de destination
     */
    float getDestRectY();

    /**
     *\brief mutateur de la position x du rectangle sdl de destination
     * @param x float: position x qui sera donné au rectangle de destination.
     */
    void setDestRectX(float x);

    /**
     *\brief mutateur de la position y du rectangle sdl de destination
     * @param y float: position y qui sera donné au rectangle de destination.
     */
    void setDestRectY(float y);   

    /**
     *\brief initialise une balle
     * @param pos Complex: position initial de la balle.
     * @param vit Complex: vitesse(direction) qui sera donné a la balle.
     */
    void Fire(const Complex &pos,const Complex &vit);

    /**
     *\brief met a jour la position de la balle
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     */
    void updateBalle(SDL_Renderer* ren);
    /**
     *\brief affiche la balle dans la fenetre SDL (n'utilisera pas sa texture pour des soucis de performances)
     * @param ren SDL_Renderer: le renderer de la fenetre SDL.
     * @param posJ Complex: sert pour calculer la position d'affichage par rapprt au joueur.
     * @param texture SDL_Texture: la texture qui sera affiché pour la balle.
     */
    void renderBalle(SDL_Renderer *ren,const Complex & posJ,SDL_Texture* texture);

    /**
     *\brief retourne true si la balle et le complex pos sont assez proche
     * @param pos Complex: force qui sera donner a la balle.
     */
    bool Hit(const Complex & pos);
};

#endif
