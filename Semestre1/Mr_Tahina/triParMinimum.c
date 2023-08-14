#include <stdio.h>
#include <stdlib.h>
void tri_par_minimum(int* tab , int n);
void remplirTab(int* tab , int a);
void afficherTab(int* tab, int a);
void tri_par_permutation_adjacente(int* tab , int n);

int main(){
	int *tab = NULL;
	int n=1;
	
	tab = malloc(n*sizeof(int));
	
	printf("Saisissez la taille du tableau: ");
	scanf("%d",&n);
	
	remplirTab(tab,n);
	afficherTab(tab,n);
	//tri_par_minimum(tab,n);
	tri_par_permutation_adjacente(tab,n);
	afficherTab(tab,n);
	
	free(tab);
	
	return 0;
}
void tri_par_minimum(int* tab , int n){
	int position_minimum=0;
		for(int i=0 ; i<n-1 ; i++){
			position_minimum = i;
			for(int j=i+1 ; j<n ; j++){
				if(tab[j]<tab[position_minimum]){
					position_minimum=j;
				}
			}
				if (position_minimum != i){
					int temp=tab[i];
					tab[i]=tab[position_minimum];
					tab[position_minimum]=temp;
				}
		}
}
void tri_par_permutation_adjacente(int* tab , int n){
	int permutation_effectue;
	
	do{
		permutation_effectue=0;
		for(int i=0 ; i<n-1 ; i++){
			if(tab[i]>tab[i+1]){
				int temp= tab[i];
				tab[i]=tab[i+1];
				tab[i+1]=temp;
				
				permutation_effectue=1;
			}
		}
	}while(permutation_effectue);
}
	
void remplirTab(int* tab , int a) {
	int i=0;
	for(i=0 ; i<a ; i++){
		printf("Saisissez la valeur n°%d: ",i+1);
		scanf("%d",tab+i);
	}
}
void afficherTab(int* tab, int a){
	int i=0;
	for(i=0 ; i<a ; i++) {
		printf("%d\n",tab[i]);
	}
}
