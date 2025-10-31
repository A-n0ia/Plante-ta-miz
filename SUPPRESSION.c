#include "paramitz.h"

void suppression(char grille[ligne][colonne], int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM){  //Regarde si une des règles de suppression et vérifiée, auquel cas remplace tous les items concernés par des ' ' dans plateau
    int i,j,suppr=0;
    for(i=0;i<ligne;i++){
        for(j=0;j<colonne;j++){
            suppr+=verifLigne(grille, scoreS, scoreF, scoreP, scoreO, scoreM, i, j);
            suppr+=verifColonne(grille, scoreS, scoreF, scoreP, scoreO, scoreM, i, j);
        }
    }
    if(suppr>0){
        fall(grille);
        remplissage(grille,scoreS,scoreF,scoreP,scoreO,scoreM);
    }
}

int verifLigne(char grille[ligne][colonne], int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM, int i, int j){    //VERIFIE SI IL Y A UN COMBO DE 4 OU 6 SUR UNE LIGNE
    int k,a;
    int suppr=0;
    if (j + 1 < colonne){
        if(grille[i][j]==grille[i][j+1]){
            k=1;
            while(j + k < colonne && grille[i][j]==grille[i][j+k]){
                k++;
            }
            if(k>=6){
                suppr6(grille, scoreS, scoreF, scoreP, scoreO, scoreM, grille[i][j]);
                suppr=1;
            }
            else if(k>=3){
                if(grille[i][j]=='S'){
                        (*scoreS)+=k;
                }
                else if(grille[i][j]=='F'){
                        (*scoreF)+=k;
                }
                else if(grille[i][j]=='P'){
                    (*scoreP)+=k;
                }
                else if(grille[i][j]=='O'){
                    (*scoreO)+=k;
                }
                else if(grille[i][j]=='M'){
                    (*scoreM)+=k;
                }
                suppr=1;
                for (a = 0; a < k; a++) {
                    grille[i][j + a] = ' ';
                }
            }

        }
    }
    return suppr;
}

int verifColonne(char grille[ligne][colonne],int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM, int i, int j){        //VERIFIE SI IL Y A UN COMBO DE 4 OU 6 SUR UNE COLONNE
    int k,a;
    int suppr=0;
    if (i + 1 < ligne){
        if(grille[i][j]==grille[i+1][j]){
            k=1;
            while(i + k < ligne && grille[i][j]==grille[i+k][j]){
                k++;
            }
            if(k>=6){
                    suppr6(grille, scoreS, scoreF, scoreP, scoreO, scoreM, grille[i][j]);
                    suppr=1;
                }
                else if(k>=3){
                    if(grille[i][j]=='S'){
                        (*scoreS)+=k;
                    }
                    else if(grille[i][j]=='F'){
                        (*scoreF)+=k;
                    }
                    else if(grille[i][j]=='P'){
                        (*scoreP)+=k;
                    }
                    else if(grille[i][j]=='O'){
                        (*scoreO)+=k;
                    }
                    else if(grille[i][j]=='M'){
                        (*scoreM)+=k;
                    }
                    suppr=1;
                    for (a = 0; a < k; a++) {
                        grille[i + a][j] = ' ';
                    }
                }
        }
    }
    return suppr;
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

/*void supprH(char grille[ligne][colonne],int* score,char swap){

}*/








