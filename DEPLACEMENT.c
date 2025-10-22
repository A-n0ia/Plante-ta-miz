void deplacement(int *Xjoueur,int *Yjoueur,char touche){
        if(touche=='z'){
            if(*Yjoueur!=0){
                *Yjoueur--;
            }

        }
        if(touche=='s'){
            if(*Yjoueur!=Y){
                *Yjoueur++;
            }
        }
        if(touche=='d'){
            if(*Xjoueur!=X){
                *Xjoueur++;
            }
        }
        if(touche=='q'){
            if(*Xjoueur!=0){
                *Xjoueur--;
            }
        }
}

void permutation(char grille[][],int Xjoueur,int Yjoueur,char touche){
     char swap;
     if(touche=='z'){
            if(Yjoueur!=0){
                swap=grille[Xjoueur][Yjoueur];
                grille[Xjoueur][Yjoueur]=grille[Xjoueur][Yjoueur-1];
                grille[Xjoueur][Yjoueur-1]=swap;
            }

        }
        if(touche=='s'){
            if(Yjoueur!=Y){
                swap=grille[Xjoueur][Yjoueur];
                grille[Xjoueur][Yjoueur]=grille[Xjoueur][Yjoueur+1];
                grille[Xjoueur][Yjoueur+1]=swap;
            }

        }
        if(touche=='d'){
            if(Xjoueur!=X){
                swap=grille[Xjoueur][Yjoueur];
                grille[Xjoueur][Yjoueur]=grille[Xjoueur+1][Yjoueur];
                grille[Xjoueur+1][Yjoueur]=swap;
            }

        }
        if(touche=='q'){
            if(Xjoueur!=0){
                swap=grille[Xjoueur][Yjoueur];
                grille[Xjoueur][Yjoueur]=grille[Xjoueur-1][Yjoueur];
                grille[Xjoueur-1][Yjoueur]=swap;
            }
        }

}
