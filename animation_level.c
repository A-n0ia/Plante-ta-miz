#paramitz.h

void animation_nv(int level){
	int i,j;
	if(level==2){
		char mot[30]="NEXT LEVEL UNLOCKED : 2";
		for(j=0;j<15;j++){
			printf("\n");
		}
		for(j=0;j<6;j++){
			printf("\t");
		}
	
		for(i=0;i<25;i++){
			printf("%c",mot[i]);
			Sleep(150);
		}
		sleep(10000);
		}
	if(level==3){
		char mot[30]="NEXT LEVEL UNLOCKED : 3";
		for(j=0;j<15;j++){
			printf("\n");
		}
		for(j=0;j<6;j++){
			printf("\t");
		}
	
		for(i=0;i<25;i++){
			printf("%c",mot[i]);
			Sleep(120);
		}
		Sleep(10000);
		}
	
}




