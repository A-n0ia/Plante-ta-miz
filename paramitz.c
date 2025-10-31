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

 void permutation(char grille[ligne][colonne],int xJoueur,int yJoueur,char touche, int IsSelected){
     char swap;
     if(!IsSelected){
        return;
     }

     if(touche=='z'){
            if(yJoueur!=0 ){
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

void remplissage(char grille[ligne][colonne]){
    int i,j;
    char vide;
    for (i=0;i<ligne;i++){
        for (j=0;j<colonne;j++){
            if(grille[i][j]=' '){
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
    }
}

void fall(char grille[ligne][colonne]){
    int i,j,k,cpt;
    for(i=ligne;i>1;i--){
        for(j=0;j<colonne;j++){
            if(grille[i][j]==' '){
                    cpt=i;
                    k=0;
                    while(cpt!=1){
                        grille[i+k][j]=grille[i+k+1][j];
                        k++;
                        cpt--;
                    }

            }
        }
    }

}

void suppression(char grille[ligne][colonne],int* score){  //Regarde si une des règles de suppression et vérifiée, auquel cas remplace tous les items concernés par des ' ' dans plateau
    int i,j;
    for(i=0;i<ligne;i++){
        for(j=0;j<colonne;j++){
            verifLigne(grille,score,i,j);
            verifColonne(grille,score,i,j);
        }
    }
    verifRectangleEtH(grille, score);
}

void verifLigne(char grille[ligne][colonne],int* score,int i,int j){    //VERIFIE SI IL Y A UN COMBO DE 4 OU 6 SUR UNE LIGNE
    char swap;
    int k,a;
    if (j + 1 >= colonne) return;
    if (grille[i][j] == ' ') return;
    if(grille[i][j]==grille[i][j+1]){
        k=1;
        while(j + k < colonne && grille[i][j]==grille[i][j+k]){
           k++;
           if(k>=6){
               swap=grille[i][j];
               suppr6(grille,score,swap);
            }
            else if(k>=4){
               *score=*score+4;      //SCORE +4 AVEC LIGNE DE 4 ITEMS
               for (a = 0; a < k; a++) {
                   grille[i][j + a] = ' ';
               }
            }
        }
    }
}

void verifColonne(char grille[ligne][colonne],int* score,int i,int j){        //VERIFIE SI IL Y A UN COMBO DE 4 OU 6 SUR UNE COLONNE
    char swap;
    int k,a;
    if (i + 1 >= ligne) return;
    if (grille[i][j] == ' ') return;
    if(grille[i][j]==grille[i+1][j]){
        k=1;
        while(i + k < ligne && grille[i][j]==grille[i+k][j]){
            k++;
            if(k>=6){
                swap=grille[i][j];
                suppr6(grille,score,swap);
            }
            else if(k>=4){
                *score=*score+4;                                  //SCORE +4 AVEC COLONNE DE 4 ITEMS
                for (a = 0; a < k; a++) {
                    grille[i + a][j] = ' ';
                }
            }
        }
    }
}


void suppr6(char grille[ligne][colonne],int* score,char swap){        //SUPPRIME TOUT LES ITEMS EN CAS DE COMBO 6
    int i,j;
    for(i=0;i<ligne;i++){
        for(j=0;j<colonne;j++){
            if(grille[i][j]==swap){
                grille[i][j]=' ';
                (*score)++;
            }
        }
    }
}

void verifRectangleEtH(char grille[ligne][colonne], int *score) {
    int i, j, a, b;
    int hauteur;
    int largeur;
    char ref;
    int estRectangle;

    for (i = 0; i < ligne - 1; i++) {
        for (j = 0; j < colonne - 1; j++) {

            ref = grille[i][j];
            if (ref == ' ') {
                continue;
            }

            hauteur = 1;
            largeur = 1;

            // Cherche la largeur
            while (j + largeur < colonne && grille[i][j + largeur] == ref) {
                largeur++;
            }

            // Cherche la hauteur
            while (i + hauteur < ligne && grille[i + hauteur][j] == ref) {
                hauteur++;
            }

            // Vérification si rectangle
            estRectangle = 1;
            for (a = 0; a < hauteur; a++) {
                for (b = 0; b < largeur; b++) {
                    if (grille[i + a][j + b] != ref) {
                        estRectangle = 0;
                    }
                }
                if (!estRectangle) break;
            }

            // Vérification si au moins rectangle 2x2
            if (estRectangle && largeur >= 2 && hauteur >= 2) {
                *score += 2 * (largeur * hauteur);

                // Supprime les cases du rectangle
                for (a = 0; a < hauteur; a++) {
                    for (b = 0; b < largeur; b++) {
                        grille[i + a][j + b] = ' ';
                    }
                }
            }

            // --- Vérification d’un “H” classique 3x3 ---
            // (X . X / X X X / X . X)
            if (i + 2 < ligne && j + 2 < colonne) {
                if (grille[i][j] == ref && grille[i + 1][j] == ref && grille[i + 2][j] == ref &&
                    grille[i][j + 2] == ref && grille[i + 1][j + 2] == ref && grille[i + 2][j + 2] == ref &&
                    grille[i + 1][j + 1] == ref) {

                    int nbCases = 7;
                    *score += 2 * nbCases;

                    // Supprime les cases du H
                    grille[i][j] = ' ';
                    grille[i + 1][j] = ' ';
                    grille[i + 2][j] = ' ';
                    grille[i][j + 2] = ' ';
                    grille[i + 1][j + 2] = ' ';
                    grille[i + 2][j + 2] = ' ';
                    grille[i + 1][j + 1] = ' ';
                }
            }
        }
    }
}

int cascade(char grille[ligne][colonne], int *score) {
    int scoreAvant, scoreApres;

    do {
        scoreAvant = *score;

        // Supprime les lignes/colonnes de 4,5,6
        suppression(grille, score);

        // Supprime les rectangles ou H
        verifRectangleEtH(grille, score);

        // Fait tomber les cases
        fall(grille);

        // Ici tu peux appeler une fonction remplissage si tu veux remplir le haut
        // remplissage(grille);

        scoreApres = *score;
    } while(scoreApres > scoreAvant); // Tant que des points ont été ajoutés, continue
}

void jeu(){
    int xJoueur = 1 + rand() % (colonne - 1);
    int yJoueur = 1 + rand() % (ligne - 1);
    int IsSelected = 0;
    char grille[ligne][colonne];
    char touche;
    int score = 0;

    srand(time(NULL));
    Grille(grille);

    while (1) {
        system("cls");
        affichePlateau(grille, xJoueur, yJoueur, IsSelected);
        printf("Score : %d\n", score);
        printf("Deplacez le curseur (zqsd), (e) pour sélectionner, x pour quitter : ");

        touche = getch();
        if (touche == 'x') break;

        if (touche == ' ') {
            IsSelected = !IsSelected;  // selection/deselection
        }
        else if (IsSelected) {
            // Permutation si une case est sélectionnée
            permutation(grille, xJoueur, yJoueur, touche, IsSelected);

            // Supprime les combinaisons et applique cascade
            cascade(grille, &score);

            // Après la cascade, tombe les cases et remplissage
            fall(grille);
            remplissage(grille);
        }
        else {
            // Déplacement du curseur
            deplacement(&xJoueur, &yJoueur, touche);
        }
    }

    printf("\n=== Jeu termine ! Score final : %d ===\n", score);
}


