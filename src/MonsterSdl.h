/**
@brief Module gerant MonsterSdl.

@file MonsterSdl.h
@author Oswald BLASSOU : oswald.blassou@etu.univ-lyon1.fr Numero Etu : 11410660
@version 1.0
@date 2016/03/01
*/


#ifndef _MONSTERSDL_H
#define _MONSTERSDL_H

#include "defs.h"

#include "PositionSdl.h"
#include "NiveauSdl.h"

/**
@brief Definition de la structure MonsterSdl qui est represente par sa position 2D et sa direction de 1 à 4
*/
typedef struct {

    PositionSdl posMonster;
    int iDirection;

     float x,y;
     float dx,dy;
     short life;
     int onGround;
     int timerMort;

     int animFrame, facingLeft, slowingDown;

}MonsterSdl;


/**
@brief Initialise MonsterSdl avec la position 0,0 et la direction 1 (direction par defaut).
@param[in, out] s pointeur de mario.
@return Aucun.
*/
void monsInitSdl(MonsterSdl *s);


/**
@brief Initialise s avec la postion p passe en parametre .
@param[in, out] s pointeur de monster.
@param[in] p pointeur de position.
@return Aucun.
@warning .
*/
void monsSetPositionSdl(MonsterSdl *s, const PositionSdl *p);



/**
@brief retourne la  position de MonsterSdl qui contient ses coordonnées.
@param[in, out] s pointeur sur MonsterSdl.
@return position.
*/
PositionSdl monsGetPositionSdl(const MonsterSdl *s);


/**
@brief modifie la direction de MonsterSdl avec la valeur de direction.
@param[in, out] s pointeur sur MonsterSdl.
@param[in] direction nouvelle direction pour MonsterSdl en mode donnee
@return aucun.
@warning direction prend ses valeur dans (1,2,3,4).
*/
void monsSetDirectionSdl(MonsterSdl *s, const int direction);


/**
@brief retourne la  direction de MonsterSdl
@param[in, out] s pointeur sur MonsterSdl.
@return int.
*/
int monsGetDirectionSdl(const MonsterSdl *s);


/**
@brief Modifie la position de MonsterSdl dans le terrain vers la gauche d'un caractere .
@param[in, out] s pointeur sur MonsterSdl.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
int monsGaucheSdl(MonsterSdl *s, const Niveau *n);


/**
@brief Modifie la position de MonsterSdl dans le terrain vers la droite d'un caractere .
@param[in, out] s pointeur sur MonsterSdl.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
int monsDroiteSdl(MonsterSdl *s, const Niveau *n);


/**
@brief Modifie la position de MonsterSdl dans le terrain vers le haut d'un caractere .
@param[in, out] s pointeur sur MonsterSdl.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
void monsHautSdl(MonsterSdl *s, const Niveau *n);


/**
@brief Modifie la position de MonsterSdl dans le terrain vers le bas d'un caractere .
@param[in, out] s pointeur sur MonsterSdl.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
int monsBasSdl(MonsterSdl *s, const Niveau *n);


/**
@brief Modifie la position de MonsterSdl dans le terrain vers le haut et bas de 2 caracteres .
@param[in, out] s pointeur sur MonsterSdl.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
void monsSautSdl(MonsterSdl *s, const Niveau *n);

/**
@brief Modifie la position de MonsterSdl si MarioSdl se trouve sur une case non valide .
@param[in, out] s pointeur sur MonsterSdl.
@param[in, out] n pointeur sur Niveau.
@return Aucun.
*/
void monsTombeSdl(MonsterSdl *s,const Niveau *n);

/**
@brief Test des fonctions avec plusieurs cas.
@param Aucun.
@return Aucun.
@warning im doit être intitialisé, les champs de couleur doivent être compris entre 0 et 255.
*/
void monsBougeAutoSdl(MonsterSdl *s, const Niveau *n);

#endif /*_MONSTERSDL_H*/

