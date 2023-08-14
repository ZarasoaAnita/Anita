#include <stdio.h>
#include <stdlib.h>
int entrerNombre ( ) ;
int* allouer(int taille);
void entrerValTab(int *tab, int taille);
void afficherTab(int *tab , int taille);

int main () {
	int taille = 0;
	int *tab =NULL;
	
	taille = entrerNombre();
	tab= allouer(taille);
	entrerValTab(tab , taille);
	afficherTab(tab,taille);
	
	free(tab);
	return 0;
}
int entrerNombre ( ) {
	int taille=0;
	printf("Saisissez la taille du tableau:");
	scanf("%d",&taille);
	return taille ;
}

int* allouer(int taille) {
	int* tab = (int*) malloc(taille*sizeof(int));
	return tab;
}

void entrerValTab(int *tab, int taille) {
	for(int i=0; i<taille ; i++) {
		printf("Entrez la valeur n°%d : ",i+1);
		scanf("%d",tab+i);
	}
}

void afficherTab(int *tab , int taille) {
	for(int i=0 ; i<taille ; i++) {
		printf("%d\n",tab[i]);
	}
}
