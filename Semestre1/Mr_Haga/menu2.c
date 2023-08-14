#include<stdio.h>
#include "table.c"
#include "parfait.c"
int main () {
		
	int choix = 0 ;
	int n = 1 ;
	int somme = 0 ;
	
	printf("Bonjour\n");
	
	while ( (choix != 1 && choix != 2 && choix != 3 )||(scanf("%d",&choix) != 1) ) {
		printf("Que voulez vous faire?\n1)Afficher la table de multiplication d'un nombre\n2)Tester si un nombre est parfait ou non\n3)Quitter\n");
		scanf("%d",&choix);
	
		if ( choix == 1 ) {
		printf("Entrez n : ");
		scanf( "%d",&n);
		table (n) ;
		}
	
		if ( choix == 2 ) {
		int i = 1;
		printf("Entrez le nombre n :");
		scanf("%d",&n);
		parfait ( n , i , somme ) ;
		}
	
	
		if ( choix == 3 ) {
			printf("AU revoir\n");
			break;
		}

	}
	return 0 ;
}

	
	
	

