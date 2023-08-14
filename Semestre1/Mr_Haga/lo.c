#include <stdio.h>

int main() {
    int n, i, j, space;

    printf("Entrez un nombre impaire: ");
    scanf("%d", &n);

    if(n % 2 == 0) {
        printf("Erreur: le nombre doit etre impaire.");
        return 0;
    }

    space = n/2 + 1;

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= space; j++) {
            printf(" ");
        }

        for(j = 1; j <= i; j++) {
            printf("*");
        }

        printf("\n");

        if(i < n/2 + 1) {
            space--;
        }
        else {
            space++;
        }
    }

    return 0;
}

