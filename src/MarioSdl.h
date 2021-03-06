/**
@brief Module gerant MarioSdl.

@file MarioSdl.h
@author Oswald BLASSOU : oswald.blassou@etu.univ-lyon1.fr Numero Etu : 11410660
@version 1.0
@date 2016/03/01
*/


#ifndef _MARIOSDL_H
#define _MARIOSDL_H

#include "defs.h"
#include "PositionSdl.h"
#include "NiveauSdl.h"

/**
@brief Definition de la structure MarioSdl qui est represente par sa position 2D et sa direction de 1 à 4
*/
typedef struct {

    PositionSdl posMario;
    int iDirection;

     float x,y;
     float dx,dy;
     short life;
     int onGround;
     int timerMort;

     int animFrame, facingLeft, slowingDown;

}MarioSdl;


/**
@brief Initialise MarioSdl avec la position 0,0 et la direction 1 (direction par defaut).
@param[in, out] m pointeur de mario.
@return Aucun.
*/
void marInit(MarioSdl *m);


/**
@brief Initialise m avec la postion p passe en parametre .
@param[in, out] m pointeur de mario.
@param[in] p pointeur de position.
@return Aucun.
@warning .
*/
void marSetPositionSdl(MarioSdl *m, const PositionSdl *p);



/**
@brief retourne la  position de MarioSdl qui contient ses coordonnées.
@param[in, out] m pointeur sur MarioSdl.
@return position.
*/
PositionSdl marGetPositionSdl(const MarioSdl *m);


/**
@brief modifie la direction de MarioSdl avec la valeur de direction.
@param[in, out] m pointeur sur MarioSdl.
@param[in] direction nouvelle direction pour MarioSdl en mode donnee
@return aucun.
@warning direction prend ses valeur dans (1,2,3,4).
*/
void marSetDirection(MarioSdl *m, const int direction);


/**
@brief retourne la  direction de MarioSdl.
@param[in, out] m pointeur sur MarioSdl.
@return int.
*/
int marGetDirection(const MarioSdl *m);


/**
@brief Modifie la position de MarioSdl dans le terrain vers la gauche d'un caractere .
@param[in, out] m pointeur sur MarioSdl.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
void marGauche(MarioSdl *m, const Niveau *n);


/**
@brief Modifie la position de MarioSdl dans le terrain vers la droite d'un caractere .
@param[in, out] m pointeur sur MarioSdl.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
void marDroite(MarioSdl *m, const Niveau *n);


/**
@brief Modifie la position de MarioSdl dans le terrain vers le haut d'un caractere .
@param[in, out] m pointeur sur MarioSdl.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
void marHaut(MarioSdl *m, const Niveau *n);


/**
@brief Modifie la position de MarioSdl dans le terrain vers le bas d'un caractere .
@param[in, out] m pointeur sur MarioSdl.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
void marBas(MarioSdl *m, const Niveau *n);


/**
@brief Modifie la position de MarioSdl dans le terrain vers le haut et bas de 2 caracteres .
@param[in, out] m pointeur sur MarioSdl.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
void marSaut(MarioSdl *m, const Niveau *n);

/**
@brief Modifie la position de MarioSdl si MarioSdl se trouve sur une case non valide .
@param[in, out] m pointeur sur MarioSdl.
@param[in, out] n pointeur sur Niveau.
@return Aucun.
*/
void marTombe(MarioSdl *m,const Niveau *n);

/**
@brief Test des fonctions avec plusieurs cas.
@param Aucun.
@return Aucun.
@warning im doit être intitialisé, les champs de couleur doivent être compris entre 0 et 255.
*/


#endif /*_MARIOSDL_H*/
