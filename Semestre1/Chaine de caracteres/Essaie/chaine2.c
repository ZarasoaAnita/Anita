#include <stdio.h>
#include <string.h>

int main () {
	printf("Affiche la chaine de caractere ABCDEFGHIJKLMNOPQRSTUVWXYZ\n\n\n\n");

int i=0;
int pos_tab=0;
char tab_alpha[27];

	for (i=65 ; i<=90;i++){
		tab_alpha[pos_tab]=i;
		pos_tab++;
	}

	tab_alpha[26]=0;
	printf("%s\n",tab_alpha);

	return 0;
}
