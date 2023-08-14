#include <stdio.h>
#include <stdlib.h>
int** allouer2D(int a);

int main(){
	printf("Realiser le triangle de Pascal\n\n");
	int n=0;
	int** tab = 0;
	
	
	printf("Saisissez la puissance que vous voulez:	");
	scanf("%d",&n);
	
	tab=allouer2D(n+1);
	
	for(int i=0; i<n+1 ; i++){
		tab[i][0]=1;
	}
	
	for(int i=1 ; i<n+1 ; i++){
		for(int j=1 ; j<=i ; j++){
			tab[i][j] =(tab[i-1][j-1]) + (tab[i-1][j]);
		}
	}
	
	for(int i=0 ; i<n+1; i++){
		for(int j=0 ; j<=i ; j++){
			printf("%d\t",tab[i][j]);
		}
		printf("\n");
	}
		
	
	free(tab);
	return 0;
}

int** allouer2D(int a){
	
	int** tableau = malloc( a *sizeof(int *));
	
		for(int i=0 ; i<a ;i++){
			tableau[i] = malloc(a * sizeof(int));
		}
	
	return tableau;
}
