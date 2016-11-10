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


    if(mar->onGround==1){
                        posAddDy(&mar->posMario,-JUMP_HEIGHT);

/*                        mar->onGround=0;*/
                    }


    if(mar->onGround==1){
                        mar->dy-=JUMP_HEIGHT;
                        mar->onGround=0;
                    }

}






