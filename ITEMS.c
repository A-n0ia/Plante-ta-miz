#include "paramitz.h"

void canne_sucre(char grille[ligne][colonne],int xJoueur,int yJoueur,Scores* pScore){  // SUPPR DU 7X7
    int k, l;
    int centre_i = xJoueur;
    int centre_j = yJoueur;
    for (k = centre_i - 3; k <= centre_i + 3; k++) {
        for (l = centre_j - 3; l <= centre_j + 3; l++) {
            // On vérifie qu'on ne sort pas de la grille
            if (k >= 0 && k < ligne && l >= 0 && l < colonne) {
                if (grille[k][l] == 'S') {pScore->scoreS++;}
                else if (grille[k][l] == 'F') {pScore->scoreF++;}
                else if (grille[k][l] == 'P') {pScore->scoreP++;}
                else if (grille[k][l] == 'O') {pScore->scoreO++;}
                else if (grille[k][l] == 'M') {pScore->scoreM++;}
                grille[k][l] = ' ';
            }
        }
    }
}

void nuke_grille(char grille[ligne][colonne],Scores* pScore){
	int i,j; 									//DEFINE LIGNE/COLONNE POUR NV 2 ET 3
	for(i=0;i<ligne;i++){
		for(j=0;j<colonne;j++){
			if(grille[i][j]=='S') (pScore->scoreS)++;
			else if(grille[i][j]=='F') (pScore->scoreF)++;
			else if(grille[i][j]=='P') (pScore->scoreP)++;
			else if(grille[i][j]=='O') (pScore->scoreO)++;
			else if(grille[i][j]=='M') (pScore->scoreM)++;
			grille[i][j]=' ';
		}
	}
}

