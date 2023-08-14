#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	char **nom = NULL;
	char l[10];
	char c[10];
	int ligne=0;
	int col=0;
	
	printf("Combien de noms voulez-vous entrer? ---> ");
	fgets(l,5,stdin);
	sscanf(l,"%d",&ligne);
	
	printf("Combien de caracteres maximum dans les noms: ");
	fgets(c, 5,stdin);
	sscanf(c,"%d",&col);
	
	nom= (char**) malloc(sizeof(char*) *ligne);
	for(int i=0 ; i<ligne ; i++) {
		nom[i] = (char*) malloc(sizeof(char)*col);
	}
	
	for(int i=0 ; i<ligne ; i++) {
		printf("Entrez nom n°%d :",i+1);
		fgets(nom[i],col,stdin);
	}
	
	for(int i=0; i<ligne ; i++) {
		for(int j=i+1 ; j<ligne ; j++) {
			if(strcmp(nom[i],nom[j]) >0) { 
				char temp[col];
				strcpy(temp , nom[i]);
				strcpy(nom[i],nom[j]);
				strcpy(nom[j],temp);
			}
		}
	}
	
	printf("Voici les noms que vous avez entrés mais dans l'ordre:\n");
	for(int i=0 ; i<ligne ; i++) {
		printf("%s\n",nom[i]);
	}
	free(nom);
	return 0;
}
