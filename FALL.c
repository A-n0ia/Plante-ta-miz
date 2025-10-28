#include "paramitz.h"

void fall(char grille[ligne][colonne]){
    int i,j,k,cpt;
    for(i=ligne;i>0;i--){
        for(j=0;j<colonne;j++){
            if(grille[i][j]==' '){
                    cpt=i;
                    k=0;
                    while(cpt!=0){
                        grille[i+k][j]=grille[i+k+1][j];
                        k++;
                        cpt--;
                    }

            }
        }
    }

}

