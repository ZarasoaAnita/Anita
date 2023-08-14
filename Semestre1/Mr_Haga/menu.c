#include <stdio.h>
void table ( int n ) ;
void parfait ( int n , int i , int somme ) ;

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
			printf("A bientot\n");
			break;
		}

	}
	return 0 ;
}

void table ( int n ) {
	int j = 1 ;
	for ( j=1  ;j >= 1 && j <= 10 ; j++ ) {		
			printf(" %d * %d = %d\n",n,j,n*j);
	}
}	
void parfait ( int n , int i , int somme ) {
		somme = 0 ;
			
	for ( i = 1 , somme = 0 ; i < n ; i++ ) {
		
		if ( n % i == 0 ) {
			somme += i ;
		}
	}
	
	if ( somme == n ) {
		printf("Le nombre est parfait\n");
	}
	
	else {
		printf("Le nombre n'est pas parfait\n");
	}
}
