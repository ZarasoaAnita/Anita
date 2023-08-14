#include <stdio.h>
#define TAILLE_TABLEAU 5 //TAILLE_TABLEAU est un variable constant 

int main () {
	/*int tableau [5] = {0};
	int i;
	
	for(i=0 ; i<5 ; i++) {
		printf("[%d]",tableau [i]);
	}*/
	
	int tableau [TAILLE_TABLEAU] = {0};
	int i;
	
	for(i=0 ; i< TAILLE_TABLEAU; i++) {
		printf("[%d]",tableau [i]);
	}
		
	return 0;
}
