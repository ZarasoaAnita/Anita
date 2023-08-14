#include <stdio.h>
#include <stdlib.h>
int facto(int n);

int main(){
	printf("Calcul de la factoriel d'un entier\n");
	
	/*unsigned*/ int n = 1;
	/*unsigned */int factorielle = 1;
	
	printf("Saisissez le nombre dont on ve savoir le factoriel:  ");
	scanf("%d",&n);
	
	factorielle = facto(n);
	
	printf("%d! = %d\n",n,factorielle);
	
	return 0;
}
int facto(int n){
	
	if(n==2){return 2;}
	
	return n * facto(n-1);
	
}
