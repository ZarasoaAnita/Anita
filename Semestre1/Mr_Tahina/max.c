#include <stdio.h>
#include <stdlib.h>
int entrerNombre();
int* allouer(int a);
void remplirTab(int* tab , int a);
void afficherTab(int* tab, int a);
void triTab (int* tab , int a);

int main() {
	int n=0;
	int *tab = NULL;
	
	printf("Veuille entrez la taille du tableau :");
	n = entrerNombre();
	tab = allouer(n);
	printf("Veuillez remplir le tableau\n");
	remplirTab(tab , n);
	printf("Voici les elements que vous avez entrer\n");
	afficherTab(tab ,n);
	triTab(tab , n);
	//printf("Voici le tableau apres tri\n");
	//afficherTab(tab ,n);
	printf("Vous voulez voir combien de max:");
	n = entrerNombre();
	printf("Voici les %d plus grands nombres: \n",n);
	afficherTab(tab ,n);
	
	return 0;
}

int entrerNombre() {
	int a=0;
	scanf("%d",&a);
return a;
}

int* allouer(int a) {
	int* tab= (int *) malloc (a*sizeof(int));
	return tab;
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

void triTab (int* tab , int a){
	for(int i=0 ; i<a ; i++){
		for(int j=i+1 ; j<a ; j++){
			if(tab[i]<tab[j]){
				int temp=0;
				temp=tab[i];
				tab[i]=tab[j];
				tab[j]=temp;
			}
		}
	}	
}

void triencore (int* tab , int a){
	
}
