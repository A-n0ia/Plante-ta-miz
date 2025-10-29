#include "paramitz.h"

void suppression(char grille[ligne][colonne],int* score){  //Regarde si une des règles de suppression et vérifiée, auquel cas remplace tous les items concernés par des ' ' dans plateau
    int i,j,k,a,b;
    for(i=0;i<ligne;i++){
        for(j=0;j<colonne;j++){
            verifLigne();
            verifColonne();
        }           
    }
}

                // VERIF EN COLONNE

            
                   
                    
                
            
        
        //IL MANQUE LE H + LE RECTANGLE 
        
        //FAIRE TOMBER LES ITEMS : FONCTION FALL
 
    }
void suppr6(char grille[ligne][colonne],int* score){
    int i,j;
    char swap;
    swap=grille[i][j];
    for(i=0;i<ligne;i++){
        for(j=0;j<colonne;j++){
            if(grille[i][j]==swap){
                grille[i][j]=' ';
                *score++;
            }
        }
    }
}

void verifLigne(char grille[ligne][colonne],int* score){
            if(grille[i][j]==grille[i][j+1]){
                k=0;
                while(grille[i][j]==grille[i][j+k]){
                    k++;
                    if(k>=5){
                        suppr6();
                    }
                 }
            }  
            else if(k>=3){
                *score=*score+4;
            }
}

void verifColonne(char grille[ligne][colonne],int* score){
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
