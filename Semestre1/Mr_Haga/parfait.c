#include <stdio.h>

void parfait ( int n , int i , int somme );

/*int main () {
	printf("Test si un nombre est parfait ou non\n");
	
	int n = 0 ,
	    i = 1 ,
	    somme = 0 ;

///Entrée de données	
while ( n >= 0 ) {
	printf("Entrez un nombre n:\n");
	scanf("%d",&n);

///Traitement et sortie de résultat	
	parfait ( n , i , somme );
	for ( i=1 , somme=0 ; i < n ; i++ ) {
		if( n%i == 0) {
			somme += i ;
		}
	}
	
	if (somme == n) {
		printf("Le nombre est parfait\n");
	}
	else {
		printf("Le nombre n'est pas parfait\n");
	}
}

	return 0;
}*/

void parfait ( int n , int i , int somme ) {
	for ( i=1 , somme=0 ; i < n ; i++ ) {
		if( n%i == 0) {
			somme += i ;
		}
	}
	
	if (somme == n) {
		printf("Le nombre est parfait\n");
	}
	else {
		printf("Le nombre n'est pas parfait\n");
	}
	
}
