#include "paramitz.h"


void Grille(char grille[ligne][colonne]){
    int i,j,swap,swap2,swap3;
    for(i=0;i<ligne;i++){
        for(j=0;j<colonne;j++){
            swap=1+rand()%5;
            swap2=swap;
            swap3=swap;
            if(swap==1){
                grille[i][j]='S';
            }
            else if(swap==2){
                grille[i][j]='F';
            }
            else if(swap==3){
                grille[i][j]='P';
            }
            else if(swap==4){
                grille[i][j]='O';
            }
            else if(swap==5){
                grille[i][j]='M';
            }
            if(grille[i][j]==grille[i][j-1] && grille[i][j]==grille[i][j-2]){ //CHANGE 3 A LA SUITE EN LIGNE
                do{
                    swap2=1+rand()%5;

                }while(swap==swap2);
                swap=swap2;

                if(swap==1){
                    grille[i][j]='S';
                }
                else if(swap==2){
                    grille[i][j]='F';
                }
                else if(swap==3){
                    grille[i][j]='P';
                }
                else if(swap==4){
                    grille[i][j]='O';
                }
                else if(swap==5){
                    grille[i][j]='M';
                }

            }
            if(grille[i][j]==grille[i-1][j] && grille[i][j]==grille[i-2][j]){    //CHANGE 3 A LA SUITE EN COLONNE
                do{
                    swap2=1+rand()%5;

                }while(swap==swap2);
                swap=swap2;

                if(swap==1){
                    grille[i][j]='S';
                }
                else if(swap==2){
                    grille[i][j]='F';
                }
                else if(swap==3){
                    grille[i][j]='P';
                }
                else if(swap==4){
                    grille[i][j]='O';
                }
                else if(swap==5){
                    grille[i][j]='M';
                }

            }
            //test
            if(grille[i][j]==grille[i][j-1] && grille[i][j]==grille[i][j-2]){ //CHANGE 3 A LA SUITE EN LIGNE
                do{
                    swap2=1+rand()%5;

                }while(swap2==swap || swap2==swap3);
                swap=swap2;

                if(swap==1){
                    grille[i][j]='S';
                }
                else if(swap==2){
                    grille[i][j]='F';
                }
                else if(swap==3){
                    grille[i][j]='P';
                }
                else if(swap==4){
                    grille[i][j]='O';
                }
                else if(swap==5){
                    grille[i][j]='M';
                }

            }


    }
}
}
