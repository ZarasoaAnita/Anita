#include <stdio.h>
#include <string.h>

int main () {
	printf("Ecrire un mot et l'ecrire à l'envers\n");

char mot [100] ;

		printf("Ecrire un mot: ");
		scanf("%s",mot);
		
	 int taille = strlen (mot);
	 
	 char mot_inverse [taille+1];
	 
	 for (int i=0 ; i<taille ; i++) {
		 mot_inverse[i] = mot [taille-1-i];
	}
	
	printf("Le mot inverse est %s \n",mot_inverse);
	
	
	return 0;
}
