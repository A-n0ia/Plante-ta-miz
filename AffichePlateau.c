#include "paramitz.h"


void affichePlateau(char tab[ligne][colonne],int xJoueur,int yJoueur,int IsSelected){
    for(int i=0;i<ligne;i++){
        for(int j=0;j<colonne;j++){
            if(tab[i][j]=='S'){
                if((i==yJoueur)&&(j==xJoueur)){
                    if(IsSelected){
                        printf("\e[0;101;33m" "%c " reset,tab[i][j]);
                   }
                   else{
                        printf("\e[0;102;33m" "%c " reset,tab[i][j]);
                   }
                }
                else{
                    printf(jaune "%c " reset,tab[i][j]);
                }
            }

            else if(tab[i][j]=='F'){
                if((i==yJoueur)&&(j==xJoueur)){
                    if(IsSelected){
                        printf("\e[0;101;31m" "%c " reset,tab[i][j]);
                   }
                   else{
                        printf("\e[0;102;31m" "%c " reset,tab[i][j]);
                   }
                }
                else{
                    printf(rouge "%c " reset,tab[i][j]);
                }
            }

            else if(tab[i][j]=='P'){
                if((i==yJoueur)&&(j==xJoueur)){
                    if(IsSelected){
                        printf("\e[0;101;32m" "%c " reset,tab[i][j]);
                   }
                   else{
                        printf("\e[0;102;32m" "%c " reset,tab[i][j]);
                   }
                }
                else{
                    printf(vert "%c " reset,tab[i][j]);
                }
            }

            else if(tab[i][j]=='O'){
                if((i==yJoueur)&&(j==xJoueur)){
                    if(IsSelected){
                        printf(BgRouge "%c " reset,tab[i][j]);
                   }
                   else{
                        printf(BgVert "%c " reset,tab[i][j]);
                   }
                }
                else{
                    printf("%c " reset,tab[i][j]);
                }
            }

            else if(tab[i][j]=='M'){
                if((i==yJoueur)&&(j==xJoueur)){
                    if(IsSelected){
                        printf("\e[0;101;36m" "%c " reset,tab[i][j]);
                   }
                   else{
                        printf("\e[0;102;36m" "%c " reset,tab[i][j]);
                   }
                }
                else{
                    printf(cyan "%c " reset,tab[i][j]);
                }
            }
        }
        printf("\n");
    }

}
