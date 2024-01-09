#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ouverture();
void redirection (int* i);

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
	printf("<html></html>"
		"<head><title>Formulaire de recherche</title>"
		"<style>"
		"body{background-color: rgba(36, 37, 37, 0.87);}"
		".container{max-width:45vw;margin:150px auto 0 auto;}"
		"h2{ text-decoration: underline; text-transform: uppercase;color:rgb(233, 134, 20);letter-spacing: 3px;line-height: 40px;text-align:center;padding: 15px;font-size: 1.7rem;}"
		"form{text-align: center;}"  
		"label{font-size: 2rem; color:rgb(212, 203, 203); font-weight: bold;}"   
		"input{width: 30vw;}"    
		".text{ height:75px; font-size: 1.5rem; border-radius: 20px; padding-left: 50px;}" 
		".bouton{width:150px;height:30px;font-variant: small-caps;font-size: 1rem;}"  
		".bouton:hover{background-color: rgb(236, 185, 125);}"  
		"</style></head>"   
		"<body>"
		"<div class=\"container\">"
		"    <h2>Recherche des acces au systeme d'un utilisateur en particulier</h2>"   
		"    <form method=\"get\" action=\"http://www.anita.com/cgi-bin/var_log/mitady.cgi\">"   
		"        <p><label for=\"anarana\">Nom :</label>"
		"           <input type=\"text\" name=\"anarana\" class=\"text\"></p>"
		"        <p><input type=\"submit\" value=\"valider\" class=\"bouton\"></p>"    
		"      </form>"
		"</div>"
		"</body>"
		"</html>"
	);
}
