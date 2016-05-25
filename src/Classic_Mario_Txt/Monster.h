/**
@brief Module gerant Monster.

@file Monster.h
@author Sow Mamadou: mamadou.sow@etu.univ-lyon1.fr Numero Etu : 11414531
@version 1.0
@date 2016/03/15
*/

#ifndef _MONSTER_H
#define _MONSTER_H


#include "Position.h"
#include "Niveau.h"

/**
@brief La structure Monster contient une positin en 2D (x,y) et une direction qui peut prendre ses valeur
entre (1,2,3,4)
*/
typedef struct {

    Position posMonster;
    int iDirection;

}Monster;


/**
@brief <B>Initialise</B> une structure Monster.
Cette fonction remplit posMonster et une idirection de monster avec des valeur par défaut.
@param[in, out] s pointeur sur Monster.
*/
void monsInit(Monster*s);

/**
@brief modifie la position Monster avec les coordonnées de p.
@param[in, out] s pointeur sur Monster.
@param[in] p pointeur sur une Postion en mode donnee .
@return Aucun.
@warning p doivent être initialiser avant avec des valeurs positives.
*/
void monsSetPosition(Monster *s, const Position *p);

/**
@brief retourne la  position de Monster qui contient ses coordonnées.
@param[in, out] s pointeur sur Monster.
@return Aucun.
*/
Position monsGetPosition(const Monster *s);

/**
@brief modifie la direction de Monster avec la valeur de direction.
@param[in, out] s pointeur sur Monster.
@param[in] direction nouvelle direction pour monster en mode donnee
@return Position.
@warning direction prend ses valeur dans (1,2,3,4).
*/
void monsSetDirection(Monster *s, const int direction);

/**
@brief retourne la  direction de Monster .
@param[in, out] s pointeur sur Monster.
@return Aucun.
*/
int monsGetDirection(const Monster *s);

/**
@brief Modifie la position de Monster dans le terrain vers la gauche d'un caractere .
@param[in, out] s pointeur sur Monster.
@param[in, out] t pointeur sur Terrain.
@return int.
*/
int monsGauche(Monster *s, const Niveau *n);

/**
@brief Modifie la position de Monster dans le terrain vers la droite d'un caractere .
@param[in, out] s pointeur sur Monster.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
int monsDroite(Monster*s, const Niveau *n);

/**
@brief Modifie la position de Monster dans le terrain vers le bas d'un caractere .
@param[in, out] s pointeur sur Monster.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
void monsBas(Monster*s, const Niveau *n);

/**
@brief Modifie la position de Monster dans le terrain vers le haut d'un caractere .
@param[in, out] s pointeur sur Monster.
@param[in, out] t pointeur sur Terrain.
@return Aucun.
*/
void monsHaut(Monster*s, const Niveau *n);


/**
@brief Permet de faire bouger automatiquement le Monster en evitant le caractere #.
@param[in, out] s pointeur sur Monster.
@param[in, out] n pointeur sur Niveau.
@return Aucun.
*/
void monsBougeAuto(Monster *s, const Niveau *n);

/**
@brief Permet de faire les test de  Toutes les fonctions du module Monster.
@param Aucun.
@return Aucun.
@warning s doit être intitialisé postion positive et direction comprise entre (1,4)
*/
void monsTestRegression();

#endif /* _MONSTER_H*/
