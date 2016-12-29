/**
@file MarioSdl.c
@brief Fichier d'implémentation du module MarioSdl .
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "MarioSdl.h"


void marInit(MarioSdl *m){


    posInit(&m->posMario,0,0);
    marSetDirection(m,1);
}

void marSetPositionSdl(MarioSdl *m, const PositionSdl *p){
    assert(p->x>=0);
    assert(p->y>=0);

    m->posMario=*p;
}


PositionSdl marGetPositionSdl(const MarioSdl *m){
    return m->posMario;
}


void marSetDirection(MarioSdl *m, const int direction){
     assert((direction>=1) && (direction<=4));
     m->iDirection=direction;
}

int marGetDirection(const MarioSdl *m){

    return m->iDirection;
}


void marDroite(MarioSdl *mar, const Niveau *n){
        //NO NEED n
        (void)n;


        float dy;
        posAddDy(&mar->posMario,-0.5);

        dy = posGetDy(&mar->posMario);

        if(dy < -MAX_WALK_SPEED)
        {
            dy = -MAX_WALK_SPEED;
        }
        posSetDy(&mar->posMario,dy);
        marSetDirection(mar,2);

         mar->dx += 0.5;
        if(mar->dx > MAX_WALK_SPEED)
        {
            mar->dx =MAX_WALK_SPEED;
        }

        marSetDirection(mar,4);
}


void marGauche(MarioSdl *mar, const Niveau *n){
        (void)n;


        float dx;
        posAddDx(&mar->posMario,-0.5);

        dx = posGetDx(&mar->posMario);

        if(dx < -MAX_WALK_SPEED)
        {
            dx = -MAX_WALK_SPEED;
        }
        posSetDx(&mar->posMario,dx);
        marSetDirection(mar,2);




        mar->dx -= 0.5;
        if(mar->dx < -MAX_WALK_SPEED)
        {
            mar->dx = -MAX_WALK_SPEED;
        }

        marSetDirection(mar,2);
}

void marSaut(MarioSdl *mar, const Niveau *n){
    (void)n;

    if(mar->onGround==1){
                        posAddDy(&mar->posMario,-JUMP_HEIGHT);

/*                        mar->onGround=0;*/
                    }


    if(mar->onGround==1){
                        mar->dy-=JUMP_HEIGHT;
                        mar->onGround=0;
                    }

}

void MoveMap2(Niveau *sj,const int action){
	int dimx,dimy;
	dimx = nivGetDimX(sj);
	dimy = nivGetDimY(sj);

	switch(action){
		case 2:
			sj->xscroll-=MOVESPEED;
			break;

		case 4:
			sj->xscroll+=MOVESPEED;
			break;

		case 1:
			sj->yscroll-=MOVESPEED;
			break;

		case 3:
			sj->yscroll+=MOVESPEED;
			break;
	}

	/*Limitation Clamping  et limitation du scrolling*/
	if (sj->xscroll<0)
		sj->xscroll=0;
	if (sj->yscroll<0)
		sj->yscroll=0;
	if (sj->xscroll>dimx*TAILLE_SPRITE-sj->largeur_fenetre)
		sj->xscroll=dimx*TAILLE_SPRITE-sj->largeur_fenetre;
	if (sj->yscroll>dimy*TAILLE_SPRITE-sj->hauteur_fenetre)
		sj->yscroll=dimy*TAILLE_SPRITE-sj->hauteur_fenetre;
}



int CollisionDecor2(Niveau *niv,MarioSdl *perso,float dx, float dy){
	/*retourne des nombres differents en fonction de la collision*/
	/*
	   1 pour une collision sur le haut
	   2 pour une collision sur la gauche
	   3 pour une collision sur le bas
	   4 pour une collision sur la droite
	 */
	int xmin,xmax,ymin,ymax,i,j;
	int nb;
	char c;

//	MarioSdl *perso = jeuGetMarioSdl(&sj->jeu);
	//Niveau *niv = jeuGetNiveau(&sj->jeu);

	int dimx,dimy;
	dimx = nivGetDimX(niv);
	dimy = nivGetDimY(niv);


	/*Personnage en dehors du terrain*/
	if (perso->x<0 || (perso->x + TAILLE_SPRITE -1)>=dimx*TAILLE_SPRITE
			|| perso->y<0 || (perso->y + TAILLE_SPRITE -1)>=dimy*TAILLE_SPRITE)
		return -1;

	if (dx<0 || dy<0){
		xmin=(perso->x + dx) / TAILLE_SPRITE;
		ymin=(perso->y + dy) / TAILLE_SPRITE;

		xmax=(perso->x + TAILLE_SPRITE -1)  / TAILLE_SPRITE;
		ymax=(perso->y + TAILLE_SPRITE -1) / TAILLE_SPRITE;
	}

	else{

		xmin = perso->x / TAILLE_SPRITE;
		ymin = perso->y / TAILLE_SPRITE;
		xmax = (perso->x + dx + TAILLE_SPRITE -1) / TAILLE_SPRITE;
		ymax = (perso->y + dy + TAILLE_SPRITE -1) / TAILLE_SPRITE;
	}

	for(i=xmin;i<=xmax;i++)
	{
		for(j=ymin;j<=ymax;j++)
		{
			c=nivGetXY(niv,i,j);

			/*On passe le char en int*/

			nb=atoi(&c);

			/*  printf("c=%c , nb=%d\n",c,nb);*/
			if(nb>=50){nb=5;}
			/*printf("nb=%d\n",nb);*/

			/*Collision Personnage sur le haut*/
			if(dx==0 && dy <= 0){

				if(nb<=5 && nb!=0){ return 1;}

			}

			/*Collision Personnage sur le bas*/
			if(dx==0 && dy >= 0){

				if(nb<=5 && nb!=0){ return 3;}

			}

			/*Collision Personnage sur la gauche*/
			else if(dx<=0 && dy == 0){

				if(nb<=5 && nb!=0){ return 2;}

			}
			/*Collision Personnage sur la droite*/
			else if(dx>=0 && dy == 0){

				if(nb<=5 && nb!=0){ return 4;}

			}

			/*Dans une collision*/
			else{

				if(nb<=5 && nb!=0){ return 5;}

			}
		}
	}

	/*En cas de non collision*/
	return 0;
}
