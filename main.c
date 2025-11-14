#include "paramitz.h"

typedef struct scores{
    int scoreS;
    int scoreF;
    int scoreP;
    int scoreO;
    int scoreM;
    int score_total;
}Scores;

typedef struct player{
    char name[20];
    int level;
    int lives;
    int current_best_score;
    int all_time_best_score;
}Player;

typedef struct contract{
    int scoreS;
    int scoreF;
    int scoreP;
    int scoreO;
    int scoreM;
}Contract;

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

Contract* objectifs(Contract* objectives,int level){
    if(level==1){
        objectives->scoreF=10+rand()% 21;
        objectives->scoreP=10+rand() % (objectives->scoreF-9);
        objectives->scoreM=10+rand() % (objectives->scoreF-9);
        objectives->scoreO=0;
        objectives->scoreS=0;
    }
    else if(level==2){
        objectives->scoreO=40;
        objectives->scoreS=23;
        objectives->scoreF=16;
        objectives->scoreP=13;
        objectives->scoreM=0;
    }
    return objectives;
}

Scores* initScores(Scores* pScore){
    pScore->scoreF=0;
    pScore->scoreM=0;
    pScore->scoreO=0;
    pScore->scoreP=0;
    pScore->scoreS=0;
    return pScore;
}

/*Player* findSave(Player* actual){
    char cherche[20];
    printf("Quel est votre nom ?");
    scanf("%s",cherche);
    FILE* save=NULL;


}*/

Player* initJoueur(Player* pJoueur){
    printf("Quel est votre pseudo ?\n");
    scanf("%s",pJoueur->name);
    pJoueur->level=1;
    pJoueur->lives=5;
    pJoueur->current_best_score=0;
    pJoueur->all_time_best_score=0;
    return pJoueur;
}

int partie(Scores* pScore,Contract* objectives,Player* pJoueur){
    char continuer;
    int c;
    if((pScore->scoreF<objectives->scoreF) || (pScore->scoreM<objectives->scoreM) || (pScore->scoreO<objectives->scoreO) || (pScore->scoreP<objectives->scoreP) || (pScore->scoreS<objectives->scoreS)){
        pJoueur->lives-=1;
        if(pJoueur->lives<1){
            if(pJoueur->level>1){
                pJoueur->level-=1;
                pJoueur->lives=5;
            }
            pJoueur->lives=5;
            gotoxy(46,8);
            printf(rouge"GAME OVER");
            gotoxy(27,9);
            printf("- vous n'avez plus de vie, vous allez retourner au niveau %d -"reset,pJoueur->level);
        }
        else{
            gotoxy(46,8);
            printf(rouge"GAME OVER"reset);
            gotoxy(27,9);
            printf("- il vous reste"vert" %d"reset" vies pour reussir le niveau %d -",pJoueur->lives,pJoueur->level);
        }
        gotoxy(0,13);
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Voulez-vous continuer ?\t\tEntrer 1 pour OUI ou 2 pour NON");
        continuer=getch();
        while((continuer < '0') || (continuer > '9')){
            printf(rouge"     Entree invalide\n"reset);
            printf("Voulez-vous continuer ?\t\tEntrer 1 pour OUI ou 2 pour NON");
            continuer=getch();
        }
        if(continuer=='1'){
            clearConsole();
            gotoxy(0,5);
            printf("Vous avez choisi de continuer, il vous reste %d vies pour completer le niveaux %d",pJoueur->lives,pJoueur->level);
            gotoxy(0,10);
            attendreTouche();
            return 1;
        }
        else{
            clearConsole();
            gotoxy(0,5);
            printf("Vous avez choisi d'arreter, vous pourrer toujours recharger votre sauvegarde plus tard ou commencer une nouvelle partie");
            return 0;
        }
    }
    else{
        if(pJoueur->level<3){
            pJoueur->level+=1;
            animation_nv(pJoueur->name,pJoueur->level);
            gotoxy(25,20);
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Voulez-vous continuer ?\t\tEntrer 1 pour OUI ou 2 pour NON");
            continuer=getch();
            while((continuer < '0') || (continuer > '9')){
                printf(rouge"    Entree invalide\n"reset);
                printf("Voulez-vous continuer ?\t\tEntrer 1 pour OUI ou 2 pour NON");
                continuer=getch();
            }
            if(continuer=='1'){
                clearConsole();
                gotoxy(0,5);
                printf("Vous avez choisi de continuer, il vous reste %d vies pour completer le niveaux %d",pJoueur->lives,pJoueur->level);
                gotoxy(0,10);
                attendreTouche();
                return 1;
            }
            else{
                clearConsole();
                gotoxy(0,5);
                printf("Vous avez choisi d'arreter, vous pourrer toujours recharger votre sauvegarde plus tard ou commencer une nouvelle partie\n");
                return 0;
            }

        }

    }
}


void jouer(Scores* pScore,Contract* objectives,Player* pJoueur){
    int xJoueur=1;
    int yJoueur=1;
    int IsSelected=0;
    char grille[ligne][colonne];
    Grille(grille,pJoueur->level);
    //affichePlateau(grille,xJoueur,yJoueur,IsSelected);
    int getch();
    //variables pour la gestion du temps
    clock_t temps_debut,temps_pause,pause=0.0;
    clock_t temps_ecoule;
    //variables pour la saise utilisateur (choix de direction de déplacement)
    char touche='a';
    //initialisation du temps
    temps_ecoule=0;
    temps_debut = clock();
    clearConsole();
    //boucle de jeu
    do{
        /* partie autonome : ce que fait le programme quoi qu'il arrive */
        //calcul du temps écoulé
        temps_ecoule=(clock()-temps_debut)/CLOCKS_PER_SEC - pause;
        //affichages
        //affichage du temps écoulé et du score
        gotoxy(0, ligne+4);
        printf("Temps : %.1f s  ", 90.0-temps_ecoule);
        affichePlateau(grille,xJoueur,yJoueur,IsSelected,pScore,objectives,pJoueur->level);
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
                temps_pause=clock();
                permutation(grille,xJoueur,yJoueur,touche);
                deplacement(&xJoueur,&yJoueur,touche);
                suppression(grille,pScore,xJoueur,yJoueur,IsSelected,objectives,pJoueur->level);
                IsSelected=0;
                pause+=(double)(clock()-temps_pause)/CLOCKS_PER_SEC;
            }
            else{
                deplacement(&xJoueur,&yJoueur,touche);
            }
        }

    }while(temps_ecoule<=90);





}



int main()
{
     #ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | 0x0004); // ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #endif
    Scores scoring;
    Scores *pScore=NULL;
    pScore=&scoring;
    pScore=initScores(pScore);
    Player joueur;
    Player sauvegarde;
    Player* pJoueur=NULL;
    pJoueur=&joueur;
    Contract todo;
    Contract* objectives=&todo;
    srand(time(NULL));
    int choix,continuer=1;
    clearConsole();
    afficherTitreJeu();
    Sleep(1500);

    do{
        clearConsole();
        afficherMenuTitre();
        afficherMenuPrincipal();
        choix=lireChoixMenu();
        switch(choix){
            case 1:
                pJoueur=initJoueur(pJoueur);
                hide_cursor();
                clearConsole();
                animation_nv(pJoueur->name,pJoueur->level);
                attendreTouche();
                objectives=objectifs(objectives,joueur.level);
                jouer(pScore,objectives,pJoueur);
                while(continuer==1){
                    clearConsole();
                    continuer=partie(pScore,objectives,pJoueur);
                    if(continuer==1){
                        pScore=initScores(pScore);
                        objectives=objectifs(objectives,joueur.level);
                        jouer(pScore,objectives,pJoueur);
                    }
                }

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

    if((choix==1) || (choix==2)){
        sauvegarde.lives=0;
        sauvegarde.level=0;
        sauvegarde.current_best_score=0;
        sauvegarde.all_time_best_score=0;
        pScore->score_total=pScore->scoreF+pScore->scoreM+pScore->scoreO+pScore->scoreP+pScore->scoreS;
        gotoxy(0,15);
        pJoueur->current_best_score=pScore->score_total;
        printf("\t\tScore final : %d\n\n",pScore->score_total);
        printf("S : %d\nF : %d\nP : %d\nO : %d\nM : %d\n\n\n",pScore->scoreS,pScore->scoreF,pScore->scoreP,pScore->scoreO,pScore->scoreM);
        Sleep(2000);

        /*FILE* check_best_score=NULL;
        check_best_score=fopen("saves.txt","wb+");
        fread(&sauvegarde,sizeof(sauvegarde),1,check_best_score);*/
        FILE* highscores=NULL;
        highscores=fopen("saves.dat","rb+");
        if (highscores != NULL) {
            fread(&sauvegarde,sizeof(sauvegarde),1,highscores);
            if(pJoueur->current_best_score > sauvegarde.all_time_best_score){
                pJoueur->all_time_best_score=pJoueur->current_best_score;
                printf("NEW HIGHSCORE !!!\n\n");
            }
            else{
               pJoueur->all_time_best_score=sauvegarde.all_time_best_score;
            }
            rewind(highscores);
        }
        else{
            highscores = fopen("saves.dat", "wb+");  // créer le fichier s’il n’existe pas
            pJoueur->all_time_best_score=pJoueur->current_best_score;
        }

        fwrite(&joueur,sizeof(joueur),1,highscores);
        rewind(highscores);
        fread(&sauvegarde,sizeof(sauvegarde),1,highscores);
        printf("\n\n\nName : %s\t\tlevel : %d \t\t live : %d\n\n\t\t Meilleur de cette partie : %d\t\tMeilleur score toute sauvegardes confondues : %d\n\n\n",sauvegarde.name,sauvegarde.level,sauvegarde.lives,sauvegarde.current_best_score,sauvegarde.all_time_best_score);
        fclose(highscores);
    }


    return 0;
}
