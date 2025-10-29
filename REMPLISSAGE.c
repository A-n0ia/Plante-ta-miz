#include "paramitz.h"

void remplissage(char grille[ligne][colonne]){
    int i,j;
    char vide;
    srand(time(NULL));
        for(j=0;j<colonne;j++)
            if(grille[i][j]==' '){
                vide=1+rand()%5;
                if(vide==1){
                    grille[i][j]='S';
                }
                else if(vide==2){
                    grille[i][j]='F';
                }
                else if(vide==3){
                    grille[i][j]='P';
                }
                else if(vide==4){
                    grille[i][j]='O';
                }
                else if(vide==5){
                    grille[i][j]='M';
                }
            }
}





