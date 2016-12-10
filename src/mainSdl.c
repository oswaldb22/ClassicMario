#include <stdio.h>
#include "sdlJeu.h"


int main ( int argc, char** argv )
{
    sdlJeu *sj=NULL;
	sj=malloc(sizeof(sdlJeu));     	
	sdljeuInit( sj );
	sdlMenu(sj);
	/*sdljeuBoucle(&sj);*/
	sdljeuDetruit(sj);
	return 0;
}
