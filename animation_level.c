#include "paramitz.h"

void animation_nv(char nom[20],int level){
	int j,i=0;
	if(level == 1){
        gotoxy(20,7);
        printf("Bienvenue \e[4;31m");
        while(nom[i]!='\0'){
			printf("%c",nom[i]);
			Sleep(200);
			i++;
		}
        printf(reset" !  Vous entrez maintenant dans le 1er niveau !");
        gotoxy(42,9);
        printf(jaune "Bonne chance"reset);
        gotoxy(6,13);
	}


	else if(level==2){
		char mot[30]="NEXT LEVEL UNLOCKED : 2";
        gotoxy(6,15);
		for(i=0;i<25;i++){
			printf("%c",mot[i]);
			Sleep(150);
		}
		gotoxy(10,20);
		printf("Des %c apparaitront maintenant de tant en tant. Mettez-les en début ou fin de combos pour creer une explosion !",0x0F);
    }
	else if(level==3){
		char mot[30]="NEXT LEVEL UNLOCKED : 3";
		gotoxy(6,15);

		for(i=0;i<25;i++){
			printf("%c",mot[i]);
			Sleep(120);
		}
    }

}




