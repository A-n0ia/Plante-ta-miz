#include "paramitz.h"

void suppression(char grille[ligne][colonne],int* score){  //Regarde si une des règles de suppression et vérifiée, auquel cas remplace tous les items concernés par des ' ' dans plateau
    int i,j,k,a,b;
    char swap;
    for(i=0;i<ligne;i++){
        for(j=0;j<colonne;j++){
            //FAIRE DES FONCTIONS POUR CHAQUE MANIERES DE GAGNER DES POINTS ? 
            //VERIF EN LIGNE

            if(grille[i][j]==grille[i][j+1]){
                k=0;
                while(grille[i][j]==grille[i][j+k]){
                    k++;
                    if(k>=5){
                        swap=grille[i][j];
                        for(a=0;a<ligne;a++){
                            for(b=0;b<colonne;b++){
                                if(grille[a][b]==swap){
                                    grille[a][b]=' ';
                                    *score++;
                                }
                            }
                        }
                    }
                    else if(k>=3){
                *score=*score+4;
                }
            
            }
            }

                // VERIF EN LIGNE

            if(grille[i][j]==grille[i+1][j]){
                k=0;
                while(grille[i][j]==grille[i+k][j]){
                    k++;
                    if(k>=5){
                        swap=grille[i][j];
                        for(a=0;a<ligne;a++){
                            for(b=0;b<colonne;b++){
                                if(grille[a][b]==swap){
                                    grille[a][b]=' ';
                                    *score++;
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
        //IL MANQUE LE H + LE RECTANGLE 
        
        //FAIRE TOMBER LES ITEMS :
        
        
        
        
        
        
        
        
        
        
        
        
    }
