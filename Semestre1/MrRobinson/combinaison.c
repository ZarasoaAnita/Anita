#include <stdio.h>
#include <stdlib.h>
int** allocation(int a);
void construction_tab(int** tab, int a);

int main(){
	printf("Calcul de la combinaison de deux nombres\n");
	printf("Le nombre de haut doit etre superieur à celui du bas\n\n"); 
	int haut =0;
	int bas =0;
	int** pascal = NULL;
	
	printf("Saisissez le nombre du haut: ");
	scanf("%d",&haut);
	printf("Saisissez le nombre du bas: ");
	scanf("%d",&bas);
	
	pascal = allocation(haut);
	construction_tab(pascal,haut);
	
	printf("La combinaison de %d et %d est %d \n",haut,bas,pascal[haut][bas]);
	
	
	return 0;
}
int** allocation(int a){
	int ** array;
	
	array= malloc((a+1)* sizeof(int*));
	
	for(int i=0; i<a+1 ; i++){
		*(array+i)=malloc((a+1)*sizeof(int));
	}
	
	return array;
}

void construction_tab(int** tab, int a){
	for(int i=0; i<=a+1 ; i++){
			tab[i][0]= 1;
		}
		
	for(int i=1; i<=a ; i++){
		for(int j=1; j<i; j++){
			tab[i][j]= (tab[i-1][j-1]) + tab[i-1][j];
		}
	}

}
