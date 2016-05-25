/**
@brief Module definnisant la Position (en 2D) d'un personnage.

@file Position.h
@author Oswald BLASSOU : oswald.blassou@etu.univ-lyon1.fr Numero Etu : 11410660
@version 1.0
@date 2016/03/01
*/

#ifndef _POSITION_H
#define _POSITION_H

/**
@brief Definition de la structure Position qui sera utile pour definir la position des personnages.
*/

typedef struct {
    int x;
    int y;
}Position;


/**
@brief Initialise une position avec des valeurs passées en paramètres.
@param[in, out] p pointeur de position.
@param[in] x entier qui représente la position x qui sera passer dans P.
@param[in] y entier qui représente la position y qui sera passer dans P.
@return Aucun.
@warning les positions doivent être positives.
*/
void posInit(Position *p, const int x, const int y);


/**
@brief retourne la  coordonnée X contenu dans la Position p.
@param[in, out] p pointeur sur position.
@return int .
*/
int posGetX(const Position *p);

/**
@brief retourne la  coordonnée Y contenu dans la Position p.
@param[in, out] p pointeur sur position.
@return int .
*/
int posGetY(const Position *p);

/**
@brief modifie la coordonnée x de Position passée en paramètre.
@param[in, out] p pointeur sur Position.
@param[in] x entier qui représente la position x qui sera passer dans P.
@return Aucun.
@warning x doit etre positive.
*/
void posSetX(Position *p, const int x);

/**
@brief modifie la coordonnée y de Position passée en paramètre.
@param[in, out] p pointeur sur Position.
@param[in] y entier qui représente la position x qui sera passer dans P.
@return Aucun.
@warning x doit etre positive.
*/
void posSetY(Position *p, const int y);

/**
@brief Permet de faire les test de  Toutes les fonctions du module Mario.
@param Aucun.
@return Aucun.
@warning p doit être intitialisé x et y positive .
*/
void posTestRegression();

#endif /* _POSITION_H*/


