#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sdlJeu.h"


/*------------------------Deplacement en Scrolling--------------------------*/

void MoveMap(sdlJeu *sj,const int action){
	int dimx,dimy;
	dimx = nivGetDimX( jeuGetConstNiveau(&sj->jeu) );
	dimy = nivGetDimY( jeuGetConstNiveau(&sj->jeu) );

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


/*------------------------Deplacement,Collision et Saut----------------------*/
int CollisionDecor(sdlJeu *sj,float dx, float dy){
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

	MarioSdl *perso = jeuGetMarioSdl(&sj->jeu);
	Niveau *niv = jeuGetNiveau(&sj->jeu);

	int dimx,dimy;
	dimx = nivGetDimX( jeuGetConstNiveau(&sj->jeu) );
	dimy = nivGetDimY( jeuGetConstNiveau(&sj->jeu) );


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

void analyseCollision(sdlJeu *sj){

	/*Etudie les renvoies de la fonction CollisionDecor
	  En fonction de chaque nombre renvoyer on etudie les collisions et on influe sur
	  dx et dy !

	  .Utilisez la variable OnGround ou la variable Onledge, le test de collision ou la
	  graviter sera faite tant que OnGround ou OnLedge = 0*/
	MarioSdl *mar =jeuGetMarioSdl(&sj->jeu);

	if(CollisionDecor(sj,mar->dx,mar->dy)==-1)
	{
		posAddDy(&mar->posMario,GRAVITY*5);
		posSetDx(&mar->posMario,0);
		mar->dy=GRAVITY*5;
		mar->dx=0;
	}


	if(CollisionDecor(sj,mar->dx,mar->dy)==3)
	{
		posSetDy(&mar->posMario,0);
		posSetDx(&mar->posMario,0);
		posSetDy(&mar->posMario,0);

		mar->dy=0.0;
		mar->onGround=1;

	}


	if(CollisionDecor(sj,mar->dx,mar->dy)==1)
	{
		posAddDy(&mar->posMario,GRAVITY*5);
		posSetDx(&mar->posMario,0);
		mar->dy = GRAVITY*10;
		mar->dx=0.0;
	}



	if(CollisionDecor(sj,mar->dx,mar->dy)==2)
	{
		posSetDx(&mar->posMario,0);
		mar->dx =0;

	}


	if(CollisionDecor(sj,mar->dx,mar->dy)==4)
	{
		mar->dx = 0;
		posSetDx(&mar->posMario,0);
	}

	if(CollisionDecor(sj,mar->dx,mar->dy)==5)
	{
		posAddDy(&mar->posMario,GRAVITY*3);
		posSetDx(&mar->posMario,0);

		mar->dy = GRAVITY*3;
		mar->dx=0.0;

		if(CollisionDecor(sj,mar->dx,mar->dy)==3){
			posSetDy(&mar->posMario,0.0);
			mar->dy=0.0;
			mar->onGround=1;
		}

		if(CollisionDecor(sj,mar->dx,mar->dy)==1){
			posSetDy(&mar->posMario,0.0);
			mar->dy=0.0;
			mar->onGround=1;
		}
	}

}

void updateplayer(sdlJeu *sj){

	MarioSdl *mar =jeuGetMarioSdl(&sj->jeu);

	sj->time++;

	/*    int d=CollisionDecor(sj,mar->dx,mar->dy);
	      printf("1.  *%d* ",d);
	      printf("X= %f, Y=%f, dx=%f, dy=%f, ground=%d\n", mar->x,mar->y,mar->dx,mar->dy,mar->onGround);*/
	analyseCollision(sj);

	/* int d1=CollisionDecor(sj,mar->dx,mar->dy);
	   printf("2.  *%d* ",d1);
	   printf("X= %f, Y=%f, dx=%f, dy=%f, ground=%d\n", mar->x,mar->y,mar->dx,mar->dy,mar->onGround);*/

	mar->x+=mar->dx;

	analyseCollision(sj);
	mar->y+=mar->dy;
	/*-----------------------------ANIMATION----------------------------------------------------*/
	if(mar->dx != 0 && mar->onGround)
	{
		if(sj->time % 6 == 0)
		{
			if(mar->animFrame == 0)
			{
				mar->animFrame = 1;
			}
			else
			{
				mar->animFrame = 0;
			}
		}
	}
	mar->dx=0;

	mar->dy+=GRAVITY;

	/*Evite mario de tomber*/
	if(CollisionDecor(sj,mar->dx,mar->dy)==3)
	{
		mar->dy=0.0;
		mar->onGround=1;

	}

}



/*----------------------Dessine les images----------------------------------*/

Image image(const char* filename, SDL_Renderer * renderer){
	Image res;
	SDL_Surface * surfaceCorrectPixelFormat;
	/*res.surface = SDL_LoadBMP(filename);*/
	res.surface = IMG_Load(filename);

	if (res.surface == NULL)
	{
		/* std::string nfn = std::string("../") + filename;
		   std::cout<<"error: Can not load "<< filename<<". Trying "<<nfn<<std::endl;;
		   res.surface = IMG_Load(nfn.c_str());*/
		if (res.surface == NULL)
		{
			/* nfn = std::string("../") + nfn;
			   res.surface = IMG_Load(nfn.c_str());*/
		}
	}
	if (res.surface == NULL)
	{
		/* std::cout<<"error: Can not load "<< filename<<std::endl;
		   return res;*/
	}

	surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(res.surface,SDL_PIXELFORMAT_ARGB8888,0);
	SDL_FreeSurface(res.surface);
	res.surface = surfaceCorrectPixelFormat;

	/*res.texture = SDL_CreateTexture(g.renderer(), SDL_PIXELFORMAT_ARGB8888, 	SDL_TEXTUREACCESS_STREAMING,	res.surface->w, res.surface->h);*/
	res.texture = SDL_CreateTextureFromSurface( renderer, res.surface);

	if (res.texture == NULL)
	{
		printf("error: problem to create the texture of %s\n", filename);
		return res;
	}

	/*int ok = SDL_UpdateTexture(res.texture, NULL, res.surface->pixels, res.surface->pitch);*/
	/*assert(ok==0);*/

	printf("Image loaded: %s\n", filename);
	return res;
}

float temps(){
	/*return float(clock()) / CLOCKS_PER_SEC;*/
	return SDL_GetTicks() / CLOCKS_PER_SEC;  /* converti des ms en secondes en divisant par 1000*/
}

void image_draw(Image *im, SDL_Renderer * renderer, int x, int y, int w, int h){
	int ok;
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;

	if (im->has_changed)
	{
		ok = SDL_UpdateTexture(im->texture, NULL, im->surface->pixels, im->surface->pitch);
		assert(ok == 0);
		im->has_changed = 0;
	}

	ok = SDL_RenderCopy(renderer, im->texture, NULL, &r);
	/*ok = SDL_RenderCopyEx(g.renderer(), im.texture, NULL, &r, 0, NULL, SDL_FLIP_NONE);*/
	assert(ok == 0);
}

/*----------------------Dessine les texte----------------------------------*/

void text_draw(SDL_Texture *texture, SDL_Renderer * renderer,int x,int y, int w, int h){
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;

	SDL_RenderCopy(renderer,texture,NULL,&r);
}

void sdljeuInit(sdlJeu* sj)
{

	int dimx, dimy;
	int imgFlags;

	sj->time=0;


	/*-----------------------SCROLLING-------------------------------*/

	sj->largeur_fenetre=LARGEUR_FENETRE;
	sj->hauteur_fenetre=HAUTEUR_FENETRE;

	sj->xscroll=0*TAILLE_SPRITE;
	sj->yscroll=0*TAILLE_SPRITE;

	/*-----Initialisation du jeu avec le terrain1.txt----------------*/

	jeuInit(&sj->jeu,"data/TER.txt");

	/*---------------Initialisation de la SDL VIDEO------------------------*/

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n",SDL_GetError());
		SDL_Quit();
		/* exit();*/
	}

	imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
	{
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
		SDL_Quit();
	}

	/*---------------------Initialisation de la SDL TTF--------------------*/
	if(TTF_Init() == -1)
	{
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	sj->font = TTF_OpenFont("data/angelina.ttf", 50);
	if(sj->font==NULL){
		printf("error: problem to create the texture of angelina.ttf");
	}


	/*-Recuperation de dimx et dimy du Niveau pour la creation de la fenetre-*/

	dimx = nivGetDimX( jeuGetConstNiveau(&sj->jeu) );
	dimy = nivGetDimY( jeuGetConstNiveau(&sj->jeu) );
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;
	printf("dimX = %d , dimY = %d\n",dimx,dimy);

	/* Creation de la fenetre */
	sj->window = SDL_CreateWindow("CLASSIC MARIO v0.3",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			sj->largeur_fenetre, sj->hauteur_fenetre,
			SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	/* Attribution de l'icone de la fenetre */
	SDL_SetWindowIcon(sj->window, IMG_Load("data/mario_icon.png"));

	if (sj->window == NULL)
	{
		fprintf(stderr, "Erreur d'initialisation de la SDL pour la fenetre: %s\n",SDL_GetError());
		SDL_Quit();
		assert(0);
		exit(1);
	}

	/*-------Use this function to create a 2D rendering context for a window.----*/
	sj->renderer = SDL_CreateRenderer( sj->window, -1, SDL_RENDERER_ACCELERATED);

	/*-------Initialisation of audio library.----*/
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
 {
		printf("%s", Mix_GetError());
 }
 Mix_Music *musique; //Création du pointeur de type Mix_Music
 musique = Mix_LoadMUS("./data/Music/overworld.wav"); //Chargement de la musique
 Mix_PlayMusic(musique, -1); //Jouer infiniment la musique

	/* Chargement des Images */

	sj->imMonster= image("data/Image/fantome.png", sj->renderer);
	assert(sj->imMonster.surface);

	sj->imMarioD[0] = image("data/Image/mario_d2.png", sj->renderer);
	assert(sj->imMarioD[0].surface);

	sj->imMarioD[1] = image("data/Image/mario_d1.png", sj->renderer);
	assert(sj->imMarioD[1].surface);

	sj->imMarioG[0] = image("data/Image/mario_g2.png", sj->renderer);
	assert(sj->imMarioG[0].surface);

	sj->imMarioG[1] = image("data/Image/mario_g1.png", sj->renderer);
	assert(sj->imMarioG[1].surface);

	/*----------------------------MARIO MAP------------------------------*/

	sj->imSol = image("data/Image/Map/sol1.bmp", sj->renderer);
	assert(sj->imSol.surface);

	sj->imPointI = image("data/Image/Map/pointI.bmp", sj->renderer);
	assert(sj->imSol.surface);

	sj->imBrickUsed = image("data/Image/Map/blockq_used.bmp", sj->renderer);
	assert(sj->imSol.surface);

	sj->imBrick = image("data/Image/Map/gnd_red2.bmp", sj->renderer);
	assert(sj->imSol.surface);

	sj->imBrickRed = image("data/Image/Map/brickred.bmp", sj->renderer);
	assert(sj->imBrickRed.surface);

	sj->imBrickGrey = image("data/Image/Map/brick2.bmp", sj->renderer);
	assert(sj->imBrickGrey.surface);


	/*----------------------------MENU------------------------------*/
	sj->menu[0]= image("data/Image/menu1.png", sj->renderer);
	assert(sj->menu[0].surface);

	sj->menu[1]= image("data/Image/menu2.png", sj->renderer);
	assert(sj->menu[1].surface);

	sj->menu[2]= image("data/Image/menu3.png", sj->renderer);
	assert(sj->menu[2].surface);

}

void sdljeuAff(sdlJeu* sj)
{
	int direction;
	const Niveau* niv = jeuGetConstNiveau(&sj->jeu);
	const MarioSdl* mar = jeuGetMarioSdl(&sj->jeu);
	const MonsterSdl* mons = jeuGetMonsterSdl(&sj->jeu);

	/*------------------------AFFICHAGE SCROLLING-------------------------------*/
	int i,j;
	int minx,maxx,miny,maxy;


	int    dimx = nivGetDimX( jeuGetConstNiveau(&sj->jeu) );
	int    dimy = nivGetDimY( jeuGetConstNiveau(&sj->jeu) );
	sj->xscroll=mar->x+(TAILLE_SPRITE/2)-(LARGEUR_FENETRE/2);
	sj->yscroll=mar->y+(TAILLE_SPRITE/2)-(HAUTEUR_FENETRE/2);

	if (sj->xscroll<0)
		sj->xscroll=0;
	if (sj->yscroll<0)
		sj->yscroll=0;
	if (sj->xscroll>dimx*TAILLE_SPRITE-sj->largeur_fenetre)
		sj->xscroll=dimx*TAILLE_SPRITE-sj->largeur_fenetre;
	if (sj->yscroll>dimy*TAILLE_SPRITE-sj->hauteur_fenetre)
		sj->yscroll=dimy*TAILLE_SPRITE-sj->hauteur_fenetre;


	minx = sj->xscroll / TAILLE_SPRITE;
	miny = sj->yscroll / TAILLE_SPRITE;
	maxx = (sj->xscroll + sj->largeur_fenetre )/TAILLE_SPRITE;
	maxy = (sj->yscroll + sj->hauteur_fenetre )/TAILLE_SPRITE;

	/*Remplir l'écran de bleu*/
	SDL_SetRenderDrawColor( sj->renderer, 74, 75, 152, 255);
	SDL_RenderClear( sj->renderer);

	/*Affichage du terrain en fonction du terrain deja defini en TXT*/
	/*-------------EN FONCTION DU SCROLLING------------------------*/
	for(i=minx;i<maxx;i++)
	{
		for(j=miny;j<maxy;j++)
		{
			switch(nivGetXY(niv,i,j)){

				case '1' :
					image_draw( &sj->imPointI, sj->renderer, i*TAILLE_SPRITE - sj->xscroll, j*TAILLE_SPRITE - sj->yscroll, TAILLE_SPRITE, TAILLE_SPRITE);
					break;

				case '2' :
					image_draw( &sj->imBrickUsed, sj->renderer, i*TAILLE_SPRITE - sj->xscroll, j*TAILLE_SPRITE - sj->yscroll, TAILLE_SPRITE, TAILLE_SPRITE);
					break;

				case '3' :
					image_draw( &sj->imBrick, sj->renderer, i*TAILLE_SPRITE - sj->xscroll, j*TAILLE_SPRITE - sj->yscroll, TAILLE_SPRITE, TAILLE_SPRITE);
					break;

				case '4' :
					image_draw( &sj->imBrick, sj->renderer, i*TAILLE_SPRITE - sj->xscroll, j*TAILLE_SPRITE - sj->yscroll, TAILLE_SPRITE, TAILLE_SPRITE);
					break;

				case '5' :
					image_draw( &sj->imBrickGrey, sj->renderer, i*TAILLE_SPRITE - sj->xscroll, j*TAILLE_SPRITE - sj->yscroll, TAILLE_SPRITE, TAILLE_SPRITE);
					break;

				case '6' :
					image_draw( &sj->imSol, sj->renderer, i*TAILLE_SPRITE - sj->xscroll, j*TAILLE_SPRITE - sj->yscroll, TAILLE_SPRITE, TAILLE_SPRITE);
					break;

				case '7' :
					image_draw( &sj->imBrickUsed, sj->renderer, i*TAILLE_SPRITE - sj->xscroll, j*TAILLE_SPRITE - sj->yscroll, TAILLE_SPRITE, TAILLE_SPRITE);
					break;
			}
		}
	}

	/* Copier le sprite de MarioSdl sur la fenetre en fonction de la direction*/
	direction=marGetDirection(mar);
	switch (direction)
	{

		case 2 :
			image_draw( &sj->imMarioG[mar->animFrame], sj->renderer, mar->x- sj->xscroll, mar->y- sj->yscroll, TAILLE_SPRITE,TAILLE_SPRITE);
			break;
		case 4 :
			image_draw( &sj->imMarioD[mar->animFrame], sj->renderer, mar->x- sj->xscroll, mar->y- sj->yscroll, TAILLE_SPRITE,TAILLE_SPRITE);
			break;
	}

	/* Copie le sprite de Monster sur l'ecran*/
	image_draw( &sj->imMonster, sj->renderer, mons->x-sj->xscroll,  mons->y-sj->yscroll, TAILLE_SPRITE, TAILLE_SPRITE);
}

void sdljeuBoucle(sdlJeu* sj)
{
	SDL_Event events;
	int quit = 0;
	Jeu *jeu;
	Uint32 t, nt;
	t = SDL_GetTicks();
	jeu=&sj->jeu;

	/* tant que ce n'est pas la fin ...*/
	while ( quit == 0 )
	{
		/*FONCTION DE VERIFICATION DU DYNAMISME DE MARIO*/
		nt = SDL_GetTicks();
		if (nt-t>20)    /* 50 img / s*/
		{
			jeuActionsAutomatiques(jeu);
			updateplayer(sj);
			t = nt;
		}

		/* tant qu'il y a des evenements à traiter (cette boucle n'est pas bloquante)*/
		while ( SDL_PollEvent( &events ) )
		{
			if ( events.type == SDL_QUIT ) quit = 1;
			else if ( events.type == SDL_KEYDOWN )
			{
				switch ( events.key.keysym.scancode )
				{
					case SDL_SCANCODE_SPACE:
						MoveMap(sj,1);
						jeuActionClavier(&sj->jeu,'s');
						break;

					case SDL_SCANCODE_ESCAPE:
						quit = 1;
					case SDL_SCANCODE_Q:
						quit = 1;
						break;
					default: break;
				}

			}
		}

		/*Si une touche est pressé ensuite*/
		const Uint8 *state = SDL_GetKeyboardState(NULL);

		if(state[SDL_SCANCODE_LEFT])
		{
			MoveMap(sj,2);
			jeuActionClavier(&sj->jeu,'g');

		}

		else if(state[SDL_SCANCODE_RIGHT])
		{
			MoveMap(sj,4);
			jeuActionClavier(&sj->jeu,'d');

		}

		/* on affiche le jeu sur le buffer caché*/
		sdljeuAff( sj );

		/* on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle)*/
		SDL_RenderPresent( sj->renderer);
	}

}



/*------------------------AFFICHAGE MENU-----------------------------------*/

void sdlMenu(sdlJeu *sj)
{

	int  i = 1;
	printf("i : %d", i);

	int compteur;
	compteur= 1;

	SDL_Event events;

	while (compteur != 0)
	{
		switch(i)
		{
			case 1:
				image_draw( &sj->menu[0], sj->renderer, 0, 0, LARGEUR_FENETRE,HAUTEUR_FENETRE);
				break;

			case 2:
				image_draw( &sj->menu[1], sj->renderer, 0, 0,LARGEUR_FENETRE,HAUTEUR_FENETRE);
				break;

			case 3:
				image_draw( &sj->menu[2], sj->renderer, 0, 0, LARGEUR_FENETRE,HAUTEUR_FENETRE);
				break;
		}

		while ( SDL_PollEvent( &events))
		{
			if ( events.type == SDL_QUIT ) compteur = 1;
			else if ( events.type == SDL_KEYDOWN )
			{
				switch(events.key.keysym.scancode)
				{
					case  SDL_SCANCODE_DOWN:
						switch(i)
						{
							case 1:
								i = 2;
								break;

							case 2:
								i = 3;
								break;

							case 3:
								i = 1;
								break;
						}
						break;

					case  SDL_SCANCODE_UP:
						switch(i)
						{
							case 1:
								i = 3;
								break;

							case 2:
								i = 1;
								break;

							case 3:
								i = 2;
								break;
						}
						break;

					case SDL_SCANCODE_ESCAPE:
						compteur = 0;
						break;
					case SDL_SCANCODE_RETURN:
						switch(i)
						{
							case 1:
								sdljeuBoucle( sj);
								break;
							case 2:
								compteur=1;
								break;
							case 3:
								compteur = 0;
								break;
							default: break;
						}
					default:break;
				}
			}
		}
		SDL_RenderPresent( sj->renderer);
	}
}


void ImageFree(Image im){
	SDL_FreeSurface(im.surface);
	SDL_DestroyTexture(im.texture);
}
void ImageFreeTab(Image im[],int size){
	for(int i=0;i<size;i++){
		ImageFree(im[i]);
	}
}

void sdljeuDetruit( sdlJeu *sj){
//	Mix_FreeMusic(musique); //Libération de la musique
   Mix_CloseAudio(); //Fermeture de l'API

	TTF_CloseFont( sj->font);
	TTF_Quit();
	SDL_DestroyRenderer( sj->renderer );
	SDL_DestroyWindow( sj->window);
	SDL_Quit();
	/*----------------------------MARIO & MONSTER ------------------------*/
	ImageFreeTab(sj->imMarioG,2);
	ImageFreeTab(sj->imMarioD,2);
	ImageFree(sj->imMonster);
	/*----------------------------MAP---------------------------------------*/
	ImageFree(sj->imSol);
	ImageFree(sj->imBrick);
	ImageFree(sj->imPointI);
	ImageFree(sj->imBrickUsed);
	ImageFree(sj->imBrickRed);
	ImageFree(sj->imBrickGrey);
	/*----------------------------MENU-------------------------------------*/
	ImageFreeTab(sj->menu,3);
	free(sj);
}
