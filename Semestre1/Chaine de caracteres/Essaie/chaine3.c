#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compte(char* chaine);

/*int main(int argc, char *argv[])
{
	char* mot="Bonjour";
	
	printf("%ld\n",strlen(mot));
	
	int nombre_de_caractere=0;
	//int caractere=0;
	
	nombre_de_caractere=compte(mot);
	printf("%d\n",nombre_de_caractere);

	return 0;
}
* */
int main(int argc, char *argv[])
{
/* On crée 2 chaînes. chaine1 doit être assez grande pour
accueillir
le contenu de chaine2 en plus, sinon risque de plantage */
char chaine1[100] = "Salut", chaine2[] = " Mateo21";
strcat(chaine1, chaine2); // On concatène chaine2 dans chaine1
// Si tout s'est bien passé, chaine1 vaut "Salut Mateo21"
printf("chaine1 vaut : %s\n", chaine1);
// chaine2 n'a pas changé :
printf("chaine2 vaut toujours : %s\n", chaine2);
}
int compte(char* chaine){
	int nombre_de_caractere=0;
	int caractere=0;
	
	while(chaine[caractere]!='\0'){
		nombre_de_caractere++;
		caractere++;
	}
	return nombre_de_caractere;
}
