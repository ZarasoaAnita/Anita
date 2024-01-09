#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 50

typedef struct{
		char mois[255], jour[255], moment[255], user[255], not_1[255], not_2[255];
		char action[255], actionneur[255];
}Info;


void redirection (int* i);
int page_choisi();
int total_page(int* lignes);
void affiche_page(Info* acceder, int* nombre_lignes, int* page);
void pagination(int* nombre_page);
void affichage_html(Info* acceder , int* nombre_lignes);
void affichage_table(Info* acceder , int* nombre_lignes);
void remplissage(Info* acceder , int* nombre_lignes);
int manisa();

int main(){
	printf("Content-Type:text/html\n\n");

	Info* acceder = malloc(5000*sizeof(Info));
	int nombre_lignes=0;
	int what=0;
				
	
	redirection(&what);
	
	if(what>0){
	remplissage(acceder , &nombre_lignes);
	affichage_html(acceder , &nombre_lignes);
	}
	else if(what==0){
		printf("<meta http-equiv=\"refresh\" content=\"0;url=http://www.anita.com/var_log/ask_login.html\">\n");
	}
	
	free(acceder);
	return 0;
}
///Nombre total de page
int total_page(int* lignes){
	int nombre_page=0;
	nombre_page = *lignes/10;
	
	if(*lignes % 10 != 0){
		nombre_page ++;
	}
	
	//printf(" Nombre total de page = %d\n",nombre_page);
	
	return nombre_page;
}
///La page choisi par l'utilisateur
int page_choisi() {
    int page = 1;
    char* data = getenv("QUERY_STRING");
    char chaine[TAILLE_MAX];

    if (data != NULL) {
        char inutile[TAILLE_MAX];
        if (sscanf(data, "%[^=]=%s", inutile, chaine) == 2 && strlen(chaine) > 0) {
            page = atoi(chaine);
        }
    }

    return page;
}
///Affiche les pages 10 lignes par 10
void affiche_page(Info* acceder, int* nombre_lignes, int* page) {
    int start_index = (10 * (*page)) - 10;
    int end_index = 10 * (*page);

    for (int j = start_index; j < end_index && j < *nombre_lignes; j++) {
        	if (strcmp(acceder[j].action, "opened") == 0){
            printf("<tr class=\"opened\"><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n",acceder[j].mois, acceder[j].jour, acceder[j].moment, acceder[j].action, acceder[j].actionneur);
			 }
			  else if (strcmp(acceder[j].action, "closed") == 0) {
				printf("<tr class=\"closed\"><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n",
				 acceder[j].mois, acceder[j].jour, acceder[j].moment, acceder[j].action, acceder[j].actionneur);
			}
    }
}
///Affiche les numéros de page 
void pagination(int* nombre_page){
	int page;
	page=page_choisi();
	int end=page+4;
	int begin=page-5;
	
	if(end > *nombre_page){
		end = *nombre_page;
	}
	
	if(begin<0){
		begin=0;
	}
	
	printf("<form action=\"http://www.anita.com/cgi-bin/var_log/all_liste_log.cgi\" method=\"get\">");
	
	for(int i=begin ; i<end; i++){
		if(i+1==page){
			printf("<input type=\"submit\" class=\"chosen\" value=\"%d\" name=\"bokotra\">\n",i+1);
		}
		else{
			printf("<input type=\"submit\" value=\"%d\" name=\"bokotra\">\n",i+1);
		}

	}
	
	printf("</form>\n");
	
}
///Affiche la page html en integral
void affichage_html(Info* acceder , int* nombre_lignes){
	printf("<html>\n");
	printf("<head>\n");
	printf("<title>Recuperation donnees dans /var/log/auth.log</title>\n");
	printf("<style>\n");
	printf("body{background-color:rgb(236, 200, 179);}\n");
	printf("table{margin:auto;background-color:white;}\ntable,td,th,tr{border:5px solid rgb(161, 114, 87);\nborder-collapse:collapse;\npadding:18px}\nth{font-size:2.2em;\ncolor:rgb(161, 100, 64);}\ntd{color:black;font-size:1.8em;font-family:monospace;font-weight:bold;}\n");
	printf("h2{font-size:2em;color:rgb(119, 51, 12);text-decoration:underline 3px solid;}\n"); 
	printf("table{margin-bottom:30px;}");
	printf(".opened{background-color:rgba(64, 209, 93, 0.87);}\n");
	printf(".closed{background-color:rgb(206, 10, 10);}\n");
	printf(".chosen{background-color:rgb(119, 51, 12);color:white}");
	printf("input{color:rgb(119, 51, 12); border:2px solid rgb(119, 51, 12);height:40px;width:35px;font-weight: bold;}");
	printf("</style>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<center>\n");
	
	printf("<h2>Voici la liste totale des acc&egrave;s au systeme (ouverture et fermeture)</h2>\n"); 
	printf("<table>\n");
	printf("<thead>\n");
	printf("<tr>\n");
	printf("<th>MOIS</th>\n");
	printf("<th>JOUR</th>\n");
	printf("<th>MOMENT</th>\n");
	printf("<th>ACTION</th>\n");	
	printf("<th>ACTIONNEUR</th>\n");
	printf("</tr>\n");
	printf("</thead>\n");
	printf("<tbody>\n");
	
	int nombre_pages;
	int page=1;
	
	nombre_pages=total_page(nombre_lignes);
	page=page_choisi();
	affiche_page(acceder,nombre_lignes,&page);
	
	printf("</tbody>\n");
	printf("</table>\n");
	
	pagination(&nombre_pages);
	
	
	printf("</center>\n");
	printf("</body>\n");
	printf("</html>\n");
}
///Fonction qui affiche la table au complet (pass necessaire ici vue qu'on va paginer)
void affichage_table(Info* acceder , int* nombre_lignes){
	for(int j=0; j<*nombre_lignes; j++){
		 if (strcmp(acceder[j].action, "opened") == 0){
            printf("<tr class=\"opened\"><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n",acceder[j].mois, acceder[j].jour, acceder[j].moment, acceder[j].action, acceder[j].actionneur);
         }
          else if (strcmp(acceder[j].action, "closed") == 0) {
            printf("<tr class=\"closed\"><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n",
             acceder[j].mois, acceder[j].jour, acceder[j].moment, acceder[j].action, acceder[j].actionneur);
        }
	}
}
///Remplissage de la structure avec les donnees de /var/log/auth.log
void remplissage(Info* acceder , int* nombre_lignes){
	FILE* file=NULL;
	file=popen("cat /var/log/auth.log","r");
	
	if(file==NULL){
		printf("Erreur d'ouverture du fichier\n");
		exit(1);
	}
	
	*nombre_lignes=0;
	
	int i=0;
	char ligne[1024];
	
	while(fgets(ligne, sizeof(ligne),file) != NULL){
		if (strstr(ligne, "for user") && (strstr(ligne,"repeated")==NULL)) {
			char tmp[100];
			sscanf(ligne, "%[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] session %[^ ] for user %s", acceder[i].mois, acceder[i].jour, acceder[i].moment, acceder[i].user, acceder[i].not_1, acceder[i].not_2, acceder[i].action, tmp);
			
				if(strcmp(acceder[i].action,"opened")==0){
					sscanf(tmp, "%[^(](",acceder[i].actionneur);
				}
				else if(strcmp(acceder[i].action,"closed")==0){
					strcpy(acceder[i].actionneur,tmp);
				}
				
				//~ printf("%s",ligne);
				//~ printf("%d ---> %s\n",i,acceder[i].actionneur);
				//~ printf("<tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n\n", acceder[i].mois, acceder[i].jour, acceder[i].moment, acceder[i].action, acceder[i].actionneur);
			
			i++;	
		}	
	}
	
	*nombre_lignes = i;
	//printf("Il y %d nombres de lignes\n",*nombre_lignes);
	pclose(file);
}
///Compte le nombre de lignes
int manisa(){
	FILE* file=NULL;
	file=fopen("/var/log/auth.log","r");
	char ligne[255];
	int k=0;
	while(fgets(ligne, sizeof(ligne), file) != NULL) {
		if (strstr(ligne, "for user") && (strstr(ligne,"repeated")==NULL)) {
		k++;
		}
	}
	printf(" Nombre de ligne= %d\n",k);
	return k;
	fclose(file);
}
void redirection (int* i){
	FILE* file=NULL;
	file = fopen("/home/anita/HTML/AT_SCHOOL/var_log/connected.txt", "r");
	
	*i=0;
	int k=0;
	
	char ligne[255];
	while(fgets(ligne, sizeof(ligne), file) != NULL){
		k++;
	}
	
	*i = k;
	
	fclose(file);
}
	
	
	

	

	
