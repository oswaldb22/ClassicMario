
#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "SDL2/SDL_audio.h"
#include "SDL2/SDL_mixer.h"

#include "JeuS.h"
#include "defs.h"

typedef struct
{
    SDL_Surface* surface;
    SDL_Texture* texture;
    int has_changed;
}Image;


typedef struct
{
	Jeu jeu;

    SDL_Window* window;
    SDL_Renderer *renderer;
    TTF_Font *font;

    int xscroll,yscroll;
    int largeur_fenetre,hauteur_fenetre;

    int time;
    SDL_Texture *texture;


/*----------------------------MARIO & MONSTER ------------------------*/
    Image imMarioG[2];
    Image imMarioD[2];

    Image imMonster;

/*----------------------------MAP---------------------------------------*/
    Image imSol;
    Image imBrick;
    Image imPointI;
    Image imBrickUsed;
    Image imBrickRed;
    Image imBrickGrey;
/*----------------------------MENU------------------------------*/
    Image menu[3];


}sdlJeu;

void sdljeuInit(sdlJeu *sj);
void sdljeuBoucle( sdlJeu *sj);
void sdlMenu(sdlJeu *sj);
void sdljeuDetruit( sdlJeu *sj);

void MoveMap(sdlJeu *sj,const int action);
int CollisionDecor(sdlJeu *sj,float dx, float dy);
void analyseCollision(sdlJeu *sj);


void updateplayer(sdlJeu *sj);

Image image(const char* filename, SDL_Renderer * renderer);
float temps();
void image_draw(Image *im, SDL_Renderer * renderer, int x, int y, int w, int h);

void text_draw(SDL_Texture *texture, SDL_Renderer * renderer,int x,int y, int w, int h);


#endif
