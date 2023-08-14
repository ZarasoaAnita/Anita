#include <stdio.h>
#include <stdlib.h>
int getData ();
int sumOdd (int n);
void displayResult(int n , int somme);

int main() {
	printf("Calcul de la somme des n premiers entiers impairs\n");
	
	int n=1;
	int somme=0;

while (n!=0) {
	n=getData() ;
	somme= sumOdd(n);
	displayResult(n,somme);
}
	

	return 0;
}
int getData () {
	int n;
	printf("Entrez n:" );
	scanf("%d",&n);
	return n;
}

int sumOdd (int n) {
	int somme=0;
	int i=0;
	for( i=1, somme=0 ; i<=(2*n-1) ; i+=2){
		somme += i;
	}
	return somme;
}

void displayResult(int n , int somme){
	printf("La somme des %d premiers entiers impairs est egal à %d\n",n,somme);
}
