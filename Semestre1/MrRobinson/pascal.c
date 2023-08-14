#include <stdio.h>
#include <stdlib.h>
int** allouerTab (int a);
void construction_tab(int** tab, int a);

int main(){
	printf("Triangle de Pascal\n");
	int** tab= NULL;
	int n=0;
	
	printf("Entrez la taille du tableau: ");
	scanf("%d",&n);
	
	tab = allouerTab(n+1);
	construction_tab(tab,n+1);
	
	for(int i=1; i<=n+1; i++){
		for(int j=0; j<i ; j++){
			printf("%d\t",tab[i][j]);
		}
		printf("\n");
	}
	
	free(tab);
	
	return 0;
}
int** allouerTab (int a){
	int** tableau ;
		tableau= malloc(a * sizeof(int*));
		for(int i=0; i<=a; i++){
			tableau[i]=malloc(a*sizeof(int));
		} 
	return tableau;
}

void construction_tab(int** tab, int a){
	for(int i=0; i<=a ; i++){
			tab[i][0]= 1;
		}
	*(*(tab+i)+j)=0;
	for(int i=1; i<=a ; i++){
		for(int j=1; j<i; j++){
			tab[i][j]= (tab[i-1][j-1]) + tab[i-1][j];
		}
	}

}
