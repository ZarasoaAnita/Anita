#include "information.h"
#include "information.c"


int main(){
	Information* etudiant = malloc(sizeof(Information)*100);
	char* nom = malloc(30);
	strcpy(nom,"info_Etudiant.csv");
	
	int nombre=0;///Pour savoir combien de nom , on veut ajouter
	
	FILE* file=NULL;
	FILE* new=NULL;

		file = info_Etudiant (&nombre,etudiant,nom);
		new=triage_Etudiant(file, nom);
		
	(void)new;
	free(etudiant);
	return 0;
}
