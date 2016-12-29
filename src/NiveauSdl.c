/**
@file Niveau.c
@brief Fichier d'implémentation du module Niveau
 */
#define _GNU_SOURCE /*Pour pouvoir utiliser la fonction getline(); lecture d'une ligne de fichier*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "NiveauSdl.h"

void nivInit(Niveau *n, const char filename[]){
	FILE* f;
	int nbMonster;
	int i,j;
    int x,y;
    char tb[300][300];
	int dimx,dimy;

	f = fopen(filename, "r");
   	if (f==NULL)
    	{
        	printf("Erreur lors de l'ouverture de %s\n", filename);
    	}

   	assert( fscanf( f , "%d\n%d\n%d\n", &dimx, &dimy, &nbMonster) == 3 );


	n->dimX = dimx-1;
	n->dimY = dimy;
	n->nbMonster = nbMonster;

    for (j = 0 ; j < n->dimY ; j++)
    {
		char* ligneFichier=NULL;
		size_t sz=0;
	  int l =  getline(&ligneFichier, &sz, f);
		if(l==-1){
			printf("Error with getting line on file\n");
		}
		else{
				for (i = 0 ; i <n->dimX  ; i++)
        {
            switch (ligneFichier[i])
            {
                case '#':
                    tb[j][i] = '#';
                    break;

                case '1':/*Point d'interro*/
                    tb[j][i] = '1';
                    break;

                case '2':/*Block Utiliser*/
                    tb[j][i] = '2';
                    break;

                case '3':/*Brick Ressortissante*/
                    tb[j][i] = '3';
                    break;

                case '4':
                    tb[j][i] = '4';
                    break;

                case '5': /*Brick du Sol*/
                    tb[j][i] = '5';
                    break;

                case '6':/*Brick GREY*/
                    tb[j][i] = '4';
                    break;

                case '7':/*Brick GREY*/
                    tb[j][i] = '7';
                    break;



            }
        }
		}
		free(ligneFichier);
    }

    /*renverse le tableau*/
    for(x=0;x<n->dimX;++x)
		for(y=0;y<n->dimY;++y)
			n->ter[x][y] = tb[n->dimY-1-y][x];
    fclose(f);

/*-----------------------SCROLLING-------------------------------*/
			n->largeur_fenetre=LARGEUR_FENETRE;
			n->hauteur_fenetre=HAUTEUR_FENETRE;

			n->xscroll=0*TAILLE_SPRITE;
			n->yscroll=0*TAILLE_SPRITE;
}


int niVGetNbMonster(Niveau * n)
{
    return n->nbMonster;
}


void niVSetNbMonster(Niveau * n, const int nb)
{
    assert((nb>0));
    n->nbMonster=nb;
}

int nivEstPositionPersoValide(const Niveau * n, const int x, const int y)
{
    if((x>=0) && (x<n->dimX) && (y>=0) && (y<n->dimY) && (n->ter[x][y]!='#')){
        return 1;
    }
	else return 0;
}

char nivGetXY(const Niveau * n, const int x, const int y){
    assert(x>=0);
    assert(y>=0);
    assert(x<n->dimX);
    assert(y<n->dimY);

    return n->ter[x][y];

}

int nivGetDimX(const Niveau *n)
{
	return n->dimX;
}


int nivGetDimY(const Niveau *n)
{
	return n->dimY;
}

void nivSetDimX(Niveau *n, const int dimX){
    assert(dimX>=0);

    n->dimX=dimX;
}

void nivSetDimY(Niveau *n, const int dimY){
    assert(dimY>=0);

    n->dimY=dimY;
}
