#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 50

typedef struct{
	char ip[255];
	char date[255]; 
	char heure[255]; 
	char methode[255]; 
	char get_request[500]; 
	char url[255];	
}Info;

void remplissage (Info* acceder, int* nombre_lignes);
void affichage (Info* acceder , int* nombre_lignes);
int total_page(int* lignes);
int page_choisi() ;
void affiche_page(Info* acceder, int* nombre_lignes, int* page);
void pagination(int* nombre_page);

int main(){
	printf("Content-Type:text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<meta charset=\"UTF-8\">");
	printf("<title>Recuperation donnees dans /var/log/apache2/access.log</title>\n");
	printf("<style>\n");
	printf("body{width:100vw;}");
	printf("table{ background-color:rgb(190, 241, 243);width:90vw;margin:15px;height:80vh;}");
	printf("table,th,td,tr{border: 5px solid rgb(53, 122, 111);border-collapse: collapse;padding: 10px;}");
	printf("h2{font-size:2rem;font-variant: small-caps;}");
	printf("th{font-size: 1.5rem;font-weight: bold;}");
	printf("td{font-size:1em;}");
	printf(".chosen{background-color:#e96a6a;}");
	printf("input{height:40px;width:35px;}");
	printf("</style>\n");
	printf("</head>\n");
	
	printf("<body>\n");
	printf("<center>\n");
	printf("<h2>Liste des requêtes HTTP reçues par le serveur Apache2</h2>\n"); 
	printf("<table>\n");
	printf("<thead>\n");
	printf("<tr>\n");
	printf("<th>IP du client</th>\n");
	printf("<th>Date</th>\n");
	printf("<th>Heure</th>\n");
	printf("<th>Methode</th>\n");	
	printf("<th>GET request</th>\n");
	printf("<th>URL</th>\n");
	printf("</tr>\n");
	printf("</thead>\n");
	printf("<tbody>\n");
	
	Info* acceder = malloc(5000*sizeof(Info));
	int nombre_lignes;
	int nombre_pages;
	int page=1;
	
	remplissage(acceder,&nombre_lignes);
	nombre_pages=total_page(&nombre_lignes);
	//affichage(acceder,&nombre_lignes);
	page=page_choisi();
	affiche_page(acceder,&nombre_lignes,&page);

	printf("</tbody>\n");
	printf("</table>\n");
	
	pagination(&nombre_pages);
	
	printf("</center>\n");
	printf("</body>\n");
	printf("</html>\n");
	
	free(acceder);
	return 0;
}
void remplissage (Info* acceder, int* nombre_lignes){
	
	FILE* file=NULL;
	file=popen("cat /var/log/apache2/access.log","r");
	
	if(file==NULL){
		printf("Erreur d'ouverture du fichier /var/log/apache2/acces.log \n");
		exit(1);
	}
	
	*nombre_lignes=0;
	int i=0;
	char ligne[1024];

	while (fgets(ligne, sizeof(ligne), file) != NULL) {		
		sscanf(ligne,"%[^ ] %*[^[][%[^:]:%[^ ] %*[^\"]\"%[^ ] %[^ ] %*[^\"]\"%*[^\"]\"%[^\"]\"%*[^\n]\n",acceder[i].ip,acceder[i].date,acceder[i].heure,acceder[i].methode,acceder[i].get_request,acceder[i].url);
		//printf("<tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n",acceder[i].ip, acceder[i].date,acceder[i].heure,acceder[i].methode,acceder[i].get_request,acceder[i].url);
		
		i++;
	}
	
	*nombre_lignes = i;
	//printf("Il y %d nombres de lignes\n",*nombre_lignes);
	pclose(file);	
}

void affichage (Info* acceder , int* nombre_lignes){
	for(int j=0; j<*nombre_lignes; j++){
	printf("<tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n",acceder[j].ip, acceder[j].date,acceder[j].heure,acceder[j].methode,acceder[j].get_request,acceder[j].url);	
	}
}
int total_page(int* lignes){
	int nombre_page=0;
	nombre_page = *lignes/10;
	
	if(*lignes % 10 != 0){
		nombre_page ++;
	}
	
	//printf(" Nombre total de page = %d\n",nombre_page);
	
	return nombre_page;
}
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
void affiche_page(Info* acceder, int* nombre_lignes, int* page) {
    int start_index = (10 * (*page)) - 10;
    int end_index = 10 * (*page);

    for (int j = start_index; j < end_index && j < *nombre_lignes; j++) {
        	printf("<tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n",acceder[j].ip, acceder[j].date,acceder[j].heure,acceder[j].methode,acceder[j].get_request,acceder[j].url);	
    }
    
    
}
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
	
	printf("<form action=\"http://www.anita.com/cgi-bin/creation_site/access.cgi\" method=\"get\">");
	
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

