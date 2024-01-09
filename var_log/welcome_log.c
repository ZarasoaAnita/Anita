#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void redirection (int* i);
void ouverture();

int main(){
	printf("Content-Type:text/html\n\n");
	
	int what=0;
				
	redirection(&what);
	
	if(what > 0){
		ouverture();
	}
	else if(what==0){
		printf("<meta http-equiv=\"refresh\" content=\"0;url=http://www.anita.com/var_log/ask_login.html\">\n");
	}
	
	return 0;
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
void ouverture(){
	printf("<!DOCTYPE html>"
		"<html lang='en'>"
		"<head>"
			"<meta charset='UTF-8'>"
			"<meta http-equiv='X-UA-Compatible' content='IE=edge'>"
			"<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
			"<title>Welcome Log</title>"
			"<style>"
				"body{background-color: rgb(161, 118, 77);width:100vw;text-align: center;}"
				".principal{max-width:1000px;margin:200px auto 0 auto;}"
				"ul{list-style-position: inside;}"
				"ul{font-size: 3rem;}"
				".liste{font-size: 2rem;}"
				".secondaire{display: flex;flex-direction: column; text-align: left; line-height: 60px; color:rgb(65, 193, 216); margin:20px 0 50px 0;}"
				"li{padding-bottom: 20px;font-variant: small-caps;}"
				".go{text-decoration: none; color:rgb(41, 190, 216); font-weight: 700;}"
				".go:hover{background-color: rgb(174, 240, 199);}"
				".bye{text-decoration:none; color:rgba(0,0,0);}"
				".deconnexion{border:2px black solid; width:15vw; height:60px; text-align:center; padding-top:20px;margin:0 auto 0 auto;font-size:2rem;}"
				".deconnexion:hover{background-color:rgba(0,0,0,0.5);; color:white;}"
				".bye:hover{color:white;}"
			"</style>"
		"</head>"
		"<body>"
			"<div class='principal'>"
				
				"<ul>Que voulez-vous faire?"
					"<hr>"
					"<div class='secondaire'>"
						"<li class='liste'><a class='go' href='http://www.anita.com/cgi-bin/var_log/recherche.cgi'>Rechercher les accès au système d'un utilisateur </a></li>"
						"<li class='liste'><a class='go' href='http://www.anita.com/cgi-bin/var_log/all_liste_log.cgi'>Afficher la liste complète des accès au système</a></li>"
					"</div>"
				"</ul>"
				
			"</div>"
			"<div class='deconnexion'>"
				"<a class='bye' href='http://www.anita.com/cgi-bin/var_log/deconnexion.cgi'>Deconnexion</a>"
			"</div>"
		"</body>"
		"</html>"
	);
}
	
