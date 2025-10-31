#include "paramitz.h"

void suppression(char grille[ligne][colonne], int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM) {    //Regarde si une des règles de suppression et vérifiée, auquel cas remplace tous les items concernés par des ' ' dans plateau
    int i, j;
    for (i = 0; i < ligne; i++) {
        for (j = 0; j < colonne; j++) {
            verifLigne(grille, scoreS, scoreF, scoreP, scoreO, scoreM, i, j);
            verifColonne(grille, scoreS, scoreF, scoreP, scoreO, scoreM, i, j);
        }
    }
}

void verifLigne(char grille[ligne][colonne], int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM, int i, int j) {   //VERIFIE SI IL Y A UN COMBO DE 4 OU 6 SUR UNE LIGNE
    int k, a;
    if (j + 1 >= colonne) return;                                         
    if (grille[i][j] == ' ') return;

    k = 1;
    while (j + k < colonne && grille[i][j] == grille[i][j + k]) {
        k++;
    }

    if (k >= 6) {
        suppr6(grille, scoreS, scoreF, scoreP, scoreO, scoreM, grille[i][j]);
    } else if (k >= 4) {
        if(grille[i][j]=='S') (*scoreS)+=4;
        else if(grille[i][j]=='F') (*scoreF)+=4;
        else if(grille[i][j]=='P') (*scoreP)+=4;
        else if(grille[i][j]=='O') (*scoreO)+=4;
        else if(grille[i][j]=='M') (*scoreM)+=4;
        for (a = 0; a < k; a++) {
            grille[i][j + a] = ' ';
        }
    }
}
void verifColonne(char grille[ligne][colonne], int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM, int i, int j) { 		//VERIFIE SI IL Y A UN COMBO DE 4 OU 6 SUR UNE COLONNE
    int k, a;
    if (i + 1 >= ligne) return;
    if (grille[i][j] == ' ') return;
    k = 1;
    while (i + k < ligne && grille[i][j] == grille[i + k][j]) {
        k++;
    }
    if (k >= 6) {
        suppr6(grille, scoreS, scoreF, scoreP, scoreO, scoreM, grille[i][j]);
    } else if (k >= 4) {
        if(grille[i][j]=='S') (*scoreS)+=4;
        else if(grille[i][j]=='F') (*scoreF)+=4;
        else if(grille[i][j]=='P') (*scoreP)+=4;
        else if(grille[i][j]=='O') (*scoreO)+=4;
        else if(grille[i][j]=='M') (*scoreM)+=4;
        for (a = 0; a < k; a++) {
            grille[i + a][j] = ' ';
        }
    }
}
void suppr6(char grille[ligne][colonne], int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM, char swap) { 		//SUPPRIME TOUT LES ITEMS EN CAS DE COMBO 6 
    int i, j;
    for (i = 0; i < ligne; i++) {
        for (j = 0; j < colonne; j++) {
            if (grille[i][j] == swap) {
                if(grille[i][j]=='S') (*scoreS)++;
                else if(grille[i][j]=='F') (*scoreF)++;
                else if(grille[i][j]=='P') (*scoreP)++;
                else if(grille[i][j]=='O') (*scoreO)++;
                else if(grille[i][j]=='M') (*scoreM)++;
				grille[i][j] = ' ';
            }
        }
    }
}


void supprH(char grille[ligne][colonne],int* score,char swap){
    
}











