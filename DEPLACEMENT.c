#include "paramitz.h"

void deplacement(int *xJoueur,int *yJoueur,char touche){
        if(touche=='z'){
            if(*yJoueur!=0){
                *yJoueur--;
            }

        }
        if(touche=='s'){
            if(*yJoueur!=colonne){
                *yJoueur++;
            }
        }
        if(touche=='d'){
            if(*xJoueur!=ligne){
                *xJoueur++;
            }
        }
        if(touche=='q'){
            if(*xJoueur!=0){
                *xJoueur--;
            }
        }
}

void permutation(char grille[ligne][colonne],int xJoueur,int yJoueur,char touche){
     char swap;
     if(touche=='z'){
            if(yJoueur!=0){
                swap=grille[xJoueur][yJoueur];
                grille[xJoueur][yJoueur]=grille[xJoueur][yJoueur-1];
                grille[xJoueur][yJoueur-1]=swap;
            }

        }
        if(touche=='s'){
            if(yJoueur!=colonne){
                swap=grille[xJoueur][yJoueur];
                grille[xJoueur][yJoueur]=grille[xJoueur][yJoueur+1];
                grille[xJoueur][yJoueur+1]=swap;
            }

        }
        if(touche=='d'){
            if(xJoueur!=ligne){
                swap=grille[xJoueur][yJoueur];
                grille[xJoueur][yJoueur]=grille[xJoueur+1][yJoueur];
                grille[xJoueur+1][yJoueur]=swap;
            }

        }
        if(touche=='q'){
            if(xJoueur!=0){
                swap=grille[xJoueur][yJoueur];
                grille[xJoueur][yJoueur]=grille[xJoueur-1][yJoueur];
                grille[xJoueur-1][yJoueur]=swap;
            }
        }

}
