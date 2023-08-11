#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef STRUCT1_H
#define STRUCT1_H
typedef struct {
	char marque[100];
	char etiquette[50];
	char MAC[50];
}Pc;
#endif

#ifndef STRUCT_H
#define STRUCT_H
typedef struct {
	char nom[50];
	char prenom[50];
	char telephone[20];
	char email[50];
	char adresse[50];
	char date_de_naissance[100];
	char lieu_de_naissance[100];
	char annee_du_bac[30];
	char genre[30];
	char CIN[10];
	char URL[5];
}Information;
#endif


FILE* info_complementaire_PC(int* nombre,Pc* computeur,char* filename);
char** allocation2D(int ligne,int colonne);
FILE* triage_PC(FILE* file,char* filename);
Pc* take (FILE* file,char* filename);
int countLines_PC(FILE* file,char* filename);
Pc* comparaison (Pc* answer,int ligne);
FILE* ajout_fichier_final (int ligne,Pc* answer);
FILE* info_Etudiant (int* nombre,Information etudiant[],char* nom);
FILE* triage_Etudiant(FILE* file, char* nom);
