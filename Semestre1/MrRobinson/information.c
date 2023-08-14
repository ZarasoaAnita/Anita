#include <stdio.h>

int main () {
		printf ("Demande d'information\n");
		
		char nom [20]; //le nom
		char prenom [30]; //les prénoms
		int age = 0 ; //l'age
		char adresse [40];//l'adresse
		
		printf ("Quel est votre nom?\n");
		scanf("%s",nom);
		
		printf ("Quel est votre prenom?\n");
		scanf("%s",prenom);
		
		printf("Quel age avez-vous?\n");
		scanf("%d",&age);
		
		printf(" Quelle est vous adresse?\n");
		scanf("%s",adresse);
		
		printf("Vous etes %s %s , vous avez %d ans et vous habitez à %s",nom,prenom,age,adresse);
	
		return 0 ;
}
