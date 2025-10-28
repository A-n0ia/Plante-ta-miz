#include "paramitz.h"

void suppression(char grille[ligne][colonne],int* score);   //Regarde si une des règles de suppression et vérifiée, auquel cas remplace tous les items concernés par des ' ' dans plateau
    int i,j,k,val;
    char swap;
    for(i=0;i<colonne;i++){
        for(j=0;j<ligne;j++){

            //VERIF EN LIGNE

            if(grille[i][j]==grille[i][j+1]){
                k=0;
                while(grille[i][j]==grille[i][j+k]){
                    k++;
                    if(k>=5){
                        swap=grille[i][j];
                        for(i=0;i<colonne;i++){
                            for(j=0;j<ligne;j++){
                                if(grille[i][j]==swap){
                                    grille[i][j]=' ';
                                    *score++;
                                }
                            }
                        }
                    }
                }
            else if(k>=3){
                *score=*score+4;
            }
            }

                // VERIF EN LIGNE

            if(grille[i][j]==grille[i+1][j]){
                k=0;
                while(grille[i][j]==grille[i+k][j]){
                    k++;
                    if(k>=5){
                        swap=grille[i][j];
                        for(i=0;i<colonne;i++){
                            for(j=0;j<ligne;j++){
                                if(grille[i][j]==swap){
                                    grille[i][j]=' ';
                                    *score++;
                                }
                            }
                        }
                    }
                }
                    else if(k>=3){
                        *score=*score+4;
                    }
                }
            }
        }
    }
