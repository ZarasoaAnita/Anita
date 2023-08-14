#include <stdio.h>

int main() {
	
	printf("demande à l'utilisateur de saisir 10 nombres entiers, puis affiche le plus grand nombre saisi.\n");
    int tableau[10];
    int max ;
    
    printf("Entrez 10 nombres entiers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &tableau[i]);
        if ( i==0 || tableau[i] > max) {
            max = tableau[i];
        }
    }
    
    printf("Le plus grand nombre est : %d\n", max);
    
    return 0;
}
