#include "paramitz.h"
/*
void canne_sucre(char grille[ligne][colonne],int* xJoueur,int* yJoueur,int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM){  // SUPPR DU 5X5
	int i,j;
	for(i=xJoueur-2;i<=xJoueur+2;i++){
		for(j=yJoueur-2;j<=yJoueur+2;j++){

			if(grille[i][j]=='S') (*scoreS)++;
			else if(grille[i][j]=='F') (*scoreF)++;
			else if(grille[i][j])=='P' (*scoreP)++;
			else if(grille[i][j])=='O' (*scoreO)++;
			else if(grille[i][j])=='M' (*scoreM)++;
			grille[i][j]=' ';
		}
	}
}

void nuke_grille(char grille[ligne][colonne],int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM){
	int i,j; 									//DEFINE LIGNE/COLONNE POUR NV 2 ET 3
	for(i=0;i<ligne;i++){
		for(j=0;j<colonne;j++){
			if(grille[i][j]=='S') (*scoreS)++;
			else if(grille[i][j]=='F') (*scoreF)++;
			else if(grille[i][j])=='P' (*scoreP)++;
			else if(grille[i][j])=='O' (*scoreO)++;
			else if(grille[i][j])=='M' (*scoreM)++;
			grille[i][j]=' ';
		}
	}
}


void ITEMS(char grille[ligne][colonne],int* scoreS, int* scoreF, int* scoreP, int* scoreO, int* scoreM){
	int rand_item;
	rand_item=rand()%101;
	if(rand_item<=99){
		canne_sucre(grille,xJoueur,Yjoueur,scoreS,scoreF,scoreP,scoreO,scoreM);   // SUPPR DU 5X5
	}
	else if(rand_item<=100){
		nuke_grille(grille,scoreS,scoreF,scoreP,scoreO,scoreM);   // SUPPR TOUTE LA GRILLE
	}
}
*/

