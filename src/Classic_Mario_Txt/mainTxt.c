#include <stdio.h>
#include "winTxt.h"

#include "txtJeu.h"


int main ( int argc, char** argv )
{

    Jeu jeu;
    printf("debut\n");
    termClear();
	jeuInit(&jeu);
	txtBoucle(&jeu);

    termClear();
	printf("Fin\n");

	return 0;
}
