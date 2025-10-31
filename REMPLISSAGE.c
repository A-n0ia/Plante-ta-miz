#include "paramitz.h"

void remplissage(char grille[ligne][colonne]){
    int j,vide;
        for(j=0;j<colonne;j++)
            if(grille[0][j]==' '){
                vide=1+rand()%5;
                if(vide==1){
                    grille[0][j]='S';
                }
                else if(vide==2){
                    grille[0][j]='F';
                }
                else if(vide==3){
                    grille[0][j]='P';
                }
                else if(vide==4){
                    grille[0][j]='O';
                }
                else if(vide==5){
                    grille[0][j]='M';
                }
            }
}








