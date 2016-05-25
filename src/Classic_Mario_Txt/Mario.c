/**
@file Mario.c
@brief Fichier d'implémentation du module Mario .
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Mario.h"



void marInit(Mario *m){


    posInit(&m->posMario,0,0);
    marSetDirection(m,1);
}

void marSetPosition(Mario *m, const Position *p){
    assert(p->x>=0);
    assert(p->y>=0);

    m->posMario=*p;
}


Position marGetPosition(const Mario *m){
    return m->posMario;
}


void marSetDirection(Mario *m, const int direction){
     assert((direction>=1) && (direction<=4));
     m->iDirection=direction;
}

int marGetDirection(const Mario *m){

    return m->iDirection;
}


void marGauche(Mario *m, const Niveau *n){
    int positionXactuel=posGetX(&m->posMario);
    int positionYactuel=posGetY(&m->posMario);
    if(nivEstPositionPersoValide(n,positionXactuel-1,positionYactuel)==1){
        posSetX(&m->posMario,positionXactuel-1);
    }

    marSetDirection(m,2);
    marTombe(m,n);
}


void marDroite(Mario *m, const Niveau *n){
    int positionXactuel=posGetX(&m->posMario);
    int positionYactuel=posGetY(&m->posMario);
    if(nivEstPositionPersoValide(n,positionXactuel+1,positionYactuel)==1){
        posSetX(&m->posMario,positionXactuel+1);
    }
    marSetDirection(m,4);
    marTombe(m,n);
}

void marHaut(Mario *m, const Niveau *n){
    int positionXactuel=posGetX(&m->posMario);
    int positionYactuel=posGetY(&m->posMario);
    if(nivEstPositionPersoValide(n,positionXactuel,positionYactuel+1)==1){
        posSetY(&m->posMario,positionYactuel+1);
    }
    marSetDirection(m,1);


}

void marBas(Mario *m, const Niveau *n){
    int positionXactuel=posGetX(&m->posMario);
    int positionYactuel=posGetY(&m->posMario);
    if(nivEstPositionPersoValide(n,positionXactuel,positionYactuel-1)==1){
        posSetY(&m->posMario,positionYactuel-1);
    }
    marSetDirection(m,3);
     marTombe(m,n);
}

void marSaut(Mario *m, const Niveau *n){
    int i=1;
   /* int c;*/
    int positionXactuel=posGetX(&m->posMario);
    int positionYactuel=posGetY(&m->posMario);

    marTombe(m, n);
    if(nivEstPositionPersoValide(n,positionXactuel,positionYactuel-1)){
        marTombe(m,n);
    }

    while((nivEstPositionPersoValide(n,positionXactuel,positionYactuel-i))==1 && i<=2){

            posSetY(&m->posMario,positionYactuel-i);
            i++;
        }
}

void marTombe(Mario *m,const Niveau *n){
    int i=0;
    int positionXactuel=posGetX(&m->posMario);
    int positionYactuel=posGetY(&m->posMario);

    while((nivEstPositionPersoValide(n,positionXactuel,positionYactuel+i))==1 && i<=10){

            posSetY(&m->posMario,positionYactuel+i);
           /* marSetDirection(m,3);*/
            i++;

        }

}




void marTestRegression(){

    /*--------------------------------Test de regression du module Mario----------------------------------------*/

   /* Mario m;
    Niveau n;
    Position posMar;
    nivInit(&n);
    printf("\n********  TEST MODULE MARIO **********\n");
    printf("\nInitialisation de Mario avec la fonction marInit \n Initialise Mario a une position:(0,0) direction:1");
    marInit(&m);
    posMar= marGetPosition(&m);
    assert((m.iDirection== 1 || 2 || 3 || 4) && (posGetX(&m.posMario)>=0) && (posGetY(&m.posMario)>=0));
    printf("\nInitialisation --> OK\n");
    printf("\n Verifions les accesseurs que les champs idirection=1 et de position sont egales à (0,0) \n");
    assert((marGetDirection(&m)==1) && (posGetX(&posMar)==0) && (posGetY(&posMar)==0));
    printf("\nAffichage de la direction et dela position(x,y): \n");
    printf("iDirection est égale à  : %d\n",marGetDirection(&m));
    printf("x est égale à  : %d\n",posGetX(&m.posMario));
    printf("y est égale à  : %d\n",posGetY(&m.posMario));
    printf("\nAccesseurs --> OK\n");
    printf("\n Verifions les mutateurs en remplaçant les champs idirection=2 et de position sont egales à (2,2) \n");
    marSetDirection(&m,2);
    posSetX(&posMar,2);
    posSetY(&posMar,2);
    marSetPosition(&m,&posMar);
    assert((posGetX(&m.posMario)==posMar.x) && ((posGetY(&m.posMario)==posMar.y)));
    printf("\nAffichage après les mutateurs des coordonneés de Mario: \n");
    printf("direction Mario est égale à  : %d\n",marGetDirection(&m));
    printf("position X de Mario est égale à  : %d\n",posGetX(&m.posMario));
    printf("position Y de Mario est égale à  : %d\n",posGetY(&m.posMario));
    printf("\nMutateurs --> OK \n");
    printf("\n Test des Fonctions de Deplacement (bas,gauche,droite,haut, saut) dans un Niveau\n");
    printf("\nPosition actuelle:(2,2)\n");
    printf("\n1- Mario Bas \n");
    marBas(&m, &n);
    printf("\nPosition actuelle:(%d,%d)\n",posGetX(&m.posMario),posGetY(&m.posMario));
    assert((posGetX(&m.posMario)==2) && ((posGetY(&m.posMario)==1)));
    printf("\nPosition actuelle:(%d,%d)\n",posGetX(&m.posMario),posGetY(&m.posMario));
    printf("\nDeplacement Bas --> OK \n");
    printf("\n2- Mario Droite \n");
    marDroite(&m, &n);
    assert((posGetX(&m.posMario)==3) && ((posGetY(&m.posMario)==1)));
    printf("\nPosition actuelle:(%d,%d)\n",posGetX(&m.posMario),posGetY(&m.posMario));
     printf("\nDeplacement Droite --> OK \n");
    printf("\n3- Mario Haut \n");
    marHaut(&m, &n);
    assert((posGetX(&m.posMario)==3) && ((posGetY(&m.posMario)==2)));
    printf("\nPosition actuelle:(%d,%d)\n",posGetX(&m.posMario),posGetY(&m.posMario));
     printf("\nnDeplacement Haut --> OK \n");
    printf("\n4- Mario Gauche \n");
    marGauche(&m, &n);
    assert((posGetX(&m.posMario)==2) && ((posGetY(&m.posMario)==2)));
    printf("\nPosition actuelle:(%d,%d)\n",posGetX(&m.posMario),posGetY(&m.posMario));
     printf("\nDeplacement Gauche --> OK \n");
    printf("\n Remise de position à (1,1) \n");
    posSetX(&posMar,1);
    posSetY(&posMar,1);
    printf("\n5- Mario Saut \n");
    marSetPosition(&m,&posMar);
    marSaut(&m, &n);
    assert((posGetX(&m.posMario)==1) && ((posGetY(&m.posMario)==4)));
    printf("\nPosition actuelle:(%d,%d)\n",posGetX(&m.posMario),posGetY(&m.posMario));
     printf("\nDeplacement Saut --> OK \n");
    printf("\n********  Module Mario --> OK **********\n");
*/
}


