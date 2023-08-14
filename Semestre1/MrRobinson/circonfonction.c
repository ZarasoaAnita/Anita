#include <stdio.h>
#define PI 3.14
float calculcirconf ( float rayon ) ;

int main () {
	printf("Calcul de la circonférence d'un cercle\n");
	float rayon = 1 ;
	float circonference = 1 ;
	
///Entrée de données 
	printf("Entrez le rayon du cercle :");
	scanf("%f",&rayon);

///Calcul
	circonference = calculcirconf( rayon ) ;

///Sortie de resultat
	printf("Pour rayon = %f\nLa circonférence est %f\n",rayon,circonference);
	
	return 0 ;
}
float calculcirconf ( float rayon ) {
	float circonference = 1 ;
	
	circonference = 2 * PI * rayon ; 
	
	return circonference ;
}
