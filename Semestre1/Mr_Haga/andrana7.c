#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	printf("Triage de nom par ordre alphabetique\n");
	
	char **nom; 
	char **maj;
	
	int ligne = 0; 
	//int colonne = 10;
	char l[100];
	//char c[5];
	
	printf("Entrez le nombre de ligne :");
	//scanf("%d",&ligne);
	fgets(l,10,stdin);
	//ligne = atoi (l);
	sscanf(l, "%d", &ligne); //ce qu'il y a dans l va dans ligne
	
	//printf("Entrez le nombre de colonne :");
	//scanf("%d",&colonne);
	//fgets(c,5,stdin);
	//colonne = atoi (c);
	
	nom  = (char**)malloc(ligne * sizeof (char*) );
	for(int i=0 ; i<ligne; i++) {
		nom[i] = (char*)malloc(1000 * sizeof (char)); 
	}
	
	maj = (char**)malloc(ligne * sizeof (char*) );
	for(int i=0 ; i<ligne; i++) {
		maj[i] = (char*)malloc(100 * sizeof (char*));
	}
	
	
	for( int i=0 ; i<ligne ; i++ ) {
		printf("Entrez nom n°%d : ",i+1);
		fgets(nom[i] ,50, stdin);
		//scanf("%s",nom);
	}
	
	
	for(int i=0 ; i<ligne ; i++ ) {
		for(int j=i+1 ; j<ligne ; j++ ) {
			if(strcmp(nom[i] , nom[j])>0){
				char temp[5];
				strcpy(temp , nom[i]);
				strcpy(nom[i],nom[j]);
				strcpy(nom[j],temp);
			}
		}
	}
	
	for( int i=0 ; i<ligne ; i++ ) {
		printf("%s",nom[i]);
	}
	free(
	
	
	return 0;
}

