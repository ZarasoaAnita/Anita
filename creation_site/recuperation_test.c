#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hexa.h"

char* trueName(char* serverName);
void enabled_or_disabled(char*conf);
//char** sites_available ();
 void activation (char* name);
 void desactivation(char* name);

int main(){
    printf("Content-type: text/html\n\n");
    char* take=getenv("QUERY_STRING");

   


   	char* serverName=NULL;	serverName=malloc(100); ///prend le nom du serveur ex:www.anita.com
    char* name=NULL;	name=malloc(100); ///prend uniquement le nom dans le nom du serveur ici par ex:anita
    char* nom_serveur=malloc(100);///ce qu'on va mettre dans le fichier .conf
    char* admin=malloc(100);
    char* documentRoot=NULL;	documentRoot=malloc(100);
    char* racine=malloc(100);
    char* alias=malloc(100);
    char* dir1a=malloc(100); char* dir1b=malloc(100); char* dir1c=malloc(50);
    char* dir2a=malloc(100); char* dir2b=malloc(100); char* dir2c=malloc(100); char* dir2d=malloc(50);
    char* err1a=malloc(100); char* err1b=malloc(100);
    char* virtual1a=malloc(100);
    char* virtual1b=malloc(100);
    char* creation=malloc(100);
    char* cmd=malloc(500);
    char* host=malloc(100);

    
    printf("<html lang=\"en\">\n<head>\n<meta charset=\"UTF-8\">\n<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
    printf("\n<title>Creation site </title>\n");
    printf("</head>\n");
   
    printf("<body>\n");
    
		if(take!=NULL){
        sscanf(take,"%*[^=]=%[^&]&%*[^=]=%[^&]&",serverName,documentRoot);
        printf("%s<br>",serverName);
        name=trueName(serverName);
        printf("%s<br>",name);
        printf("%s<br>",withoutHex(documentRoot));
            sprintf(nom_serveur,"ServerName %s",serverName);
            strcpy(admin,"ServerAdmin webmaster@localhost");
            sprintf(racine,"DocumentRoot %s",withoutHex(documentRoot));
            sprintf(alias,"ScriptAlias /cgi-bin/ %s/cgi-bin/",withoutHex(documentRoot));
            sprintf(dir1a,"<Directory %s>",withoutHex(documentRoot));
            strcpy(dir1b,"Require all granted");
            strcpy(dir1c,"</Directory>");
            sprintf(dir2a,"<Directory %s/cgi/bin/>",withoutHex(documentRoot));
            strcpy(dir2b,"Options +ExecCGI");
            strcpy(dir2c,"AddHandler cgi-script .cgi");
            strcpy(dir2d,"</Directory>");
            sprintf(err1a,"ErrorLog ${APACHE_LOG_DIR}/error.www.%s.log",name);
		    sprintf(err1b,"CustomLog /var/log/apache2/access.%s.log combined",name);
            strcpy(virtual1a,"<VirtualHost *:80>");
		    strcpy(virtual1b,"</VirtualHost>");

			strcpy(creation,"/home/anita/HTML/AT_SCHOOL/creation_site/");
			strcat(creation,name);
			strcat(creation,".conf");
            sprintf(host,"127.0.0.1\t%s",serverName);
            printf("%s\n",host);
			
            FILE* file=NULL;
            file=fopen(creation,"w+");

            if(file ==NULL){
                printf("Le fichier n'a pas été créé\n");
            }
            fprintf(file,"%s\n\n\t%s\n\n\t%s\n\t%s\n\n\t%s\n\n\t%s\n\t\t%s\n\t%s\n\n\t%s\n\t\t%s\n\t\t%s\n\t%s\n\n\t%s\n\t%s\n\n%s\n",virtual1a,nom_serveur,admin,racine,alias,dir1a,dir1b,dir1c,dir2a,dir2b,dir2c,dir2d,err1a,err1b,virtual1b);

            		
			fclose(file);

            sprintf(cmd,"sudo cp %s /etc/apache2/sites-available/",creation);

            popen(cmd,"w");

            
            sprintf(cmd,"sudo sh -c 'echo %s >> /etc/hosts'",host);
            popen(cmd, "w");
        
            sprintf(cmd,"sudo a2ensite %s",name);
            printf("<h1>%s</h1>",cmd);
            popen(cmd, "w");
            

            popen("sudo systemctl reload apache2","w");
            
		}
        else {
        fprintf(stderr, "Erreur : Aucune donnée de requête (QUERY_STRING) n'a été reçue.\n");
        }


   printf("<a href=\"http://www.anita.com/cgi-bin/recuperation.cgi?serverName=%s&racine=%s&activate=activer\">Activer</a>",serverName,documentRoot);
   if(strstr(take,"activer")!=NULL){
        activation(name);
   }

   printf("<br><br>");
    printf("<a href=\"http://www.anita.com/cgi-bin/recuperation.cgi?serverName=%s&racine=%s&activate=desactiver\">Desactiver</a>",serverName,documentRoot);
   if(strstr(take,"desactiver")!=NULL){
        desactivation(name);
   }
   printf("</body>\n</html>\n"); 
    return 0;
}
//Fonction pour extraire la partie entre les deux points dans le nom du serveur
char* trueName(char* serverName){
    // Recherche du premier point dans le nom du serveur
    char* premierPoint = strchr(serverName, '.');

    // Si le premier point est trouvé
    if (premierPoint != NULL) {
        // Recherche du deuxième point à partir de l'emplacement du premier point
        char* deuxiemePoint = strchr(premierPoint + 1, '.');

        // Si le deuxième point est trouvé
        if (deuxiemePoint != NULL) {
            // Calcul de la longueur de la partie entre les deux points
            int longueur = deuxiemePoint - (premierPoint + 1);

            // Allocation d'une nouvelle chaîne pour stocker la partie entre les deux points
            char* nomServeur = (char*)malloc(longueur + 1);

            // Copie de la partie entre les deux points dans la nouvelle chaîne
            strncpy(nomServeur, premierPoint + 1, longueur);

            // Ajout d'un caractère nul à la fin de la nouvelle chaîne
            nomServeur[longueur] = '\0';

            // Retour de la nouvelle chaîne
            return nomServeur;
        }
    }
}

void activation (char* name){
    char* cmd=malloc(100);
    sprintf(cmd,"sudo a2ensite %s",name);
    popen(cmd,"w");
    popen("sudo systemctl reload apache2","w");
    printf("<meta http-equiv='refresh' content='0' url=\"http://www.anita.com/cgi-bin/recuperation.cgi\">");
} 

void desactivation(char* name){
    char* cmd = malloc(100);
     sprintf(cmd,"sudo a2dissite %s",name);
     popen(cmd,"w");
     popen("sudo systemctl reload apache2","w");
     printf("<meta http-equiv='refresh' content='0' url=\"http://www.anita.com/cgi-bin/recuperation.cgi\">");
}

