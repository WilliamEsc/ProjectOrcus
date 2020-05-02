#ifndef ARME_H
#define ARME_H

#include "balle.h"
#include "personnage.h"

/*! \class arme
* \brief l'arme du joueur qui permettera d'effectuer les tirs
*/
class arme
{
private:
    clock_t lastAtck;         ///< timer de la derniere attaque
    float cadence;            ///< cadence de tir de l'arme
    float force;              ///< vitesse de déplacement des balles
    int degat;                ///< degats des balles
    std::vector<balle *> bul; ///< tableau dynamique de pointer de balle
    SDL_Texture *tex;         ///< texture des balles

public:
    /**
     *\brief Constructeur de la classe arme
     */
    arme();
    /**
     *\brief destructeur de la classe arme
     */
    ~arme();

    /**
     *\brief accesseur de degat de la classe arme
     */
    int getDegat() const;
    /**
     *\brief accesseur de lastAtck(derniere attaque) de la classe arme
     */
    float getlastAtck() const;
    /**
     *\brief mutateur d'une balle de la classe arme
     * @param i unsigned int: indice de la balle a changé.rien ne sera fait si l'indice de la balle est erroné.
     */
    balle *getBalle(const unsigned int &i) const;
    /**
     *\brief accesseur de cadende de la classe arme
     */
    float getCadence() const;
    /**
     *\brief accesseur de force de la classe arme
     */
    float getForce() const;
    /**
     *\brief accesseur de tex(ture) de la classe arme
     */
    SDL_Texture *getTexture() const;

    /**
     *\brief mutateur de tex(ture) de la classe arme
     * @param render SDL_Renderer: le renderer de la fenetre SDL.
     * @param file pointer de char: nom du fichier image pour la textures.
     */
    void setTexture(SDL_Renderer *render, const char *file);
    /**
     *\brief mutateur de force de la classe arme
     * @param f float: force qui sera donné a l'arme.
     */
    void setForce(const float &f);
    /**
     *\brief mutateur de degat de la classe arme
     * @param dmg int: degat qui sera donné a l'arme.
     */
    void setDegat(const int &dmg);
    /**
     *\brief mutateur de lastAtck de la classe arme
     * @param f float: timer qui sera donner a lastAtck de la classe arme.
     */
    void setLastAtck(const float &f);
    /**
     *\brief Ajoute une balle au vector bul de la classe arme
     * @param b balle: une copie de b sera créé sur le tas et donné au vector bul.
     */
    void setBalle(const balle &b);
    /**
     *\brief mutateur de cadence de la classe arme
     * @param f float: sera donné a cadence de l'arme.
     */
    void setCadence(const float &f);

    /**
     *\brief Crée une nouvelle balle dans vector si le temps écoulé depuis la deriere balle tiré est supérier a la cadence
     * @param pos Complex: position du tireur qui sera donné a la balle.
     * @param vit Complex: vit servira de direction a la balle créer.
     * @param angle float: angle servira a l'affichage dans le bon sens de la balle.
     */
    void tir(const Complex &pos, const Complex &vit, const float &angle);
    /**
     *\brief met a jour les position de toute les balles dans le vector bul
     * @param render SDL_Renderer: le renderer de la fenetre SDL..
     */
    void update(SDL_Renderer *render);
    /**
     *\brief affiche dans la fenetre SDL les balles par rapport a la position du joueur.
     * @param render SDL_Renderer: le renderer de la fenetre SDL..
     * @param pos Compex: position du joueur.
     */
    void rendering(SDL_Renderer *render, const Complex &pos);
    /**
     *\brief Appel de la fonction Hit de chaque balle renvoie true des qu'une des fonctions renvoie true, false dans le cas contraire
     * @param pos Complex: position de la cible.
     */
    bool Hit(const Complex &pos);
};

#endif
