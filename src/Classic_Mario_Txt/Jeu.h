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

#include "Mario.h"
#include "Niveau.h"
#include "Monster.h"

/**
@brief Definition de la structure Jeu qui sera utile pour gerer le Jeu.
*/

typedef struct {
    Mario mar;
    Monster mons;
    Niveau niv;

}Jeu;

/**
@brief Initialise Jeu en initialisant Mario,Monster,Niveau.
@param[in, out] j pointeur sur Jeu.
@return Aucun.
*/
void jeuInit(Jeu *j);

/**
@brief retourne un poiteur sur Mario du jeux.
@param[in, out] j pointeur sur Jeu.
@return pointeur sur Mario.
*/
const Mario* jeuGetConstMario(const Jeu *j);

/**
@brief retourne un poiteur sur Monster du jeux.
@param[in, out] j pointeur sur Jeu.
@return pointeur sur Monster.
*/
const Monster* jeuGetConstMonster(const Jeu *j);

/**
@brief retourne un poiteur sur Niveau du jeux.
@param[in, out] j pointeur sur Jeu.
@return pointeur sur Niveau.
*/
const Niveau* jeuGetConstNiveau(const Jeu *j);

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
