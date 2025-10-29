#include "paramitz.h"

void suppression(char grille[ligne][colonne],int* score){  //Regarde si une des règles de suppression et vérifiée, auquel cas remplace tous les items concernés par des ' ' dans plateau
    int i,j;
    for(i=0;i<ligne;i++){
        for(j=0;j<colonne;j++){
            verifLigne(grille,score,i,j);
            verifColonne(grille,score,i,j);
        }           
    }
}

void verifLigne(char grille[ligne][colonne],int* score,int i,int j){    //VERIFIER SI IL Y A UN COMBO DE 4 OU 6 SUR UNE LIGNE
    char swap;
    int k,a;
    if (j + 1 >= ligne) return;
    if(grille[i][j]==grille[i][j+1]){
        k=1;
        while(grille[i][j]==grille[i][j+k]){
           k++;
           if(k>=6){
               swap=grille[i][j];
               suppr6(grille,score,swap);
            }
            else if(k>=4){
               *score=*score+4;      //SCORE +4 AVEC LIGNE DE 4 ITEMS
               for (a = 0; a < k; a++) {
                   grille[i][j + a] = ' ';
               }
            }
        }
        j=j+k;     
    }   
}

void verifColonne(char grille[ligne][colonne],int* score,int i,int j){        //VERIFIER SI IL Y A UN COMBO DE 4 OU 6 SUR UNE COLONNE
    char swap;
    int k,a;
    if (i + 1 >= ligne) return;
    if(grille[i][j]==grille[i+1][j]){
        k=1;
        while(grille[i][j]==grille[i+k][j]){
            k++;
            if(k>=6){
                swap=grille[i][j];
                suppr6(grille,score,swap);
            }
            else if(k>=4){
                *score=*score+4;                                  //SCORE +4 AVEC COLONNE DE 4 ITEMS
                for (a = 0; a < k; a++) {
                    grille[i + a][j] = ' ';
                }
            } 
        }
        i=i+k;
    }
}


void suppr6(char grille[ligne][colonne],int* score,char swap){        //SUPPRIMER TOUT LES ITEMS EN CAS DE COMBO 6 
    int i,j;
    for(i=0;i<ligne;i++){
        for(j=0;j<colonne;j++){
            if(grille[i][j]==swap){
                grille[i][j]=' ';
                (*score)++;
            }
        }
    }
}





