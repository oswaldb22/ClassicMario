/**
@file Position.c
@brief Fichier d'implémentation du module Position.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "Monster.h"


void posInit(Position *p, const int x, const int y){
    assert(x>=0);
    assert(y>=0);

    p->x=x;
    p->y=y;
}

int posGetX(const Position *p){

    return p->x;
}

int posGetY(const Position *p){

    return p->y;
}

void posSetX(Position *p, const int x){
    assert(x>=0);
    p->x=x;
}

void posSetY(Position *p, const int y){
    assert(y>=0);
    p->y=y;
}

