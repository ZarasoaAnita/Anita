#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){



    return 0;
}

char** sites_available (){
    FILE* file=NULL;
    file=popen("ls /etc/apache2/sites-available","r");

    if(file==NULL){
		printf("Erreur d'ouverture du fichier\n");
		exit(1);
	}

   char contenu[255][255];
	int i=0;
	for(i=0; feof(file)!=1; i++){
		fgets(contenu[i],255,testfile);
	}
	
    pclose(testfile);


	int k=0;
	
	for( k=0;k<=i; k++){
	printf("%s",contenu[k]);
	}

    return contenu;
}

void enabled_or_disabled(char*conf){
	char*enable=getenv("QUERY_STRING");
	
	printf("<h3> voici le lien pour visiter le site</h3>");
	char*en=malloc(400);//char*ena=malloc(400);
	sscanf(enable,"%*[^=]=%[^&]&",en);
	printf("<h1>%s</h1>",en);
	char*dis=malloc(400);
	printf("<a href=\"http://www.lahoussa.com/cgi-bin/recupere.cgi?en=Activee\">Activation du site</a><br>");
	printf("<a href=\"http://www.lahoussa.com/cgi-bin/recupere.cgi?en=desactive\">Desactivee le site</a>");
	
	if(strstr(en,"activee")!=NULL){
		sprintf(en,"a2ensite %s",conf);
		system(en);
		
		//strcpy(dis,ena);
	}
	else if(strstr(en,"desactive")!=NULL){
		
		strcpy(dis,en);
		sprintf(dis,"a2dissite %s",conf);
		system(dis);
	}
	

}