#include <stdio.h>
void affiche ( int i , int tab[i] );
void complete (int i , int tab[i] );
int main () {
	int tab[10] = {0};
	int i = 0;
	
	complete (i , tab);
	affiche (i , tab);

	return 0;
}
void complete ( int i , int tab[i] ) {
	for ( i=0 ; i< 10 ; i++ ) {
	printf("Entrez la valeur n°%d :",i+1);
	scanf("%d",tab);
	}
}
void affiche ( int i , int tab[i] ) {
	for ( i = 0 ; i<10 ; i++ ) {
	printf("n[%d]= %d ",i,tab[i]);
	}
}
