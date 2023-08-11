#include "information.h"
#include "information.c"

int main(){
	Pc* computeur=malloc(sizeof(Pc)*100);
	int nombre=0;///Pour savoir combien de PC , on veut ajouter
	
	FILE* file=NULL;
	FILE* new=NULL;
	
	file=info_complementaire_PC(&nombre,computeur,"pc.csv");
	new=triage_PC(file,"pc.csv");
	
	(void)new;
	free(computeur);

	return 0;
}
