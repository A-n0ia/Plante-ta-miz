#include "paramitz.h"

void suppression(char grille[ligne][colonne], Scores* pScore,int xJoueur,int yJoueur,int IsSelected,Contract* objectives,Player* pJoueur,int suppr){  //Regarde si une des règles de suppression et vérifiée, auquel cas remplace tous les items concernés par des ' ' dans plateau
    int i,j,a;
    for(i=0;i<ligne;i++){
        for(j=0;j<colonne;j++){
            suppr+=verifLigne(grille, pScore, i, j,pJoueur);
            suppr+=verifColonne(grille, pScore, i, j,pJoueur);
        }
    }
    if(suppr>0){
        do{
            a=1;
            fall(grille);
            affichePlateau(grille,xJoueur,yJoueur,IsSelected,pScore,objectives,pJoueur);
            remplissage(grille,xJoueur,yJoueur,IsSelected,pJoueur->level);
            affichePlateau(grille,xJoueur,yJoueur,IsSelected,pScore,objectives,pJoueur);
            for(i=0;i<ligne;i++){
                for(j=0;j<colonne;j++){
                    if(grille[i][j]==' '){
                        a=0;
                    }
                }
            }
        }while(a==0);
        suppression(grille,pScore,xJoueur,yJoueur,IsSelected,objectives,pJoueur,0);
    }
}

int verifLigne(char grille[ligne][colonne], Scores* pScore, int i, int j,Player* pJoueur){    //VERIFIE SI IL Y A UN COMBO DE 4 OU 6 SUR UNE LIGNE
    int k,a;
    int suppr=0;
    if (j + 1 < colonne){
        if(grille[i][j]==grille[i][j+1]){
            k=1;
            while(j + k < colonne && grille[i][j]==grille[i][j+k]){
                k++;
            }
            if(k>=6){
                if(grille[i][j-1]=='B'){
                    explosion(grille,pScore,i,j-1,pJoueur);
                }
                else if((grille[i][j+k]=='B')){
                    explosion(grille,pScore,i,j+k,pJoueur);
                }
                suppr6(grille, pScore, grille[i][j],pJoueur);

                suppr=1;
            }
            else if(k>=4){

                if(grille[i][j]=='S'){
                        (*pScore).scoreS+=k;
                }
                else if(grille[i][j]=='F'){
                        (*pScore).scoreF+=k;
                }
                else if(grille[i][j]=='P'){
                    (*pScore).scoreP+=k;
                }
                else if(grille[i][j]=='O'){
                    (*pScore).scoreO+=k;
                }
                else if(grille[i][j]=='M'){
                    (*pScore).scoreM+=k;
                }
                pJoueur->gold+=k;
                suppr=1;

                for (a = 0; a < k; a++) {
                    grille[i][j + a] = ' ';
                }
                if(grille[i][j-1]=='B'){
                    explosion(grille,pScore,i,j-1,pJoueur);
                }
                else if((grille[i][j+k]=='B')){
                    explosion(grille,pScore,i,j+k,pJoueur);
                }
            }

        }
    }
    return suppr;
}

int verifColonne(char grille[ligne][colonne],Scores* pScore, int i, int j,Player* pJoueur){        //VERIFIE SI IL Y A UN COMBO DE 4 OU 6 SUR UNE COLONNE
    int k,a;
    int suppr=0;
    if (i + 1 < ligne){
        if(grille[i][j]==grille[i+1][j]){
            k=1;
            while(i + k < ligne && grille[i][j]==grille[i+k][j]){
                k++;
            }
            if(k>=6){
                if(grille[i-1][j]=='B'){
                    explosion(grille,pScore,i-1,j,pJoueur);
                }
                else if((grille[i+k][j]=='B')){
                    explosion(grille,pScore,i+k,j,pJoueur);
                }
                    suppr6(grille, pScore, grille[i][j],pJoueur);
                    suppr=1;
                }
                else if(k>=4){
                    if(grille[i][j]=='S'){
                        (*pScore).scoreS+=k;
                    }
                    else if(grille[i][j]=='F'){
                        (*pScore).scoreF+=k;
                    }
                    else if(grille[i][j]=='P'){
                        (*pScore).scoreP+=k;
                    }
                    else if(grille[i][j]=='O'){
                        (*pScore).scoreO+=k;
                    }
                    else if(grille[i][j]=='M'){
                        (*pScore).scoreM+=k;
                    }
                    pJoueur->gold+=k;
                    suppr=1;
                    for (a = 0; a < k; a++) {
                        grille[i + a][j] = ' ';
                    }
                    if(grille[i-1][j]=='B'){
                        explosion(grille,pScore,i-1,j,pJoueur);
                    }
                    else if((grille[i+k][j]=='B')){
                        explosion(grille,pScore,i+k,j,pJoueur);
                    }
                }
        }
    }
    return suppr;
}


void suppr6(char grille[ligne][colonne], Scores* pScore, char swap,Player* pJoueur) { 		//SUPPRIME TOUT LES ITEMS EN CAS DE COMBO 6
    int i, j;
    int cpt=0;
    for (i = 0; i < ligne; i++) {
        for (j = 0; j < colonne; j++) {
            if (grille[i][j] == swap) {
                cpt++;
				grille[i][j] = ' ';
            }
        }
    }
    if(swap=='S'){pScore->scoreS+=cpt;}
    else if(swap=='F') {pScore->scoreF+=cpt;}
    else if(swap=='P') {pScore->scoreP+=cpt;}
    else if(swap=='O') {pScore->scoreO+=cpt;}
    else if(swap=='M') {pScore->scoreM+=cpt;}
    pJoueur->gold+=cpt;
}

void explosion(char grille[ligne][colonne], Scores* pScore, int i, int j,Player* pJoueur) {
    int k, l;
    int centre_i = i;
    int centre_j = j;
    for (k = centre_i - 2; k <= centre_i + 2; k++) {
        for (l = centre_j - 2; l <= centre_j + 2; l++) {
            // On vérifie qu'on ne sort pas de la grille
            if (k >= 0 && k < ligne && l >= 0 && l < colonne) {
                if (grille[k][l] == 'S') {pScore->scoreS++;}
                else if (grille[k][l] == 'F') {pScore->scoreF++;}
                else if (grille[k][l] == 'P') {pScore->scoreP++;}
                else if (grille[k][l] == 'O') {pScore->scoreO++;}
                else if (grille[k][l] == 'M') {pScore->scoreM++;}
                grille[k][l] = ' ';
                pJoueur->gold++;
            }
        }
    }
}


/*void supprH(char grille[ligne][colonne],int* score,char swap){

}*/








