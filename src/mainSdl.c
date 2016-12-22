#include <stdio.h>
#include "sdlJeu.h"


int main ( int argc, char** argv )
{
  (void)argv;
  (void)argc;

  sdlJeu *sj=malloc(sizeof(sdlJeu));
	sdljeuInit( sj );
	sdlMenu(sj);
	sdljeuDetruit(sj);
	return 0;
}
