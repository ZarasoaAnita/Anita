#include <stdio.h>
#include <stdlib.h>
void entree_tab ( int dim , int tab[]) ;
void affiche_tab (int dim , int *tab) ;
void tri_tab (int dim , int tab []);

int main() {
	printf("Saisie de 5nombres et voir qui est le plus grand et le plus petit\n");
	int dim = 5;
	int tab[5] = {0};
	
	entree_tab (dim , tab);
	
	printf("\n");
	
	affiche_tab (dim , tab);
	
	tri_tab (dim , tab);
	
	printf("\n");
	
	printf("Le plus grand nombre est %d\n",tab[0]);
	
	printf("Le plus petit nombre est %d\n",tab[4]);
	
	
	return 0;
}

void entree_tab ( int dim , int *tab) {
	for(int i=0 ; i<dim ; i++) {
		printf("Entrez la valeur n° %d :" ,i+1);
		scanf("%d",tab+i);
	}
}

void affiche_tab (int dim , int *tab) {
	for(int i=0 ; i<dim ; i++) {
		printf(" tab[%d] = %d\n",i,tab[i]);
	}
}

void tri_tab (int dim , int tab []) {
	for(int i=0 ; i<dim ; i++) {
		
		for(int j=i+1 ; j<dim ; j++) {
			
			if (tab[i]  < tab [j]) {
				int temp = 0;
				
				temp = tab [i];
				tab [i] = tab [j] ;
				tab [j] = temp ;
			}
		}
	}
}

