#ifndef AFFICHAGE_CONSOLE_H_INCLUDED
#define AFFICHAGE_CONSOLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define ligne 15
#define colonne 25
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

void jouer(int* scoreS,int* scoreF,int* scoreP,int* scoreO,int* scoreM);
void afficheCadre(int largeur,int hauteur);     // Fonction déja fournie dans d'anciens TP
void Grille(char grille[ligne][colonne]);            //Remplis le plateau en respectant les conditions initiales
void affichePlateau(char tab[ligne][colonne],int xJoueur,int yJoueur,int IsSelected);   //Affiche la matrice à l'écran avec les bonnes couleurs et la "position" du joueur
                                                                        //IsSelected permet de savoir si la case est sélectionnée,auquel cas elle sera mise en évidence (item en minuscule,etc...)
/*
            Non-testé pour le moment
void verifRectangleEtH(char grille[ligne][colonne],int *score);
int cascade(char grille[ligne][colonne], int *score); //// Supprime les combinaisons et applique cascade
void jeu(); //Pour l'instant niveau 1
*/


void deplacement(int* xJoueur,int* yJoueur,char touche);    //Déplace le joueur dans les limites du plateau
void permutation(char grille[ligne][colonne],int xJoueur,int yJoueur,char touche);   //Permute un item selectionné avec un autre dans la matrice carré "plateau"
void suppression(char grille[ligne][colonne], int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM);   //Regarde si une des règles de suppression et vérifiée, auquel cas remplace tous les items concernés par des ' ' dans plateau
                                    //Si des 'trous' sont formés, fait tomber les items au-dessus par gravité et ajuste le score en conséquence
int verifLigne(char grille[ligne][colonne], int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM, int i, int j);
int verifColonne(char grille[ligne][colonne],int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM, int i, int j);
void suppr6(char grille[ligne][colonne], int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM, char swap);

void remplissage(char grille[ligne][colonne],int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM);   //Comble les 'trous' du plateau par des items aléatoires*
void fall(char grille[ligne][colonne]); // fait tomber les items
void gotoxy(int x,int y);
void hide_cursor();


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


