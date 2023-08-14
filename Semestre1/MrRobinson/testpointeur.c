#include <stdio.h>
#include <stdlib.h>
void inverse ( int *nombreA , int *nombreB);

int main () {
	puts("Inverser des nombres");
	
	int nombreA = 1;
	int nombreB = 1;

///Entrée des données
	printf("Entrez le nombre A: ");
	scanf("%d",&nombreA);
	printf("Entrez le nombre B: ");
	scanf("%d",&nombreB);

///Calcul et sortie de résultats
	inverse(&nombreA , &nombreB);
	
	return 0;
}
void inverse ( int *nombreA , int *nombreB) {
	int temporaire=0;
	
	temporaire = *nombreA;
	*nombreA = *nombreB;
	*nombreB = temporaire;
	
	printf("Apres inversion , A = %d et B = %d",*nombreA,*nombreB);
}	

