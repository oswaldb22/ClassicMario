/**
@brief Module gerant le Jeu

@file Jeu.h
@author Oswald BLASSOU et Sow Mamadou : oswald.blassou@etu.univ-lyon1.fr/mamadou.sow@etu.univ-lyon1.fr
Numero Etu : 11410660/11414531
@version 1.0
@date 2016/03/01
*/


#ifndef _JEU_H
#define _JEU_H

#include "MarioSdl.h"
#include "MonsterSdl.h"
#include "NiveauSdl.h"
#include "defs.h"


/**
@brief Definition de la structure Jeu qui sera utile pour gerer le Jeu.
*/

typedef struct {
    MarioSdl mar;
    MonsterSdl mons;
    Niveau niv;

}Jeu;

/**
@brief Initialise Jeu en initialisant Mario,Monster,Niveau.
@param[in, out] j pointeur sur Jeu.
@return Aucun.
*/
void jeuInit(Jeu *j, const char *filename);

/**
@brief retourne un poiteur sur Mario du jeux.
@param[in, out] j pointeur sur Jeu.
@return pointeur sur Mario.
*/
const MarioSdl* jeuGetConstMarioSdl(const Jeu *j);

MarioSdl* jeuGetMarioSdl( Jeu *j);




/**
@brief retourne un poiteur sur Monster du jeux.
@param[in, out] j pointeur sur Jeu.
@return pointeur sur Monster.
*/
const MonsterSdl jeuGetConstMonsterSdl(const Jeu *j);

/**
@brief retourne un poiteur sur Niveau du jeux.
@param[in, out] j pointeur sur Jeu.
@return pointeur sur Niveau.
*/

MonsterSdl* jeuGetMonsterSdl( Jeu *j);

const Niveau* jeuGetConstNiveau(const Jeu *j);

 Niveau* jeuGetNiveau( Jeu *j);

/**
@brief Permet de deplacer Mario par rapport au touches du clavier.
@param[in, out] j pointeur sur Jeu.
@return aucun.
*/

void jeuActionsAutomatiques(Jeu *j);

/**
@brief Prend en compte les actions du clavier.
*/
void jeuActionClavier(Jeu *j, const char touche);

/**
@brief Reinitialise le niveau si Mario touche Monster
@param[in, out] j pointeur sur Jeu.
@return aucun.
*/
void jeuVerificationPosition(Jeu *j);



#endif
