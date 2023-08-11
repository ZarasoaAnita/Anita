
#include "information.h"

///
FILE* info_complementaire_PC(int* nombre,Pc* computeur,char* filename){
	printf("Combien de PC voulez-vous ajouter a la liste? ");
	scanf("%d",nombre);
	FILE* fichier=NULL;
	fichier = fopen(filename,"a+");
	
	
	if(fichier==NULL){
		printf("Erreur d'ouverture du fichier\n");
		exit(1);
	}
	
	for(int i=0; i<*nombre; i++){
		printf("\n[%d] Saisissez la marque de votre PC : ",i+1);
		scanf("%s",computeur[i].marque);
	//	computeur[i].marque[strcspn(computeur[i].marque, "\n")] = '\0';
		fgetc(stdin);
		printf("Saisissez l'etiquette : ");
		scanf("%s",computeur[i].etiquette);
		fgetc(stdin);
		printf("Saisissez l'adresse MAC du PC : ");	
		scanf("%s",computeur[i].MAC);
	//	computeur[i].MAC[strcspn(computeur[i].MAC, "\n")] = '\0';
		fgetc(stdin);
		
		//~ fprintf(fichier,"%s\t%s\t%s\t\n",computeur[i].marque,computeur[i].etiquette,computeur[i].MAC);
		fprintf(fichier,"%s,%s,%s\n",computeur[i].marque,computeur[i].etiquette,computeur[i].MAC);
	}
	fclose(fichier);
	return fichier;
}
///
char** allocation2D(int ligne,int colonne){
	char **tab=NULL;
	tab=(char**)malloc(sizeof(char*)*ligne);
	for(int i=0;i<ligne;i++){
		*(tab+i)=(void*)calloc(colonne,sizeof(char)*colonne);
	}
	return tab;
}
///triage PC
FILE* triage_PC(FILE* file,char* filename){
	FILE* reponse;
	
	int ligne=0;
	Pc *answer = malloc(sizeof(Pc)*100);
	answer = take(file,filename);
	ligne = countLines_PC(file,filename);
	answer = comparaison(answer,ligne);
	reponse = ajout_fichier_final(ligne,answer);
	
	return reponse;
}
///Transferer les donnees du fichier dans la structure
Pc* take (FILE* file,char* filename){
	char** contenu = allocation2D(100,255);
	Pc *answer = malloc(sizeof(Pc)*100);
	file = fopen(filename,"r");
	
	for(int i=0;feof(file)!=1;i++){
		fgets(contenu[i],255,file);
		printf("%s",contenu[i]);
		sscanf(contenu[i],"%[^,\t]%*[,\t]%[^,\t]%[^\n]",answer[i].marque,answer[i].etiquette,answer[i].MAC);
		//sscanf(contenu[i],"%[^,\t]%*[,\t]%[^,\t]%*[,\t]%[^\n]",answer[i].marque,answer[i].etiquette,answer[i].MAC);
		//sscanf(contenu[i],"%[^,],%[^,],%[^\n]",answer[i].marque,answer[i].etiquette,answer[i].MAC);
	}
	
	fclose(file);
	return answer;
}
///
int countLines_PC(FILE* file,char* filename){
	int ligne=0;
	int i=0;
	char contenu[100][255];
	file = fopen(filename,"r");
	for( i=0;feof(file)!=1;i++){
		fgets(contenu[i],255,file);
		ligne=i;
	}
	fclose(file);
	return ligne;
}
///
Pc* comparaison (Pc* answer,int ligne){	
	for(int j=1;j<ligne-1;j++){
		for(int k=j+1;k<ligne;k++){
			if(strcmp(answer[j].etiquette,answer[k].etiquette)>0){
				Pc temp = answer[k];
				answer[k] = answer[j];
				answer[j] = temp;
			}
		}
		printf(" \nVoici etiquette: %s\n",answer[j].etiquette);
	}
	return answer;
}
///
/*FILE* ajout_fichier_final (int ligne,Pc* answer){
	FILE* new;
	new = fopen("PC_trier.csv","w");
	if(new==NULL){
		printf("Erreur lors de l'ouverture du fichier ");
		exit(1);
	}
	for(int j=0;j<ligne;j++){
		printf("\n%s\n",answer[j].etiquette);
		fprintf(new,"%s\t%s\t%s\n",answer[j].etiquette,answer[j].MAC,answer[j].marque);
	}
	fclose(new);
	return new;
}
*/
/*FILE* ajout_fichier_final(int ligne, Pc* answer) {
    FILE* new;
    new = fopen("PC_trier.csv", "w");
    if (new == NULL) {
        printf("Erreur lors de l'ouverture du fichier ");
        exit(1);
    }
    for (int j = 0; j < ligne; j++) {
        // Nettoyer les champs avant de les écrire dans le fichier
        char cleanedEtiquette[50];
        char cleanedMAC[50];
        char cleanedMarque[100];

        // Copier les champs nettoyés
        strcpy(cleanedEtiquette, answer[j].etiquette);
        strcpy(cleanedMAC, answer[j].MAC);
        strcpy(cleanedMarque, answer[j].marque);

        // Écrire les champs nettoyés dans le fichier avec des tabulations
        fprintf(new, "%s\t%s\t%s\n", cleanedEtiquette, cleanedMAC, cleanedMarque);
    }
    fclose(new);
    return new;
}
* */
FILE* ajout_fichier_final(int ligne, Pc* answer) {
    FILE* new;
    new = fopen("PC_trier.csv", "w");
    if (new == NULL) {
        printf("Erreur lors de l'ouverture du fichier ");
        exit(1);
    }
    for (int j = 0; j < ligne; j++) {
        // Nettoyer les champs avant de les écrire dans le fichier
        char cleanedEtiquette[50];
        char cleanedMAC[50];
        char cleanedMarque[100];

        // Copier les champs nettoyés
        strcpy(cleanedEtiquette, answer[j].etiquette);
        strcpy(cleanedMAC, answer[j].MAC);
        strcpy(cleanedMarque, answer[j].marque);

        // Écrire les champs nettoyés dans le fichier avec des tabulations
        fprintf(new, "%s\t%s\t%s\n", cleanedEtiquette, cleanedMAC, cleanedMarque);
    }
    fclose(new);
    return new;
}
///
FILE* info_Etudiant (int* nombre,Information etudiant[],char* nom){
		printf("Combien de nom voulez-vous ajouter a la liste?--->");
		scanf("%d",nombre);
		
		FILE* fichier=NULL;
		fichier=fopen(nom,"a+");
		
		if(fichier==NULL){
			printf("Erreur lors de l'ouverture du fichier\n");
			exit(1);
		}
		
		for(int i=0;i<*nombre;i++){
		printf("Saisissez votre nom: ");
		scanf("%s",etudiant[i].nom);
		fgetc(stdin);
		printf("Saisissez votre prenom: ");
		scanf("%[^\n]",etudiant[i].prenom);
		fgetc(stdin);
		printf("Saisissez votre numero de telephone: ");
		scanf("%[^\n]",etudiant[i].telephone);
		fgetc(stdin);
		printf("Saisissez votre adresse email: ");
		scanf("%[^\n]",etudiant[i].email);
		fgetc(stdin);
		printf("Saisissez votre date de naissance(JJ/MM/AA): ");
		scanf("%[^\n]",etudiant[i].date_de_naissance);
		fgetc(stdin);
		printf("Saisissez votre lieu de naissance(JJ/MM/AA): ");
		scanf("%[^\n]",etudiant[i].lieu_de_naissance);
		fgetc(stdin);		
		printf("Saisissez votre annee du bac: ");
		scanf("%[^\n]",etudiant[i].annee_du_bac);
		fgetc(stdin);
		printf("Saisissez votre genre(H ou F): ");
		scanf("%[^\n]",etudiant[i].genre);
		fgetc(stdin);
		printf("Saisissez votre numero de CIN: ");
		scanf("%[^\n]",etudiant[i].CIN);
		fgetc(stdin);
		printf("Saisissez votre URL: ");
		scanf("%[^\n]",etudiant[i].URL);
		fgetc(stdin);
		//fputs("Nom\tPrenom\tTel\tEmail\tAdresse\tDate de naissance\tLieu de naissance\tBacc\tGenre\tCIN\tUrl gitHub",file);
		//~ fprintf(fichier,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",etudiant[i].nom,etudiant[i].prenom,etudiant[i].telephone,etudiant[i].email,etudiant[i].date_de_naissance,etudiant[i].lieu_de_naissance,etudiant[i].annee_du_bac,etudiant[i].genre,etudiant[i].CIN,etudiant[i].URL);
		fprintf(fichier,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",etudiant[i].nom,etudiant[i].prenom,etudiant[i].telephone,etudiant[i].email,etudiant[i].date_de_naissance,etudiant[i].lieu_de_naissance,etudiant[i].annee_du_bac,etudiant[i].genre,etudiant[i].CIN,etudiant[i].URL);
	}
	fclose(fichier);
	return fichier;
}
FILE* triage_Etudiant(FILE* file, char* nom){
	
	file=fopen(nom,"r");
	
	char contenu[255][255];
	
	if(file==NULL){
		printf("Erreur d'ouverture du fichier\n");
		exit(1);
	}
	
	int j=0;
	
	for(int i=0; feof(file)!=1; i++){
		fgets(contenu[i],255,file);		
		printf("%s\n",contenu[i]);
		j++;
	}
	char tmp[255];
	
	for(int i=1; i<j; i++){
		for(int k=i+1; k<j; k++){
			if(strcmp(contenu[i],contenu[k])>0){
				strcpy(tmp,contenu[i]);
				strcpy(contenu[i],contenu[k]);
				strcpy(contenu[k],tmp);
			}
		}
	}
	
	for(int i=1; i<j; i++){
		printf("%s\n",contenu[i]);
	}
	
	fclose(file);
	
	FILE* new=fopen("etudiant_trier.csv","w");

	if(new==NULL){
		printf("Erreur d'ouverture du fichier\n");
		exit(1);
	}
	
	//~ fprintf(new,"Nom\tPrenom\tTel\tEmail\tAdresse\tDate de naissance\tLieu de naissance\tBacc\tGenre\tCIN\tUrl gitHub");
	//	fprintf(new,"Nom,Prenom,Tel,Email,Adresse,Date de naissance,Lieu de naissance,Bacc,Genre,CIN,Url gitHub");
	
	for(int i=0; i<j; i++){
		fprintf(new,"%s",contenu[i]);
	}
	
	fclose(new);
	return new;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


