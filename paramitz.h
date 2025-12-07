#ifndef AFFICHAGE_CONSOLE_H_INCLUDED
#define AFFICHAGE_CONSOLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define ligne 25
#define colonne 45
#define ligne2 15
#define colonne2 20
#define jaune "\e[0;33m"
#define rouge "\e[0;31m"
#define vert "\e[0;32m"
#define cyan "\e[0;36m"
#define BgVert "\e[0;102m"
#define BgRouge "\e[0;101m"
#define reset "\e[0m"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                Header pour toutes les fonctions du projet
//                Hésitez pas à changer le nom des fonctions que vous codez ou à rajouter d'autres fonctions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct scores{
    int scoreS;
    int scoreF;
    int scoreP;
    int scoreO;
    int scoreM;
    int score_total;
}Scores;

typedef struct contract{
    int scoreS;
    int scoreF;
    int scoreP;
    int scoreO;
    int scoreM;
}Contract;

typedef struct player{
    char name[20];
    int level;
    int lives;
    int gold;
    int current_best_score;
    int all_time_best_score;
}Player;

void jouer(Scores* pScore,Contract* objectives,Player* pJoueur);
void animation_nv(char nom[20],int level);
void afficheCadre(int largeur,int hauteur);     // Fonction déja fournie dans d'anciens TP
void Grille(char grille[ligne][colonne],int level);            //Remplis le plateau en respectant les conditions initiales
void affichePlateau(char tab[ligne][colonne],int xJoueur,int yJoueur,int IsSelected,Scores* pScore,Contract* ojectives,Player* pJoueur);   //Affiche la matrice à l'écran avec les bonnes couleurs et la "position" du joueur
                                                                        //IsSelected permet de savoir si la case est sélectionnée,auquel cas elle sera mise en évidence (item en minuscule,etc...)
Player* initJoueur(Player* pJoueur);
/*
            Non-testé pour le moment
void verifRectangleEtH(char grille[ligne][colonne],int *score);
int cascade(char grille[ligne][colonne], int *score); //// Supprime les combinaisons et applique cascade
void jeu(); //Pour l'instant niveau 1
*/

void gotoxy(int x, int y);
void deplacement(int* xJoueur,int* yJoueur,char touche);    //Déplace le joueur dans les limites du plateau
void permutation(char grille[ligne][colonne],int xJoueur,int yJoueur,char touche);   //Permute un item selectionné avec un autre dans la matrice carré "plateau"
void suppression(char grille[ligne][colonne],Scores* pScore,int xJoueur,int yJoueur,int IsSelected,Contract* objectives,Player* pJoueur,int suppr);   //Regarde si une des règles de suppression et vérifiée, auquel cas remplace tous les items concernés par des ' ' dans plateau
                                    //Si des 'trous' sont formés, fait tomber les items au-dessus par gravité et ajuste le score en conséquence
void canne_sucre(char grille[ligne][colonne],int xJoueur,int yJoueur,Scores* pScore);
void nuke_grille(char grille[ligne][colonne],Scores* pScore);
int verifLigne(char grille[ligne][colonne], Scores* pScore, int i, int j,Player* pJoueur);
int verifColonne(char grille[ligne][colonne],Scores* pScore, int i, int j,Player* pJoueur);
void suppr6(char grille[ligne][colonne], Scores* pScore, char swap,Player* pJoueur);
void explosion(char grille[ligne][colonne],Scores* pScore,int i,int j,Player* pJoueur);

void remplissage(char grille[ligne][colonne],int xJoueur,int yJoueur,int IsSelected,int level);   //Comble les 'trous' du plateau par des items aléatoires*
void fall(char grille[ligne][colonne]); // fait tomber les items
void gotoxy(int x,int y);
void hide_cursor();
int get_input();


/////// PROTOTYPE DE SOUS-PROGRAMME POUR LE MENU ///////////

/*Fonction qui permet d'éffacer l'écran*/
void clearConsole();
/*Fonction qui affiche le titre du jeu en ASCII avec couleur*/
void afficherTitreJeu();
/*Fonction qui affiche le menu du jeu en ASCII avec couleur*/
void afficherMenuTitre();
void afficherMenuPrincipal(); //Affiche le menu principal
/*Fonction qui permet de lire le choix du joueur et le retourne */
int lireChoixMenu();
/*Fonction de la boucle principale du menu */
//void menuPrincipal();

/////// PROTOTYPE DE SOUS-PROGRAMME POUR LES REGLES DU JEU ///////////
void attendreTouche(); // Appuyer sur Entrée
void ReglesComplet();
void regleObjectif();
void regleItems();
void regleCommandes();
void reglePoints();
void regleFinPartie();
void menuRegles();


/*

.
.
.

*/

#endif


