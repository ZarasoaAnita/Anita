#include <stdio.h>
#include <string.h>

int main () {
	char texte[20]= "Hello World!";
	printf("Longueur du texte = %ld\n", strlen(texte));
	for(int i=0; i<=strlen(texte) ;i++) {
		printf("%c\t", texte[i]);
	}
	
	printf("\nCodes ASCII: \n");
	for(int i=0; i<=strlen(texte); i++){
		printf("%d\t", texte[i]);
	}
			
	printf("\nLe texte a l'envers:\n");
	for(int i=strlen(texte); i>=0 ; i--) 
		printf("%c",texte[i]);
	
	
	return 0;
}
