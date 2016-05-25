/**
@file Monster.c
@brief Fichier d'implémentation du module Monster
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "Monster.h"


void monsInit(Monster*s){
    posInit(&s->posMonster,0,0);
    monsSetDirection(s,1);

}

void monsSetPosition(Monster *s, const Position *p){
    s->posMonster=*p;
}


Position monsGetPosition(const Monster *s){
    return s->posMonster;
}

void monsSetDirection(Monster *s, const int direction){
    assert((direction >= 1) && (direction<= 4));
    s->iDirection=direction;
}


int monsGetDirection(const Monster *s){
    return s->iDirection;
}


int monsGauche(Monster *s, const Niveau *n){
    int positionXactuel=posGetX(&s->posMonster);
    int positionYactuel=posGetY(&s->posMonster);
    if(nivEstPositionPersoValide(n,positionXactuel-1,positionYactuel)==1){
        posSetX(&s->posMonster,positionXactuel-1);
        monsSetDirection(s,2);
        return 1;
    }
    else
    {
        return 0;
    }

}

int monsDroite(Monster*s, const Niveau *n){
    int positionXactuel=posGetX(&s->posMonster);
    int positionYactuel=posGetY(&s->posMonster);
    if(nivEstPositionPersoValide(n,positionXactuel+1,positionYactuel)==1){
        posSetX(&s->posMonster,positionXactuel+1);
        monsSetDirection(s,4);
        return 1;
    }
    else
    {
        return 0;
    }

}


void monsBas(Monster*s, const Niveau *n){
    int positionXactuel=posGetX(&s->posMonster);
    int positionYactuel=posGetY(&s->posMonster);
    if(nivEstPositionPersoValide(n,positionXactuel,positionYactuel-1)==1){
        posSetY(&s->posMonster,positionYactuel-1);
        monsSetDirection(s,3);
    }
}


void monsHaut(Monster*s, const Niveau *n){
    int positionXactuel=posGetX(&s->posMonster);
    int positionYactuel=posGetY(&s->posMonster);
    if(nivEstPositionPersoValide(n,positionXactuel,positionYactuel+1)==1){
        posSetY(&s->posMonster,positionYactuel+1);
        monsSetDirection(s,1);
    }
}

void monsBougeAuto(Monster *s, const Niveau *n)
{
    //Position pos;

    /*int x,y,d;
    x = posGetX(&s->posMonster);
    y = posGetY(&s->posMonster);*/
    int deplace;

        //Direction : droite
        if(monsGetDirection(s)==4)
        {
            /*Deplacement a Droite*/
            deplace = monsDroite(s, n);

            /*Deplacement a Gauche*/
            if(deplace==0)
            {
                monsGauche(s,n);
            }
        }
        //Direction : gauche
        else if(monsGetDirection(s)==2)
        {
            /*Deplacement a Gauche */
            deplace = monsGauche(s, n);

            /*Deplacement a Droite*/
            if(deplace == 0)
            {
                monsDroite(s, n);
            }

        }
}
            // Deplacement droite
            //if (nivEstPositionPersoValide(n,x+1,y))
            //{
                //posSetX(&pos, x+1);
                //posSetY(&pos, y);
                //monsSetPosition(s,&pos);
                //monsSetDirection(s,4);
              //  monsDroite(s, n);
            //}
            // Deplacement gauche
          /*  else if(nivEstPositionPersoValide(n,x-1,y))
            {
                //posSetX(&pos, x-1);
                //posSetY(&pos, y);
                //monsSetPosition(s,&pos);
                //monsSetDirection(s,2);
                monsGauche(s, n);
            }
        }
        //Direction : gauche
        else if(s->iDirection==2)
        {
            // Deplacement gauche
            if (nivEstPositionPersoValide(n,x-1,y))
            {
                //posSetX(&pos, x-1);
                //posSetY(&pos, y);
                //monsSetPosition(s,&pos);
                //monsSetDirection(s,2);
                monsGauche(s, n);
            }
            // Deplacement droite
            else  if (nivEstPositionPersoValide(n,x+1,y))
            {
                //posSetX(&pos, x+1);
                //posSetY(&pos, y);
                //monsSetPosition(s,&pos);
                //monsSetDirection(s,4);
                monsDroite(s, n);
            }
    }
}*/




void monsTestRegression(){

    /*--------------------------------Test de regression du module Monster----------------------------------------*/
/*
    Monster s;
    Niveau n;
    Position posMons;
    int dirAuto;
    nivInit(&n);
    printf("\n********  TEST MODULE MONSTER **********\n");
    printf("\nInitialisation de Monster avec la fonction marInit \n Initialise Monster a une position:(0,0) direction:1");
    monsInit(&s);
    posMons= monsGetPosition(&s);
    assert((s.iDirection== 1 || 2 || 3 || 4) && (posGetX(&s.posMonster)>=0) && (posGetY(&s.posMonster)>=0));
    printf("\nInitialisation --> OK\n");
    printf("\n Verifions les accesseurs que les champs idirection=1 et de position sont egales à (0,0) \n");
    assert((monsGetDirection(&s)==1) && (posGetX(&posMons)==0) && (posGetY(&posMons)==0));

    printf("\nAffichage de la direction et dela position(x,y): \n");
    printf("iDirection est égale à  : %d\n",monsGetDirection(&s));
    printf("x est égale à  : %d\n",posGetX(&s.posMonster));
    printf("y est égale à  : %d\n",posGetY(&s.posMonster));

    printf("\nAccesseurs --> OK\n");

    printf("\n Verifions les mutateurs en remplaçant les champs idirection=2 et de position sont egales à (2,2) \n");
    monsSetDirection(&s,2);
    posSetX(&posMons,2);
    posSetY(&posMons,2);
    monsSetPosition(&s,&posMons);
    assert((posGetX(&s.posMonster)==posMons.x) && ((posGetY(&s.posMonster)==posMons.y)));
    printf("\nAffichage après les mutateurs des coordonneés de Monster: \n");
    printf("direction Monster est égale à  : %d\n",monsGetDirection(&s));
    printf("position X de Monster est égale à  : %d\n",posGetX(&s.posMonster));
    printf("position Y de Monster est égale à  : %d\n",posGetY(&s.posMonster));

    printf("\nMutateurs --> OK \n");

    printf("\n Test des Fonctions de Deplacement (bas,gauche,droite,haut, saut) dans un Niveau\n");
    printf("\nPosition actuelle:(2,2)\n");
    printf("\n1- Monster Bas \n");
    monsBas(&s, &n);

    assert((posGetX(&s.posMonster)==2) && ((posGetY(&s.posMonster)==1)));
    printf("\nPosition actuelle:(%d,%d)\n",posGetX(&s.posMonster),posGetY(&s.posMonster));
    printf("\nDeplacement Bas --> OK \n");
    printf("\n2- Monster Droite \n");
    monsDroite(&s, &n);
    assert((posGetX(&s.posMonster)==3) && ((posGetY(&s.posMonster)==1)));
    printf("\nPosition actuelle:(%d,%d)\n",posGetX(&s.posMonster),posGetY(&s.posMonster));
    printf("\nDeplacement Droite --> OK \n");
    printf("\n3- Monster Haut \n");
    monsHaut(&s, &n);
    assert((posGetX(&s.posMonster)==3) && ((posGetY(&s.posMonster)==2)));
    printf("\nPosition actuelle:(%d,%d)\n",posGetX(&s.posMonster),posGetY(&s.posMonster));
    printf("\nDeplacement Haut --> OK \n");
    printf("\n4- Monster Gauche \n");
    monsGauche(&s, &n);
    assert((posGetX(&s.posMonster)==2) && ((posGetY(&s.posMonster)==2)));
    printf("\nPosition actuelle:(%d,%d)\n",posGetX(&s.posMonster),posGetY(&s.posMonster));
    printf("\nDeplacement Gauche --> OK \n");
    printf("\n5- Monster Bouge Auto \n");
    monsBougeAuto(&s, &n);
    dirAuto=monsGetDirection(&s);
    assert(dirAuto == 1 || 2|| 3|| 4);no finish
    printf("\nPosition actuelle:(%d,%d)\n",posGetX(&s.posMonster),posGetY(&s.posMonster));
    printf("\nDeplacement Automatique --> OK \n");

    printf("\n********  Module Monster --> OK **********\n");*/
}






