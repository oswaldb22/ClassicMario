/**
@brief Module gerant Mario.

@file Mario.h
@author Oswald BLASSOU : oswald.blassou@etu.univ-lyon1.fr Numero Etu : 11410660
@version 1.0
@date 2016/03/01
*/


#ifndef _MARIO_H
#define _MARIO_H

#include "winTxt.h"
#include "Position.h"
#include "Niveau.h"

/**
@brief Definition de la structure Mario qui est represente par sa position 2D et sa direction de 1 à 4
*/
typedef struct {

    Position posMario;
    int iDirection;

    float x,y;
    float dx,dy;
    short life;
     int onLedge;
     int onGround;
     int timerMort;
     int animFrame, facingLeft, slowingDown;

}Mario;

/*const Position MAR_POS_NIV_1 = { 1, 1};*/

/**
@brief Initialise Mario avec la position 0,0 et la direction 1 (direction par defaut).
@param[in, out] m pointeur de mario.
@return Aucun.
*/
void marInit(Mario *m);


/**
@brief Initialise m avec la postion p passe en parametre .
@param[in, out] m pointeur de mario.
@param[in] p pointeur de position.
@return Aucun.
@warning .
*/
void marSetPosition(Mario *m, const Position *p);



/**
@brief retourne la  position de Mario qui contient ses coordonnées.
@param[in, out] m pointeur sur Mario.
@return position.
*/
Position marGetPosition(const Mario *m);


/**
@brief modifie la direction de Mario avec la valeur de direction.
@param[in, out] m pointeur sur Mario.
@param[in] direction nouvelle direction pour Mario en mode donnee
@return aucun.
@warning direction prend ses valeur dans (1,2,3,4).
*/
void marSetDirection(Mario *m, const int direction);


/**
@brief retourne la  direction de Mario.
@param[in, out] m pointeur sur Mario.
@return int.
*/
int marGetDirection(const Mario *m);


/**
@brief Modifie la position de Mario dans le terrain vers la gauche d'un caractere .
@param[in, out] m pointeur sur Mario.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
void marGauche(Mario *m, const Niveau *n);


/**
@brief Modifie la position de Mario dans le terrain vers la droite d'un caractere .
@param[in, out] m pointeur sur Mario.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
void marDroite(Mario *m, const Niveau *n);


/**
@brief Modifie la position de Mario dans le terrain vers le haut d'un caractere .
@param[in, out] m pointeur sur Mario.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
void marHaut(Mario *m, const Niveau *n);


/**
@brief Modifie la position de Mario dans le terrain vers le bas d'un caractere .
@param[in, out] m pointeur sur Mario.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
void marBas(Mario *m, const Niveau *n);


/**
@brief Modifie la position de Mario dans le terrain vers le haut et bas de 2 caracteres .
@param[in, out] m pointeur sur Mario.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
void marSaut(Mario *m, const Niveau *n);

/**
@brief Modifie la position de Mario si Mario se trouve sur une case non valide .
@param[in, out] m pointeur sur Mario.
@param[in, out] n pointeur sur Niveau.
@return Aucun.
*/
void marTombe(Mario *m,const Niveau *n);

/**
@brief Test des fonctions avec plusieurs cas.
@param Aucun.
@return Aucun.
@warning im doit être intitialisé, les champs de couleur doivent être compris entre 0 et 255.
*/

/**
@brief Permet de faire les test de  Toutes les fonctions du module Mario.
@param Aucun.
@return Aucun.
@warning m doit être intitialisé postion positive et direction comprise entre (1,4)
*/
void marTestRegression();

#endif /*_MARIO_H*/
