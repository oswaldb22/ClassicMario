#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*Toutes les bibliothques*/

/*---------------SDL-------------------*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/*---------------SCROLLING-------------------*/

/*Represente les dimensions de la fenetre en fonction du terrain*/

/*NIVEAU terrain1.txt
#define LARGEUR_FENETRE 480
#define HAUTEUR_FENETRE 384
*/

/*NIVEAU TER.txt*/
#define LARGEUR_FENETRE 800
#define HAUTEUR_FENETRE 480


#define MOVESPEED 32 /*Vitesse du scrolling*/

/*---------------IMAGE------------------------*/
#define TAILLE_SPRITE 32 /*Taille d'un Sprite*/

/*----------------SAUT---------------------*/
#define GRAVITY  0.4f
#define MAX_FALL_SPEED 10
#define MAX_WALK_SPEED 5
#define JUMP_HEIGHT 11
