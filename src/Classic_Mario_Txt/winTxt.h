
#include <stdio.h>

#ifndef WINTXT_H
#define WINTXT_H

/** \brief une fenêtre texte est un tableau 2D de caractères */
typedef struct {
    int dimx;       /**!< \brief largeur */
    int dimy;       /**!< \brief heuteur */
    char* win;      /**!< \brief stocke le contenu de la fenêtre dans un tableau 1D mais on y accede en 2D */
}WinTXT;

void termClear();
void winInit(WinTXT *w, int dx, int dy);
void winClear(WinTXT *w);
void winPrint(WinTXT *w, int x, int y, char c);
void winPrint2(WinTXT *w, int x, int y, char* c);
void winDraw(WinTXT *w);
void winPause();
char winGetCh();

#endif

