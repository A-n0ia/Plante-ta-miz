#include "paramitz.h"

void remplissage(char grille[ligne][colonne],int xJoueur,int yJoueur,int IsSelected,int level){
    int i,j;
    char vide;
    if(level==1){
        for(j=0;j<colonne;j++){
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
    }

    else if(level>=2){
     for(j=0;j<colonne;j++){
        if(grille[0][j]==' '){
            vide=0+rand()%105;
            if(vide<=20){
                grille[0][j]='S';
            }
            else if(vide<=40){
                grille[0][j]='F';
            }
            else if(vide<=60){
                grille[0][j]='P';
            }
            else if(vide<=80){
                grille[0][j]='O';
            }
            else if(vide<=100){
                grille[0][j]='M';
            }
            else{
                grille[0][j]='B';
            }
        }
        }
    }
}


