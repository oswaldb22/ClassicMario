/**
@brief Module definnisant la PositionSdl (en 2D) d'un personnage.

@file PositionSdl.h
@author Oswald BLASSOU : oswald.blassou@etu.univ-lyon1.fr Numero Etu : 11410660
@version 1.0
@date 2016/03/01
*/

#ifndef _POSITIONSDL_H
#define _POSITIONSDL_H

/**
@brief Definition de la structure PositionSdl qui sera utile pour definir la position des personnages.
*/

typedef struct {
    float x;
    float y;
    float dx,dy;
}PositionSdl;


/**
@brief Initialise une position avec des valeurs passées en paramètres.
@param[in, out] p pofloateur de position.
@param[in] x entier qui représente la position x qui sera passer dans P.
@param[in] y entier qui représente la position y qui sera passer dans P.
@return Aucun.
@warning les positions doivent être positives.
*/
void posInit(PositionSdl *p, const float x, const float y);


/**
@brief retourne la  coordonnée X contenu dans la PositionSdl p.
@param[in, out] p pofloateur sur position.
@return float .
*/
float posGetX(const PositionSdl *p);
float posGetDx(const PositionSdl *p);

/**
@brief retourne la  coordonnée Y contenu dans la PositionSdl p.
@param[in, out] p pofloateur sur position.
@return float .
*/
float posGetY(const PositionSdl *p);
float posGetDy(const PositionSdl *p);
/**
@brief modifie la coordonnée x de PositionSdl passée en paramètre.
@param[in, out] p pofloateur sur PositionSdl.
@param[in] x entier qui représente la position x qui sera passer dans P.
@return Aucun.
@warning x doit etre positive.
*/
void posSetX(PositionSdl *p, const float x);
void posSetDx(PositionSdl *p, const float x);
/**
@brief modifie la coordonnée y de PositionSdl passée en paramètre.
@param[in, out] p pofloateur sur PositionSdl.
@param[in] y entier qui représente la position x qui sera passer dans P.
@return Aucun.
@warning x doit etre positive.
*/
void posSetY(PositionSdl *p, const float y);
void posSetDy(PositionSdl *p, const float y);

void posAddDx(PositionSdl *p, const float dx);
void posAddDy(PositionSdl *p, const float dy);


#endif /* _POSITIONSDL_H*/


