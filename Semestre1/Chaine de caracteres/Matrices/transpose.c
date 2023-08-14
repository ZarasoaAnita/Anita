#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nombre_de_ligne();
int nombre_de_colonnes();
int ** allocation2D(int ligne, int colonne);
void remplissage(int** matrice, int ligne, int colonne);
void affichage(int** matrice, int ligne, int colonne);
int** transposition(int** matrice,int ligne_initial,int colonne_initial);

int main(){
	int ligne_initial=0;
	int ligne_final=0;
	int colonne_initial=0;
	int colonne_final=0;
	int** matrice=NULL;
	int** transposee=NULL;
	
	
	ligne_initial=nombre_de_ligne();
	colonne_initial=nombre_de_colonnes();
	ligne_final=colonne_initial;
	colonne_final=ligne_initial;
	matrice=allocation2D(ligne_initial,colonne_initial);
	remplissage(matrice,ligne_initial,colonne_initial);
	affichage(matrice,ligne_initial,colonne_initial);
	
	transposee=transposition(matrice,ligne_initial,colonne_initial);
	affichage(transposee,ligne_final,colonne_final);
	
	
	
	return 0;
}
int nombre_de_ligne(){
	int lignes=0;
	printf("Entrez le nombre de ligne de la matrice: ");
	scanf("%d",&lignes);
	return lignes;
}
int nombre_de_colonnes(){
	int colonnes=0;
	printf("Entrez le nombre de colonne de la matrice: ");
	scanf("%d",&colonnes);
	return colonnes;
}
int ** allocation2D(int ligne, int colonne){
	int** mat=NULL;
	mat=malloc(ligne*sizeof(int *));
	for(int i=0; i<ligne; i++){
		mat[i]=malloc(colonne*sizeof(int));
	}
	return mat;
}
void remplissage(int** matrice, int ligne, int colonne){
	for(int i=0; i<ligne;i++){
		for(int j=0; j<colonne; j++){
			printf("Saisissez matrice[%d][%d]:\t",i,j);
			scanf("%d",&(matrice[i][j]));
		}
	}
}	
void affichage(int** matrice, int ligne, int colonne){
	for(int i=0; i<ligne;i++){
		for(int j=0; j<colonne; j++){
			printf("%d\t",matrice[i][j]);
		}
			printf("\n");
	}	
}
int** transposition(int** matrice,int ligne_initial,int colonne_initial){
	int ligne_final=0;
	int colonne_final=0;
	int** transposee=NULL;
	
	ligne_final=colonne_initial;
	colonne_final=ligne_initial;
	transposee=allocation2D(ligne_final,colonne_final);
	
	for(int i=0; i<ligne_final; i++){
			for(int j=0; j<colonne_final; j++){
				transposee[i][j]=matrice[j][i];
			}
		}
	
	return transposee;
}
	
	
