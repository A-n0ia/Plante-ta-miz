#include "paramitz.h"

int main()
{
     #ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | 0x0004); // ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #endif

    int xJoueur=4;
    int yJoueur=3;
    int IsSelected=0;
    char grille[ligne][colonne];
    srand(time(NULL));
    Grille(grille);
    affichePlateau(grille,xJoueur,yJoueur,IsSelected);
    return 0;
}

