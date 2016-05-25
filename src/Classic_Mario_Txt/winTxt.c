#include "winTxt.h"
#include "assert.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>


#if _WIN32
#include <windef.h>
#include <winbase.h>
#include <wincon.h>
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#include <unistd.h>
#endif



void termMove(int x, int y) /* deplace le curseur du terminal*/
{
#ifdef _WIN32
    /*Deplace le curseur en haut a gauche du terminal*/
    HANDLE console= GetStdHandle(STD_OUTPUT_HANDLE);
    COORD origine= { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(console, origine);
#else
    /*system("clear");*/
    char t[16];
    sprintf(t, "\033[%d;%dH", y, x);
    printf("%s",t);
#endif

}


void termClear()  /*efface le terminal*/
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void termInit()      /* configure la saisie : ne pas afficher les caracteres tapes*/
{
#ifdef _WIN32
    HANDLE console= GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode; GetConsoleMode(console, &mode);
    SetConsoleMode(console, mode & ~ENABLE_LINE_INPUT & ~ENABLE_ECHO_INPUT);
#else
    struct termios ttystate;
    struct termios t;
    int state = 1;

    /*get the terminal state*/
    tcgetattr(STDIN_FILENO, &ttystate);

    if (state)
    {
        /*turn off canonical mode*/
        ttystate.c_lflag &= ~ICANON;
        /*minimum of number input read.*/
        ttystate.c_cc[VMIN] = 1;
    }
    else
    {
        /*turn on canonical mode*/
        ttystate.c_lflag |= ICANON;
    }
    /*set the terminal attributes.*/
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);


    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
#endif
}



void winInit(WinTXT *w, int dx, int dy)
{
    w->dimx = dx;
    w->dimy = dy;
    w->win = malloc(w->dimx*w->dimy*sizeof(char));
    winClear(w);
    printf("winInit: %d %d\n", w->dimx, w->dimy);
    termInit();
    free(w->win);
}


void winClear(WinTXT *w)
{
    int i,j;
    for(i=0;i<w->dimx;++i)
        for(j=0;j<w->dimy;++j)
            winPrint( w, i, j, ' ');

}

void winPrint(WinTXT *w, int x, int y, char c)
{
    if (x<0) return;
    if (y<0) return;
    if (x>=w->dimx) return;
    if (y>=w->dimy) return;
    w->win[ y*w->dimx + x] = c;
}

void winPrint2(WinTXT *w, int x, int y, char* c)
{
    int i=0;
    while(c[i]!='\0') winPrint(w,x+i,y, c[i]);
}

void winDraw(WinTXT *w)
{
    int i,j;
    termMove(0,0);
    for(j=0;j<w->dimy;++j)
    {
        for(i=0;i<w->dimx;++i)
            printf("%c", w->win[ j*w->dimx + i] );
        printf("\n");
    }
    termMove(0,w->dimy);
}



#ifdef _WIN32
#else

int kbhit()
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); /*STDIN_FILENO is 0*/
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}
#endif


void winPause()
{
#ifdef _WIN32
    system("pause");
#else
    printf("Appuyer sur une touche\n");
    while( !kbhit() );
#endif
}


char winGetCh() /* lire un caractere si une touche a ete pressee*/
{
    char touche=0;
#ifdef _WIN32
    if (kbhit())
    {
        DWORD mode;
        DWORD n;
        HANDLE consoleI = GetStdHandle(STD_INPUT_HANDLE);
        GetConsoleMode(consoleI, &mode);
        SetConsoleMode(consoleI, mode & ~ENABLE_LINE_INPUT & ~ENABLE_ECHO_INPUT);
        ReadConsole(consoleI, &touche, 1, &n, NULL);
    }
#else
    if (kbhit())
        touche=fgetc(stdin);
#endif
    return touche;
}
