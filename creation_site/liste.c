#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** allocation2D (int ligne , int colonne);
void available(char** tab_1 , FILE* file_1 , int* nombre);
void enable(char** tab_2 , FILE* file_2 , int* nombre);
void activation (char* name);
void desactivation(char* name);
void comparaison(char** tab_1, char** tab_2, int* n1, int* n2, char** inactif, int* k);
void affichage_tableau(char** tab_1, char** tab_2, int* n1, int* n2);
char* separer_point(char*name);
void redirectToPage();

int main(){
	printf("Cache-Control: no-cache, no-store, must-revalidate\n");
	printf("Pragma: no-cache\n");
	printf("Expires: 0\n"); 
	printf("Content-Type:text/html\n\n");
	
	printf("<html>\n");
	printf("<head>\n");
	printf("<meta charset=\"UTF-8\">");
	printf("<title>Sites actifs et inactifs</title>\n");
	printf("<style>\n");
	printf("body{ background-color: rgb(95, 11, 57);}\n");
	printf("table{width:75vw;background-color:rgb(241, 202, 232);}");
	printf("h2{color:white; font-size: 2rem;padding: 10px;}");
	printf("table,tr,td,th{ padding:30px;border-collapse:collapse;border:5px solid rgb(151, 74, 117);}");
	printf("th{font-size: 2rem;width:25vh;color:rgb(223, 13, 111);font-variant: small-caps;}");
	printf("td,tr{text-align: center;}");
	printf("td{font-size: 1.5rem;}");
	printf("a{color:rgb(30, 140, 184);}");
	printf("p{width:75vw; color:white;}");
	printf("</style>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<center>\n");
	

	
	printf("<h2>Liste des sites disponibles </h2>\n"); 
	printf("<table>\n");
	printf("<thead>\n");
	printf("<tr>\n");
	printf("<th>Sites</th>\n");
	printf("<th>Statues</th>\n");
	printf("<th>Action &agrave effectuer</th>\n");
	printf("</tr>\n");
	printf("</thead>\n");
	printf("<tbody>\n");
	
	char** tab_1=NULL;
	char** tab_2=NULL;
	char** inactif=NULL;

	tab_1=allocation2D(100,100);//là ou il y a les sites-available
	tab_2=allocation2D(100,100);//là ou il y a les sites-enable
	inactif=allocation2D(100,100);//là ou il y a les sites inactifs
	
	int n1=0; //nombre de sites available
	int n2=0; //nombre de sites enabled
	int n3=0; //nombre de sites inactifs
	
	FILE* file_1=NULL;
	available(tab_1,file_1,&n1);
	
	FILE* file_2=NULL;
	enable(tab_2,file_2,&n2);
	
	char* take=NULL;
	take=getenv("QUERY_STRING");
	if(take == NULL){
		printf("Leo be za\n");
	}
	if(take !=NULL ){
	printf("take = %s\n<br>",take);
	}
	
	if(take != NULL){
		printf("take = %s\n<br>",take);
		char* nom=malloc(50);
		char* action=malloc(50);
		printf("take = %s\n<br>",take);
		sscanf(take,"%[^=]=%[^&]&",nom,action);
		printf("take = %s\n<br>",take);
		printf("salut %s<br>\n",nom);
		printf("hey %s<br>\n",action);
		
		if(strstr(action,"yes")){
			activation(nom);
			popen("sudo systemctl reload apache2","w");
			//redirectToPage();				 
		}
		
		else if(strstr(action,"not")){
			desactivation(nom);
			popen("sudo systemctl reload apache2","w");
			//redirectToPage();				 
		}
		
		free(nom); free(action);
	}
	comparaison(tab_1,tab_2,&n1,&n2,inactif,&n3);
	affichage_tableau(tab_1,tab_2,&n1,&n2);
	
	printf("</tbody>\n");
	printf("</table>\n");
	printf("<p>* : aucune action n'est permise car appartient &agrave l'administrateur</p>\n");
	printf("</center>\n");
	printf("</body>\n");
	printf("</html>\n");
	
	free(tab_1); free(tab_2); free(inactif);
	
	return 0;
}
char** allocation2D (int ligne , int colonne){
    char** array=NULL;

    array=malloc(ligne*sizeof(char*));

    for(int i=0 ; i<ligne ; i++){
       *(array+i)=malloc(colonne);
        }

    return array;
}
void available(char** tab_1 , FILE* file_1 , int* nombre){
	file_1=popen("ls /etc/apache2/sites-available","r");
	char ligne[255];
	int i=0;
	*nombre=0;
	while (fgets(ligne, sizeof(ligne), file_1) != NULL){
		sscanf(ligne,"%s",tab_1[i]);
		//printf("%s\n",tab_1[i]);
		i++;
		*nombre +=1 ;
	}
	//printf("Il y a %d sites availables\n\n",*nombre);
	pclose(file_1);
}
void enable(char** tab_2 , FILE* file_2 , int* nombre){
	file_2=popen("ls /etc/apache2/sites-enabled","r");
	char ligne[255];
	int i=0;
	while (fgets(ligne, sizeof(ligne), file_2) != NULL){
		sscanf(ligne,"%s",tab_2[i]);
		//printf("%s\n",tab_2[i]);
		i++;
		*nombre +=1 ;
	}
	//printf("Il y a %d sites enables\n\n",*nombre);
	pclose(file_2);
}

void activation (char* name){
    char* cmd=malloc(100);
    sprintf(cmd,"sudo a2ensite %s",name);
    popen(cmd,"w");
}

void desactivation(char* name){
    char* cmd = malloc(100);
     sprintf(cmd,"sudo a2dissite %s",name);
     popen(cmd,"w");
}
/*
void activation(char* name) {
    char* cmd = malloc(100);
    if (cmd == NULL) {
        perror("Erreur lors de l'allocation de la mémoire pour cmd");
        // Gestion de l'erreur ici
        return;
    }

    sprintf(cmd, "sudo a2ensite %s 2> erreur.log", name);

    FILE *fp = popen(cmd, "w");
    if (fp == NULL) {
        perror("Erreur lors de l'exécution de popen");
        // Gestion de l'erreur ici
    }

    free(cmd);
}
*/
/*
void activation(char* name) {
    char* cmd = malloc(100);
    if (cmd == NULL) {
        perror("Erreur lors de l'allocation de la mémoire pour cmd");
        return;
    }

    sprintf(cmd, "echo 01092004 | sudo -S a2ensite %s 2> erreur.log", name);

    FILE *fp = popen(cmd, "w");
    if (fp == NULL) {
        perror("Erreur lors de l'exécution de popen");
    } else {
        pclose(fp);
    }

    free(cmd);
}
void desactivation(char* name) {
    char* cmd = malloc(100);
    if (cmd == NULL) {
        perror("Erreur lors de l'allocation de la mémoire pour cmd");
        // Gestion de l'erreur ici
        return;
    }

    sprintf(cmd, "sudo a2dissite %s 2> erreur.log", name);

    FILE *fp = popen(cmd, "w");
    if (fp == NULL) {
        perror("Erreur lors de l'exécution de popen");
        // Gestion de l'erreur ici
    }

    free(cmd);
}
*/

///Fonction qui va mettre dans le tableau inactif la liste des sites inactifs
void comparaison(char** tab_1, char** tab_2, int* n1, int* n2, char** inactif, int* k){
	  *k = 0; //nombre de sites inactifs
	
	 for (int i = 0; i < *n1; i++) {
        int siteActif = 0;//on suppose que tous les sites sont inactifs 

        for (int j = 0; j < *n2; j++) {
   
            if (strstr(tab_1[i], tab_2[j])) {
                siteActif = 1;
                break;
            }
        
        }

		if(siteActif == 0){
            // Allouer de la mémoire pour le nom du site inactif
            inactif[*k] = malloc(strlen(tab_1[i]) + 1);

            // Copie du nom du site inactif dans le tableau OK
            strcpy(inactif[*k], tab_1[i]);
            *k += 1;
        }
    }
}
void affichage_tableau(char** tab_1, char** tab_2, int* n1, int* n2){
	char statues[100];
	char name[100];
	
	for(int i=0; i< *n1; i++){
		printf("<tr><td>%s</td>",tab_1[i]);
		 int siteActif = 0;//on suppose que tous les sites sont inactifs 
		
		for(int j=0; j< *n2; j++){
			 if (strstr(tab_1[i], tab_2[j])) {
                siteActif = 1;
                break;
            }
		}
	
		
		if(siteActif == 0){
			strcpy(statues,"inactif");
			printf("<td>%s</td>",statues);
			
			if(strstr(tab_1[i],"default-ssl.conf") == NULL){
			strcpy(name,separer_point(tab_1[i]));
			printf("<td><a href=\"http://www.anita.com/cgi-bin/creation_site/liste.cgi?%s=yes\">ACTIVER</a></td></tr>\n",name);					 
			}
			
			else{
				printf("<td>*</td></tr>\n");
			}	
			
		}
		
		else if(siteActif == 1){
			strcpy(statues,"actif");
			printf("<td>%s</td>",statues);
			
			if(strstr(tab_1[i],"000-default.conf") == NULL && strstr(tab_1[i],"anita.conf") == NULL){
			strcpy(name,separer_point(tab_1[i]));
			 printf("<td><a href=\"http://www.anita.com/cgi-bin/creation_site/liste.cgi?%s=not\">DESACTIVER</a></td></tr>\n",name);	
			}
			
			else{
				printf("<td>*</td></tr>\n");
			}
			
		}
	}
}
char* separer_point(char*name){
	
	int point=0;
	char* conf=malloc(100);
	
	for(int i=0;i<strlen(name);i++){
		if(name[i]=='.'){
			point=i;
		}
	}
	
	for(int i=0;i<point;i++){
		conf[i]=name[i];
	}
	
	return conf;
	free(conf);
}		
void redirectToPage() {
    // En-tête de rafraîchissement
     printf("<meta http-equiv='refresh' content='1;url=http://www.anita.com/cgi-bin/creation_site/liste.cgi'>");

    // Corps de la réponse HTML
    printf("<p>Vous allez être redirigé vers une autre page dans 2 secondes.</p>\n");
}
