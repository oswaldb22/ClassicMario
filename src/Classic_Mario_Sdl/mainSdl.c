#include <stdio.h>
#include "sdlJeu.h"


int main ( int argc, char** argv )
{
    sdlJeu sj;
    printf("debut\n");
	sdljeuInit( &sj );
	sdlMenu(&sj);
	/*sdljeuBoucle(&sj);*/
	sdljeuDetruit(&sj);

	printf("Fin\n");
	return 0;
}
