#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 50

typedef struct{
		char mois[255], jour[255], moment[255], user[255], not_1[255], not_2[255];
		char action[255], actionneur[255];
}Info;

void affichage_not(char* name);
void pagination(int* nombre_page , char* page_get , char* name);
void affiche_page(Info* acceder, int* nombre_lignes, int* page);
int page_choisi(char* page_get);
int total_page(int* lignes);
void affichage_html(Info* final , int* nombre_lignes_final , char* name , char* page_get);
void comparaison_structure (Info* acceder , int* nombre_lignes , Info* final , int* nombre_lignes_final , char* name);
void remplissage(Info* acceder , int* nombre_lignes);
void take(char* name, char* page_get);

int main(){
	printf("Content-Type:text/html\n\n");
	
	char* name=malloc(100);
	char* page_get=malloc(100);
	Info* acceder = malloc(5000*sizeof(Info));
	Info* final = malloc(5000*sizeof(Info));
	int nombre_lignes = 0;
	int nombre_lignes_final=0;
	
	take(name,page_get);
	remplissage(acceder,&nombre_lignes);
	comparaison_structure(acceder , &nombre_lignes , final , &nombre_lignes_final , name);
	
	if(nombre_lignes_final != 0){
		affichage_html(final,&nombre_lignes_final,name,page_get);
	}
	else if(nombre_lignes_final == 0){
		affichage_not(name);
	}
	
	free(name);	free(page_get);
	free(acceder);	free(final);
	return 0;
}
void affichage_not(char* name){
	printf("<html>\n");
	printf("<head>\n");
	printf("<meta charset=\"UTF-8\">");
    printf("<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">");
    printf("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
	printf("<title>Recuperation donnees dans /var/log/auth.log</title>\n");
	printf("<style>\n");
	printf("body{background-color: rgb(36, 35, 35);text-align: center;}"
        ".p_1{max-width:800px;margin:200px auto 0 auto; color:red;line-height: 50px; font-size: 2.5rem;}"
        "span{color:rgb(238, 232, 232);}"
        );	
    printf(".p_2{margin-top:70px ; text-align: center;}"
        "a{text-decoration: none;}"
        ".other_span{border:2px bisque solid; padding: 30px;font-variant: small-caps; background-color: bisque; color:black;font-weight: bold;}"
        ".other_span:hover{background-color: rgb(243, 62, 62); border:black;}"
        );
	printf("</style>\n");
	printf("</head>\n");
	printf("<body>\n");
		printf("<p class=\"p_1\">Désolé!<br>Aucune donnée trouvée pour: <span>%s</span></p>",name);
		printf(" <p class=\"p_2\"><a href=\"http://www.anita.com/cgi-bin/var_log/recherche.cgi\"><span class=\"other_span\">Rechercher un autre utilisateur</span></a></p>");
	printf("</body>\n");
}
///Affiche les numéros de page 
void pagination(int* nombre_page , char* page_get , char* name){
	int page;
	page=page_choisi(page_get);
	int end=page+4;
	int begin=page-5;
	
	if(end > *nombre_page){
		end = *nombre_page;
	}
	
	if(begin<0){
		begin=0;
	}
	
	printf("<div>\n");
	for(int i=begin ; i<end; i++){
		if(i+1==page){
			printf("<a class=\"chosen\" href='http://www.anita.com/cgi-bin/var_log/mitady.cgi?anarana=%s&page=%d'>%d</a>\n",name,i+1,i+1);
		}
		else{
			printf("<a  href='http://www.anita.com/cgi-bin/var_log/mitady.cgi?anarana=%s&page=%d'>%d</a>\n",name,i+1,i+1);
		}

	}
	printf("</div>\n");
	
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
///La page choisie
int page_choisi(char* page_get){
	int page=1;
	
	page = atoi(page_get);
	
	return page;
	
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
///Affiche la page html en integral
void affichage_html(Info* final , int* nombre_lignes_final , char* name , char* page_get){
	printf("<html>\n");
	printf("<head>\n");
	printf("<meta charset=\"UTF-8\">");
    printf("<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">");
    printf("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
	printf("<title>Recuperation donnees dans /var/log/auth.log</title>\n");
	printf("<style>\n");
	printf("body{background-color:rgb(236, 200, 179);}\n");
	printf("table{margin:auto;background-color:white;}\ntable,td,th,tr{border:5px solid rgb(161, 114, 87);\nborder-collapse:collapse;\npadding:18px}\nth{font-size:2.2em;\ncolor:rgb(161, 100, 64);}\ntd{color:black;font-size:1.8em;font-family:monospace;font-weight:bold;}\n");
	printf("h2{font-size:2em;color:rgb(119, 51, 12);text-decoration:underline 3px solid;}\n"); 
	printf("table{margin-bottom:30px;}");
	printf(".opened{background-color:rgba(64, 209, 93, 0.87);}\n");
	printf(".closed{background-color:rgb(206, 10, 10);}\n");
	printf("a{text-decoration: none; color:rgb(119, 51, 12); border:2px solid rgb(119, 51, 12);padding:7px;margin:3px;}");
	printf(".chosen{background-color:rgb(119, 51, 12);color:white}");
	printf("</style>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<center>\n");
	
	printf("<h2>Voici la liste totale des acc&egrave;s au systeme (ouverture et fermeture) fait par %s</h2>\n",name); 
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
	
	 nombre_pages=total_page(nombre_lignes_final);
	 
	 page=page_choisi(page_get);
	 
	affiche_page(final,nombre_lignes_final,&page);
	
	printf("</tbody>\n");
	printf("</table>\n");
	
	pagination(&nombre_pages,page_get,name);
	
	printf("</center>\n");
	printf("</body>\n");
	printf("</html>\n");
}
///Comparaison de la structure initiale à la structure finale ou l'on va transmettre les données apres verification
void comparaison_structure (Info* acceder , int* nombre_lignes , Info* final , int* nombre_lignes_final , char* name){	
	
	*nombre_lignes_final=0;
	int j=0;
	
	for(int i=0; i<*nombre_lignes; i++){
		
		//~ printf("1---><tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n", acceder[i].mois, acceder[i].jour, acceder[i].moment, acceder[i].action, acceder[i].actionneur);
		
		if(strcmp(acceder[i].actionneur,name)==0){
			strcpy(final[j].mois,acceder[i].mois);
			strcpy(final[j].jour,acceder[i].jour);
			strcpy(final[j].moment,acceder[i].moment);
			strcpy(final[j].action,acceder[i].action);
			strcpy(final[j].actionneur,acceder[i].actionneur);
			
			//~ printf("2---><tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n\n",final[j].mois,final[j].jour,final[j].moment,final[j].action,final[j].actionneur);
			
			j++;
		}
		
	}
	
	*nombre_lignes_final=j;
	//~ printf("Il y a %d nombres de lignes dans la finale\n",*nombre_lignes_final);
	
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
	//~ printf("Il y %d nombres de lignes\n",*nombre_lignes);
	pclose(file);
}
void take(char* name, char* page_get){
	char* data = getenv("QUERY_STRING");
	
	//~ char data[100];
	//~ strcpy(data,"anarana=root&page=1");
	
	if(data != NULL){
		
		if(strstr(data,"page")!=NULL){
			sscanf(data, "anarana=%[^&]&page=%s",name,page_get);
		}
		else if(strstr(data,"page")==NULL){
			sscanf(data,"%*[^=]=%[^&]&",name);
			strcpy(page_get,"1");
		}
	}
	else{
		fprintf(stderr, "Erreur : Aucune donnée de requête (QUERY_STRING) n'a été reçue.\n");
	}
	
}
