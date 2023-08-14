#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int nombre_de_ligne();
int nombre_de_colonnes();
int ** allocation2D(int ligne, int colonne);
void remplissage(int** matrice, int ligne, int colonne);
void affichage(int** matrice, int ligne, int colonne);
int matrice_ordre2(int** matrice,int ligne,int colonne);
int** allocation2D_det_3(int ligne,int colonne);
void remplissage_det3_Sarrus(int** matrice, int** tab_determinant);
int matrice_ordre3_Sarrus(int** matrice,int ligne,int colonne);
int reponse_Sarrus(int** tab_determinant, int ligne, int colonne);

int main(){
	int ligne=0;
	int colonne=0;
	int reponse=0;
	ligne=nombre_de_ligne();
	colonne=nombre_de_colonnes();
	
	int** matrice=NULL;
	matrice=allocation2D(ligne,colonne);
	remplissage(matrice,ligne,colonne);
	affichage(matrice,ligne,colonne);
	
	if(ligne==2&&colonne==2){
		reponse=matrice_ordre2(matrice,ligne,colonne);
		printf("le determinant est egal à %d\n",reponse);
	}
	
	if(ligne==3 && colonne==3){
		reponse=matrice_ordre3_Sarrus(matrice,ligne,colonne);
		printf("le determinant est egal à %d\n",reponse);
	}
	
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
			printf("%d ",matrice[i][j]);
		}
			printf("\n");
	}
	
	
}
int matrice_ordre2(int** matrice,int ligne,int colonne){
	int reponse=0;
		reponse= ((matrice[0][0])*(matrice[1][1]))-((matrice[0][1])*(matrice[1][0]));
		return reponse;
}
int matrice_ordre3_Sarrus(int** matrice,int ligne,int colonne){
	int reponse=0;
	int** tab_determinant=NULL;
	tab_determinant=allocation2D_det_3(ligne,colonne);
	remplissage_det3_Sarrus(matrice,tab_determinant);
	reponse=reponse_Sarrus(tab_determinant,ligne,colonne);
	
	return reponse;
}	
int** allocation2D_det_3(int ligne,int colonne){
	int** tab_determinant=NULL;
	int cols=colonne+2;
	tab_determinant=malloc(ligne*sizeof(int *));
	for(int i=0; i<ligne; i++){
			tab_determinant[i]=malloc(cols*sizeof(int));
		}
	return tab_determinant;
}
void remplissage_det3_Sarrus(int** matrice, int** tab_determinant){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			tab_determinant[i][j]=matrice[i][j];
		}
	}
	
	for(int i=0; i<3; i++){
		for(int j=3, k=0; j<5; j++){
			tab_determinant[i][j]=matrice[i][k];
			k++;
		}
	}
	
	for(int i=0; i<3; i++){
		for(int j=0; j<5; j++){
			printf("%d ",tab_determinant[i][j]);
		}
			printf("\n");
	}
}
int reponse_Sarrus(int** tab_determinant, int ligne, int colonne){
	int superieur=0;
	int inferieur=0;
	int reponse=0;
	
	for(int i=0; i<ligne; i++){
			superieur += ((tab_determinant[0][0+i])*(tab_determinant[1][1+i])*(tab_determinant[2][2+i]));
		}
		
	for(int i=0; i<ligne; i++){
			inferieur += ((tab_determinant[2][0+i])*(tab_determinant[1][1+i])*(tab_determinant[0][2+i])); 
		}
	reponse=superieur-inferieur;
	return reponse;
}
	
