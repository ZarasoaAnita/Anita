#include <stdio.h>
#include <stdlib.h>

int main () {
	long a = 9 ;
	long b = 42;
	int d=0;
	int e=0;
	
	a=1000;
	b=5000000;
	
	long somme = a + b;
	long produit = a * b;
	
	printf("la somme est %ld\n",somme);
	printf("Le produit est %ld\n",produit);
	
	d = sizeof(int);
	printf("La taille en octect d'un int est %d\n",d);
	
	e = sizeof(char);
	printf("La taille en octect d'un char est %d\n",e);
	return 0;
}
