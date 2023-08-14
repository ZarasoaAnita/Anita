/********************************************************************
---------------------------------------------------------------------
	Auteur	:	JUSTIN Zarasoa Anita
	Mention	:	MIT
	Niveau	:	L1
	Numero	:	12
	Objectif:	Programme de devinette
-------------------------------------------------------------------
*******************************************************************/


#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main () {
	int nombre_a_devine = 0;
	int nombre_saisi = 0;
	int nombreCoups = 0;
	int reste = 0;
	
	printf("Vous allez deviner un nombre entre 1 et 100 en 7 coups maximum\n");
	
	srand(time(NULL));
	
	nombre_a_devine= 1+ (int) (100.0*rand() / (RAND_MAX + 1.0));

	while(nombre_saisi != nombre_a_devine ) {
	
		printf("\nEntrez un nombre entre 0 et 100\n");
		scanf("%d",&nombre_saisi);
		nombreCoups ++ ;
		reste = 7-nombreCoups;
		
		if(reste == 0 ) {
			printf("Desole , vous n'avez pas trouve le nombre en 7 coups\n");
			break;
		}
		
		if( nombre_saisi < nombre_a_devine ) {
			printf("Le nombre est plus grand\n");
			printf("%d coups restants\n",reste);
		}
		
		else if( nombre_saisi > nombre_a_devine ) {
			printf("Le nombre est plus petit\n");
			printf("%d coups restants\n",reste);
		}
		
		else if( nombre_saisi == nombre_a_devine ) {
			 printf("C'est le nombre\nFelicitation vous l'avez trouvez en %d coups\n",nombreCoups);
		}
	
	
	}
	
	
	return 0;
}
/*******************************************************************************
							FIN DU PROGRAMME
*******************************************************************************/
