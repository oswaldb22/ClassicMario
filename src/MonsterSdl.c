/**
@file MonsterSdl.c
@brief Fichier d'implémentation du module MarioSdl .
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "MonsterSdl.h"

void monsInitSdl(MonsterSdl *s){


    posInit(&s->posMonster,0,0);
    monsSetDirectionSdl(s,1);
}

void monsSetPositionSdl(MonsterSdl *s, const PositionSdl *p){
    assert(p->x>=0);
    assert(p->y>=0);

    s->posMonster=*p;
}


PositionSdl monsGetPositionSdl(const MonsterSdl *s){
    return s->posMonster;
}


void monsSetDirectionSdl(MonsterSdl *s, const int direction){
     assert((direction>=1) && (direction<=4));
     s->iDirection=direction;
}

int monsGetDirectionSdl(const MonsterSdl *s){

    return s->iDirection;
}


int monsDroiteSdl(MonsterSdl *s, const Niveau *n){

     /*int positionXactuel=posGetX(&s->posMonster);
    int positionYactuel=posGetY(&s->posMonster);
    if(nivEstPositionPersoValide(n,positionXactuel+1,positionYactuel)==1){
        posSetX(&s->posMonster,positionXactuel+1);
        monsSetDirection(s,4);
        return 1;
    }
    else
    {
        return 0;
    }*/
        s->dx += 0.5;
        if(s->dx > MAX_WALK_SPEED)
        {
            s->dx =MAX_WALK_SPEED;
        }
        return 1;
}


int monsGaucheSdl(MonsterSdl *s, const Niveau *n){

      int positionXactuel=posGetX(&s->posMonster);
    int positionYactuel=posGetY(&s->posMonster);
    if(nivEstPositionPersoValide(n,positionXactuel-1,positionYactuel)==1){
        posSetX(&s->posMonster,positionXactuel-1);
        monsSetDirectionSdl(s,2);
        return 1;
    }
    else
    {
        return 0;
    }

       /* s->dx -= 0.5;
        if(s->dx < -MAX_WALK_SPEED)
        {
            s->dx = -MAX_WALK_SPEED;
        }*/
}

void monsBougeAutoSdl(MonsterSdl *s, const Niveau *n)
{
    /*Position pos;*/

    /*int x,y,d;
    x = posGetX(&s->posMonster);
    y = posGetY(&s->posMonster);*/
    int deplace;

        /*Direction : droite*/

        if(monsGetDirectionSdl(s)==4)
        {
            /*Deplacement a Droite*/
            deplace = monsDroiteSdl(s, n);
            s->x++;
            /*Deplacement a Gauche*/
            if(deplace==0)
            {
                s->x--;
                monsGaucheSdl(s,n);
            }
        }

        /*Direction : gauche*/

        else if(monsGetDirectionSdl(s)==2)
        {
            /*Deplacement a Gauche */
            deplace = monsGaucheSdl(s, n);
            s->x++;
            /*Deplacement a Droite*/
            if(deplace == 0)
            {
                s->x--;
                monsDroiteSdl(s, n);
            }

        }
}
