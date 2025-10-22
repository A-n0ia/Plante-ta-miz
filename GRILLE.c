#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define X 25
#define Y 45
#define jaune "\e[0;33m"
#define rouge "\e[0;31m"
#define vert "\e[0;32m"
#define cyan "\e[0;36m"

#define reset "\e[0m"

void grille(){
    int i,j,swap,swap2,swap3;
    char grille[X][Y];
    srand(time(NULL));
    for(i=0;i<X;i++){
        for(j=0;j<Y;j++){
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



        if(swap==1){
            printf(jaune "%c " reset,grille[i][j]);
        }
        else if(swap==2){
            printf(rouge "%c "reset,grille[i][j]);
        }
        else if(swap==3){
            printf(vert "%c "reset,grille[i][j]);
        }
        else if(swap==4){
            printf("%c ",grille[i][j]);
        }
        else if(swap==5){
            printf(cyan"%c "reset,grille[i][j]);
        }


    }
       printf("\n");
}
}
int main(){
srand(time(NULL));
grille();

return 0;
}
