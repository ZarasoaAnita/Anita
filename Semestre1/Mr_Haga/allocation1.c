#include <stdio.h>
#include <stdlib.h>
int entrerNombre ( );
int* allouer (int taille);
void entrerValTab (int *tab , int taille);
void afficherTab (int *tab , int taille) ;
int** allouer2D (int ligne,int col);
void entrerValTab2D ( int **tab , int ligne , int col);
void afficherTab2D (int **tab , int ligne , int col);

int main () {
	//int taille=0;
	int ligne =0;
	int col =0;
	int **tab=NULL;
	
	//taille = entrerNombre ();
	ligne = entrerNombre();
	col = entrerNombre() ;
	
	tab = allouer2D (ligne , col);
	//tab = allouer(taille);
	//entrerValTab (tab , taille);
	//afficherTab(tab,taille);
	entrerValTab2D (tab , ligne , col);
	afficherTab2D(tab,ligne , col);
	
	free(tab);
	
	return 0;
}
int entrerNombre ( ) {
	int taille=0;
	printf("Entrez le nombre de ligne ou de colonne du tableau:");
	scanf("%d",&taille);
	return taille;
}

/*int allouer (int taille) {
	tab =(int*) malloc ( sizeof(int) * taille);
	return tab;
}
*/

int** allouer2D(int ligne , int col) {
	int **tab =(int**)malloc(ligne*sizeof(int*));

	for(int i=0 ; i< col ; i++) {
	tab[i] =(int*)malloc(col*sizeof(int));
	}
	
	return tab;
}

void entrerValTab2D (int **tab , int ligne , int col) {
	for(int i=0 ; i<ligne ; i++) {
		for(int j=0 ; j<col ; j++) {
			printf("tab[%d][%d] = ",i,j);
			scanf("%d",&tab[i][j]);
		}
		printf("\n");
	}
}

void afficherTab2D (int **tab , int ligne , int col) {	
	for(int i=0 ; i<ligne ; i++) {
		for(int j=0 ; j<col ; j++) {
			printf("%d\t",tab[i][j]);
		}
		printf("\n");
	}
}
	
	
	
/*void entrerValTab (int *tab , int taille) {
	for(int i=0 ; i<taille ; i++) {
		printf("Entrez la valeur n°%d",i+1);
		scanf("%d",tab+i);
	}
}
*/
/*void afficherTab (int *tab , int taille) {
	for(int i=0 ; i<taille ; i++) {
		printf("tab[%d] = %d\n",i,tab[i]);
	}
}
*/
