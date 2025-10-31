#include "paramitz.h"

void fall(char grille[ligne][colonne]){
    int i,j,k;
    for (j= 0;j<colonne;j++) {
        for (i=ligne-1;i > 0;i--) {
            if (grille[i][j]==' ') {
                k=i-1;
                while (k>=0 && grille[k][j]==' ') {
                    k--;
                }
                if (k>=0) {
                    grille[i][j]=grille[k][j];
                    grille[k][j]=' ';
                }
            }
        }
    }
}



