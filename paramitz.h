#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ligne 25
#define colonne 45

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                Header pour toutes les fonctions du projet
//                Hésitez pas à changer le nom des fonctions que vous codez ou à rajouter d'autres fonctions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void afficheCadre(int largeur,int hauteur);     // Fonction déja fournie dans d'anciens TP
void Initialisation(char** plateau);            //Remplis le plateau en respectant les conditions initiales
void affichePlateau(char** plateau,int xJoueur,int yJoueur,int IsSelected);   //Affiche la matrice à l'écran avec les bonnes couleurs et la "position" du joueur
                                                                        //IsSelected permet de savoir si la case est sélectionnée,auquel cas elle sera mise en évidence (item en minuscule,etc...)
void deplacement(int* xJoueur,int* yJoueur);    //Déplace le joueur dans les limites du plateau
void permutation(char** plateau,int xJoueur,int yJoueur,char touche);   //Permute un item selectionné avec un autre dans la matrice carré "plateau"
void suppression(char** plateau,int* score);   //Regarde si une des règles de suppression et vérifiée, auquel cas remplace tous les items concernés par des ' ' dans plateau
                                    //Si des 'trous' sont formés, fait tomber les items au-dessus par gravité et ajuste le score en conséquence
void remplissage(char** plateau);   //Comble les 'trous' du plateau par des items aléatoires
int menu();

/*

.
.
.

*/