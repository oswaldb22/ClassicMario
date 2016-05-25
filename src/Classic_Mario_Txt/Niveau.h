/**
@brief Module gerant Mario.

@file Mario.h
@author Sow Mamadou : mamadou.sow@etu.univ-lyon1.fr Numero Etu : 11414531
@version 1.0
@date 2016/03/01
*/

#ifndef _NIVEAU_H
#define _NIVEAU_H

/**
@brief Definition de la structure Niveau qui permet de faire la gestion
de changement de terrain par prapport au niveau
*/


typedef struct {


    int dimX;
    int dimY;
    char ter[100][100];
    int nbMonster;

}Niveau;

/**
@brief <B>Initialise</B> une structure Niveau.
Cette fonction initialise Niveau avec des valeur par défaut.
@param[in, out] n pointeur sur Niveau.
*/
void nivInit(Niveau *n, const char filename[]);

/**
@brief retourne le numero du niveau courant.
@param[in, out] n pointeur sur Niveau.
@return entier.
*/
int niVGetNumNiveau(Niveau * n);

/**
@brief modifie le numero du Niveau en le remplaçant ar num.
@param[in, out] n pointeur sur Niveau.
@param[in] num un entier permet de changer le numero du niveau .
@return Aucun.
@warning num doit être un entier positif.
*/
void nivSetNumNiveau(Niveau * n, const int x);

/*int niVGetTerrain();

void niVSetTerrain();*/
/**
@brief retourne le nombre de Monster qui se trouve dans un niveau.
@param[in, out] n pointeur sur Niveau.
@return entier.
*/
int niVGetNbMonster(Niveau * n);

/**
@brief modifie le nombre de Monster qui se trouve dans un niveau.
@param[in, out] n pointeur sur Niveau.
@param[in] nb entier permet de changer le nombre de monster dans un niveau.
@return Aucun.
@warning p doivent être initialiser avant avec des valeurs positives.
*/
void niVSetNbMonster(Niveau * n, const int nb);

/**
@brief Renvoie true si on peut positionnner un personnage aux coordonnées (x,y), false sinon
@param n pointeur sur Niveau.
@param x : abs de la case à tester
@param y : ordonnée de la case à tester
@return entier
*/
int nivEstPositionPersoValide(const Niveau *n, const int x, const int y);



/**
@brief Renvoie le type d'objet se trouvant en (x,y)
@param n pointeur sur Niveau.
@param x : abs de la case à tester
@param y : ordonnée de la case à tester
@return Caractere
*/
char nivGetXY(const  Niveau *n, const int x, const int y);

/**
@brief Renvoie la largeur d'un terrain
@param n pointeur sur Niveau.
@return entier
*/
int nivGetDimX(const  Niveau *n);

/**
@brief Renvoie la hauteur d'un terrain
@param n pointeur sur Niveau.
@return entier
*/
int nivGetDimY(const  Niveau *n);

/**
@brief Permet de faire les test de  Toutes les fonctions du module Niveau.
@param Aucun.
@return Aucun.
@warning n doit être intitialisé avec la fonction nivInit
*/
void nivTestRegression();


#endif


