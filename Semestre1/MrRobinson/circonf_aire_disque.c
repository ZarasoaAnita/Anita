#include <stdio.h>
#include <math.h>
#define PI 3.14
void calcul ( float rayon , float *circonference , float *aire);

int main () {
	printf("Calcul de la circonférence et de l'aire d'un disque\n");
	
	float rayon = 1 ,
		  circonference = 1 ,
		  aire = 1 ;
		  
///Entree des données
	printf("Entrez le rayon r : ");
	scanf("%f",&rayon);
	
///Calcul
	calcul ( rayon , &circonference , &aire);


///Sortie des résultats
	printf("Pour rayon =%f \nLa circonférence =%f\nL'aire du disque =%f\n",rayon,circonference,aire);
	
	return 0 ;
}
void calcul ( float rayon , float *circonference , float *aire) {
	
	*circonference = 2 * PI * rayon ;
	*aire = PI * rayon * rayon ;
}
