#include <stdio.h>
#define PI 3.14

int main () {
	
	printf ("Calcul de la circonférence d'un cercle\n");
	
	float rayon = 1 ; //le rayon du cercle
	float circonf = 0 ; //le circonférence du cercle
	
///Entrée de données
	printf("Entrez le rayon du cercle :");
	scanf("%f",&rayon);
	
///traitement
	circonf = 2 * PI * rayon ;
	
///Sortie de résultat
	printf ("Pour un rayon de %0.2f , la circonférence est égal à %0.2f\n",rayon,circonf);
		
	return 0 ;
}
