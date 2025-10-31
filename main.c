#include "paramitz.h"

void gotoxy(int x, int y)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD c;
   c.X=x;
   c.Y=y;
   SetConsoleCursorPosition(h,c);
}

void hide_cursor(){
    HANDLE cH=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO inf;
    inf.dwSize=100;
    inf.bVisible=0;
    SetConsoleCursorInfo(cH,&inf);
}


void jouer(int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM){
    int xJoueur=1;
    int yJoueur=1;
    int IsSelected=0;
    char grille[ligne][colonne];
    Grille(grille);
    //affichePlateau(grille,xJoueur,yJoueur,IsSelected);
    int getch();
    //variables pour la gestion du temps
    clock_t temps_debut;
    clock_t temps_actuelle;
    double temps_ecoule;
    //variables pour la saise utilisateur (choix de direction de déplacement)
    char touche='a';
    //initialisation du temps
    temps_ecoule=0;
    temps_debut = clock();
    //boucle de jeu
    do{
        /* partie autonome : ce que fait le programme quoi qu'il arrive */
        //calcul du temps écoulé
        temps_actuelle=clock();
        temps_ecoule=(temps_actuelle-temps_debut)/CLOCKS_PER_SEC;
        //affichages
        //affichage du temps écoulé et du score
        gotoxy(0, ligne+4);
        printf("Temps : %.1f s  ", temps_ecoule);
        gotoxy(0, ligne+3);
        printf("S : %d\tF : %d\tP : %d\tO : %d\tM : %d",*scoreS,*scoreF,*scoreP,*scoreO,*scoreM);
        gotoxy(0,0);
        /* partie évènementielle : ce que fait le programme si l'utilisateur appuie sur une touche */
        if(kbhit()!=0){
            touche= getch();
            if(touche==' '){
                if(IsSelected){
                    IsSelected=0;
                }
                else{
                    IsSelected=1;
                }
            }
            else if(IsSelected){
                permutation(grille,xJoueur,yJoueur,touche);
                deplacement(&xJoueur,&yJoueur,touche);
                suppression(grille,scoreS,scoreF,scoreP,scoreO,scoreM);
                IsSelected=0;
            }
            else{
                deplacement(&xJoueur,&yJoueur,touche);
            }
        }

        Sleep(60);
        clearConsole();
        affichePlateau(grille,xJoueur,yJoueur,IsSelected);

    }while(temps_ecoule<=30.0);



}



int main()
{
     #ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | 0x0004); // ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #endif
    int score=0;
    int scoreS=0;
    int scoreF=0;
    int scoreP=0;
    int scoreO=0;
    int scoreM=0;
    srand(time(NULL));
    int choix;
    clearConsole();
    afficherTitreJeu();
    Sleep(3000);
    do{
        clearConsole();
        afficherMenuTitre();
        afficherMenuPrincipal();
        choix=lireChoixMenu();
        switch(choix){
            case 1:
                hide_cursor();
                jouer(&scoreS,&scoreF,&scoreP,&scoreO,&scoreM);
                break;
            case 2:
                clearConsole();
                printf("\tWork in Progress\n");
                Sleep(1000);
                break;
            case 3:
                // sous-programme qui affiche les règles du jeu
                clearConsole();
                menuRegles();
                break;
            case 0 :
                printf("AU REVOIR !\n");
                break;
        }
    }while((choix!=0) && (choix!=1));

    if(choix==1){
            score=scoreS+scoreF+scoreP+scoreO+scoreM;
        printf("\n\n\n\t\tScore final : %d\n\n",score);
        printf("S : %d\nF : %d\nP : %d\nO : %d\nM : %d\n\n\n",scoreS,scoreF,scoreP,scoreO,scoreM);
        Sleep(100);
    }


    return 0;
}

