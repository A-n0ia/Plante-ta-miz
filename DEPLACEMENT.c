#include "paramitz.h"

void deplacement(int *xJoueur,int *yJoueur,char touche){
        if(touche=='z'){
            if(*yJoueur!=0){
                *yJoueur-=1;
            }

        }
        if(touche=='s'){
            if(*yJoueur!=ligne-1){
                *yJoueur+=1;
            }
        }
        if(touche=='d'){
            if(*xJoueur!=colonne-1){
                *xJoueur+=1;
            }
        }
        if(touche=='q'){
            if(*xJoueur!=0){
                *xJoueur-=1;
            }
        }
}

void permutation(char grille[ligne][colonne],int xJoueur,int yJoueur,char touche){
     char swap;
     if(touche=='z'){
            if(yJoueur!=0){
                swap=grille[yJoueur][xJoueur];
                grille[yJoueur][xJoueur]=grille[yJoueur+1][xJoueur];
                grille[yJoueur+1][xJoueur]=swap;
            }

        }
        if(touche=='s'){
            if(yJoueur!=ligne-1){
                swap=grille[yJoueur][xJoueur];
                grille[yJoueur][xJoueur]=grille[yJoueur+1][xJoueur];
                grille[yJoueur+1][xJoueur]=swap;
            }

        }
        if(touche=='d'){
            if(xJoueur!=colonne-1){
                swap=grille[yJoueur][xJoueur];
                grille[yJoueur][xJoueur]=grille[yJoueur][xJoueur+1];
                grille[yJoueur][xJoueur+1]=swap;
            }

        }
        if(touche=='q'){
            if(xJoueur!=0){
                swap=grille[yJoueur][xJoueur];
                grille[yJoueur][xJoueur]=grille[yJoueur][xJoueur-1];
                grille[yJoueur][xJoueur-1]=swap;
            }
        }

}
