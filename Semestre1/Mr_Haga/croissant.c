#include <stdio.h>
#include <stdlib.h>

int main () {
	int tableau [10] = {0} ;

	int i=0;
	
	for (i=0 ; i<10 ; i++) {
	printf("Entrez valeur n° %d: ",i+1);
	scanf("%d",&tableau[i]);
	}
	
	for (int i =0 ; i<10 ; i++){
		
		for(int j = i+1 ; j<10 ; j++){
			
			if(tableau[i]>tableau[j]) {
				int temporaire = tableau [i];
				tableau [i] = tableau [j];
				tableau [j] = temporaire ;
			}
		}
	}
	
	for (int i = 0 ; i < 10 ; i++){
		printf("%d  ", tableau[i]);
	}
	return 0;
}
