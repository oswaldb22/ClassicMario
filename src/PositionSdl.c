/**
@file PositionSdl.c
@brief Fichier d'implémentation du module PositionSdl.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "PositionSdl.h"


void posInit(PositionSdl *p, const float x, const float y){
    assert(x>=0);
    assert(y>=0);

    p->x=x;
    p->y=y;
}

float posGetX(const PositionSdl *p){

    return p->x;
}



float posGetDx(const PositionSdl *p){

    return p->dx;
}

float posGetY(const PositionSdl *p){

    return p->y;
}

float posGetDy(const PositionSdl *p){

    return p->dy;
}

void posSetX(PositionSdl *p, const float x){
    assert(x>=0);
    p->x=x;
}


void posSetDx(PositionSdl *p, const float dx){
    p->dx=dx;
}


void posSetY(PositionSdl *p, const float y){
    assert(y>=0);
    p->y=y;
}

void posSetDy(PositionSdl *p, const float dy){
    p->dy=dy;
}

void posAddDx(PositionSdl *p, const float dx){

    float dx1 =posGetDx(p);
    dx1+=dx;
    posSetDx(p,dx1);
}

void posAddDy(PositionSdl *p, const float dy){

    float dy1 =posGetDy(p);
    dy1+=dy;
    posSetDy(p,dy1);
}


