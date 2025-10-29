#include "paramitz.h"

void suppression(char grille[ligne][colonne],int* score){  //Regarde si une des règles de suppression et vérifiée, auquel cas remplace tous les items concernés par des ' ' dans plateau
    int i,j,k,a,b;
    for(i=0;i<ligne;i++){
        for(j=0;j<colonne;j++){
            verifLigne(grille,i,j,score);
            verifColonne(grille,i,j,score);
        }           
    }
}

void verifLigne(char grille[ligne][colonne],int* score){    //VERIFIER SI IL Y A UN COMBO DE 4 OU 6 SUR UNE LIGNE
    if(grille[i][j]==grille[i][j+1]){
        k=0;
        while(grille[i][j]==grille[i][j+k]){
           k++;
           if(k>=5){
               char swap;
               swap=grille[i][j];
               suppr6(grille,swap,score);
            }
            else if(k>=3){
               *score=*score+4;
            }
        }
    }   
}

void verifColonne(char grille[ligne][colonne],int* score){        //VERIFIER SI IL Y A UN COMBO DE 4 OU 6 SUR UNE COLONNE
    if(grille[i][j]==grille[i+1][j]){
        k=0;
        while(grille[i][j]==grille[i+k][j]){
            k++;
            if(k>=5){
                swap=grille[i][j];
                char swap;
                swap=grille[i][j];
                suppr6(grille,swap,score);
            }
            else if(k>=3){
                *score=*score+4;
            } 
        }         
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

