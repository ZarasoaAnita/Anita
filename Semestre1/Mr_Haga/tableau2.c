#include <stdio.h>
#define TAILLE_TABLEAU 5 
void afficher_tableau ( int tab[], int taille_du_tableau);

int main () {
	int tab [TAILLE_TABLEAU] = {16,84,-2,88,3};
		
	afficher_tableau( tab , TAILLE_TABLEAU);
	
	printf("\n\n");
		
	tab [2] = 1000;
	
	afficher_tableau( tab , TAILLE_TABLEAU); //plus besoin de faire &tab car le tableau est déjà une adresse
		
	return 0;
}
void afficher_tableau ( int tab[], int taille_du_tableau) {
	int i = 0;
	
	for(i=0 ; i< taille_du_tableau ; i++) {
		printf("[%d]", tab [i]);
	}
	
	}
