#include <stdio.h>
#include <math.h>

int main () {
	printf("Calcul de 1+2+...+n\n");
	
	int i = 1 , //le compteur
		somme = 0 ,//la somme à calculer
		n = 0 ; //la limite de la somme
		
///Entrée de données 
	printf("Entrez l'entier n:");
	scanf("%d",&n);

///Traitement
	for ( i=1 , somme = 0 ; i <= n ; i++ ) {
		somme += i ;
	}

///Sortie de résultat
	printf("Pour n = %d , la somme 1+...+n = %d\n",n,somme);
	
	return 0 ;
}
