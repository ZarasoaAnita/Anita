#include <stdio.h>
void table(int n );

/*int main (){
	printf("Affichage de la table de multiplication d'un nombre \n");
	int n = 1 ;
	
	Entrée de donnée
	printf("Entrez n : ");
	scanf( "%d",&n);

	Traitement et sortie de résultat
	table (n) ;
	for ( i=1  ;i >= 1 && i <= 10 ; i++ ) {		
			printf(" %d * %d = %d\n",n,i,n*i);
	}
	
	return 0 ;
}*/

void table ( int n ) {
	int i = 1 ;
	for ( i=1  ;i <= 10 ; i++ ) {		
			printf(" %d * %d = %d\n",n,i,n*i);
	}
}	
