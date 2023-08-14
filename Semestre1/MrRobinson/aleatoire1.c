#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main () {

///	initialisation du générateur de nombre aléatoire
	srand(time(NULL));
	
///	affichage de RAND_MAX et du temps
	printf("\nRAND_MAX = %d \ttime = %ld\n",RAND_MAX, time(NULL) );

///	Generer 10 nombres pseudo-aléatoires < RAND_MAX
	for(int i=0 ; i<10 ; i++) {
		printf("%d\t" , rand());
	}	

///	Pour générer des nombres entre 0 et 1 
	printf("\nNombres entre 0 et 1\n");
	for(int i=0 ; i<10 ; i++) {
		printf("%f\t", (float)rand () / RAND_MAX);
	}	

///	Pour générer des nombres entre 0 et 100
	printf("\nNombres entre 0 et 100\n");
	for(int i=0 ; i<10 ; i++) {
		printf("%d\t", 100*rand () / (RAND_MAX));
	}	
	
///	Pour générer des nombres entre 1 et 100 : cf; Numerical Recipes
	printf("\nNombres entre 1 et 100\n");
	for(int i=0 ; i<10 ; i++) {
		printf("%d\t", 1+ (int) (100.0*rand() / (RAND_MAX + 1.0)));
	}	
	return 0;
}
