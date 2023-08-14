#include <stdio.h>
#include <stdlib.h>

int entrerNombre();
int** allouer2D(int ligne, int col);
void entrerValTab2D(int **tab, int ligne, int col);
void afficherTab2D(int **tab, int ligne, int col);

int main() {
    int ligne = 0;
    int col = 0;
    int** tab = NULL;

    ligne = entrerNombre();
    col = entrerNombre();
    tab = allouer2D(ligne, col);
    entrerValTab2D(tab, ligne, col);
    afficherTab2D(tab, ligne, col);

    for (int i = 0; i < ligne; i++) {
        free(tab[i]);
    }
    free(tab);

    return 0;
}

int entrerNombre() {
    int taille = 0;
    printf("Entrez le nombre de ligne ou colonne du tableau : ");
    scanf("%d", &taille);
    return taille;
}

int** allouer2D(int ligne, int col) {
    int** tab = (int**)malloc(ligne * sizeof(int*));
    for (int i = 0; i < ligne; i++) {
        tab[i] = (int*)malloc(col * sizeof(int));
    }
    return tab;
}

void entrerValTab2D(int **tab, int ligne, int col) {
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            printf("tab[%d][%d] = ", i, j);
            scanf("%d", &tab[i][j]);
        }
        printf("\n");
    }
}

void afficherTab2D(int **tab, int ligne, int col) {
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", tab[i][j]);
        }
        printf("\n");
    }
}
