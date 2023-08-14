#include <stdio.h>
#include <stdlib.h>

int main () {
/* 10 caractères + 0 de fin de chaîne */
char tab [11];

int i=0; /* compteur */

/* Remplissage du tableau avec les caractères */
	for (i=0; i<10; i++) {
	tab[i] = 65 + i; // ou tab[i]=’A’+i;
	}	
/* Ajout du 0 de fin de chaîne*/
	tab[10] = '\0';

/* Affichage de la chaîne*/
	printf("tab : %s\n",tab);

/* Saut d’une autre ligne */
	printf("\n");

/* Affichage de chacun des caractères */
	for (i=0; i<11; i++) {
		printf("Caractère numéro %d: %c\n",i,tab [i]);
	}
	
	return 0;
}
