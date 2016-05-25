#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif /* WIN32 */
#include "winTxt.h"

#include "Jeu.h"

void txtAff( WinTXT *win, const Jeu *j)
{
	int x,y;
	const Niveau *niv = jeuGetConstNiveau(j);
	const Mario *mar = jeuGetConstMario(j);
	const Monster *mons = jeuGetConstMonster(j);

	winClear(win);

	for(x=0;x<nivGetDimX(niv);++x){
        for(y=0;y<nivGetDimY(niv);++y)
        {
			winPrint( win, x, y, nivGetXY(niv,x,y) );
        }
    }

	winPrint( win, posGetX(&mar->posMario), posGetY(&mar->posMario), 'M');
	winPrint( win, posGetX(&mons->posMonster), posGetY(&mons->posMonster), 'S');

	winDraw(win);
}


void txtBoucle(Jeu *jeu)
{
	WinTXT win;
	int c;
	int ok;


	/* Creation d'une nouvelle fenetre en mode texte*/
	/* => fenetre de dimension et position ( WIDTH, HEIGHT, STARTX,STARTY)*/
	winInit( &win, nivGetDimX(jeuGetConstNiveau(jeu)), nivGetDimY(jeuGetConstNiveau(jeu)) );


	ok = 1;
	do
	{
		txtAff( &win, jeu);

        #ifdef _WIN32
        Sleep(100);
        #endif /* WIN32*/

		jeuActionsAutomatiques(jeu);
        jeuVerificationPosition(jeu);
		c = winGetCh();
		switch(c)
		{
			case 'k':
				jeuActionClavier( jeu, 'g');
				break;
			case 'm':
				jeuActionClavier( jeu, 'd');
				break;
			case 'l':
				jeuActionClavier( jeu, 'h');
				break;
			case 'o':
				jeuActionClavier( jeu, 'b');
				break;
            case 'h':
				jeuActionClavier( jeu, 's');
				break;
			case 'q':
				ok = 0;
				break;
		}


	} while(ok);

}
