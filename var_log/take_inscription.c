#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verification(char* username, char* passwd_1, char* passwd_2);
void printErrorPage(int errorCode);

int main() {
    char* username = malloc(100);
    char* passwd_1 = malloc(100);
    char* passwd_2 = malloc(100);
    char* data = getenv("QUERY_STRING");
    int result = 0;

    if (data == NULL) {
        fprintf(stderr, "Erreur : Aucune donnée de requête (QUERY_STRING) n'a été reçue.\n");
        free(username);
        free(passwd_1);
        free(passwd_2);
        return 1;
    }

    if (sscanf(data, "username=%99[^&]&passwd1=%99[^&]&passwd2=%99s", username, passwd_1, passwd_2) != 3) {
        fprintf(stderr, "Erreur : La structure de la requête n'est pas valide.\n");
        free(username);
        free(passwd_1);
        free(passwd_2);
        return 1;
    }

    result = verification(username, passwd_1, passwd_2);

    if (result != 0) {
        // Redirection en cas d'erreur
        //~ printf("Content-type: text/html\n\n");
        //~ printf("<html><head><meta http-equiv=\"refresh\" content=\"0;url=http://www.anita.com/var_log/sign_up.html\"></head></html>");
        
        printErrorPage(result);
    } else {
        // Traitement réussi
        FILE* file = fopen("/home/anita/HTML/AT_SCHOOL/var_log/data.txt", "a");
        if (file == NULL) {
            perror("Erreur d'ouverture du fichier");
            free(username);
            free(passwd_1);
            free(passwd_2);
            return 1;
        }

        fprintf(file, "name=%s\tpassword=%s\n", username, passwd_1);
        fclose(file);

        // Redirection en cas de succès
        printf("Content-type: text/html\n\n");
        printf("<html><head><meta http-equiv=\"refresh\" content=\"0;url=http://www.anita.com/var_log/login.html\"></head></html>");
        
         //~ // L'inscription est réussie, vous pouvez rediriger l'utilisateur vers une page de confirmation
        //~ printf("Location: http://www.anita.com/var_log/login.html\n\n");
    }

    free(username);
    free(passwd_1);
    free(passwd_2);

    return 0;
}

int verification(char* username, char* passwd_1, char* passwd_2){
	FILE* file = NULL;
	 file=fopen("/home/anita/HTML/AT_SCHOOL/var_log/data.txt","r");
	
	//~ if(file == NULL){
		//~ printf("Erreur d'ouverture du fichier\n");
		//~ exit(1);
	//~ }
	
	if(strlen(username)<3){
		return 1;
	}
	if(strcmp(passwd_1,passwd_2) != 0){
		return 2;
	}
	if(strlen(passwd_1)<6){
		return 3;
	}
	char ligne[255];
	while (fgets(ligne,255, file) != NULL){
		char tmp[255];
		sscanf(ligne,"name=%[^\t]\t",tmp);
		if(strcmp(username,tmp)==0){
			return 4;
			break;
		}
	}
	
	fclose(file);
	return 0;
}	
void printErrorPage(int errorCode) {
    printf("Content-type: text/html\n\n");
    printf("<!DOCTYPE html>\n");
    printf("<html lang=\"fr\">\n");
    printf("<head>\n");
    printf("    <meta charset=\"UTF-8\">\n");
    printf("    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    printf("    <title>Page d'Erreur</title>\n");
    printf("    <style>\n");
    printf("        body {\n");
    printf("            font-family: Arial, sans-serif;\n");
    printf("            text-align: center;\n");
    printf("            margin: 50px;\n");
    printf("        }\n");
    printf("\n");
    printf("        h1 {\n");
    printf("            color: #FF0000;\n");
    printf("        }\n");
    printf("\n");
    printf("        p {\n");
    printf("            color: #333333;\n");
    printf("        }\n");
    printf("    </style>\n");
    printf("</head>\n");
    printf("<body>\n");
    printf("    <h1>Une erreur s'est produite</h1>\n");
    printf("    <p>Une erreur s'est produite pendant le processus d'inscription car :</p>\n");

    // Afficher un message d'erreur approprié en fonction du code d'erreur
    switch (errorCode) {
        case 1:
            printf("    <p id=\"error-message\">Le nom d'utilisateur doit comporter au moins 3 caractères.</p>\n");
            break;
        case 2:
            printf("    <p id=\"error-message\">Les mots de passe ne correspondent pas.</p>\n");
            break;
        case 3:
            printf("    <p id=\"error-message\">Le mot de passe doit comporter au moins 6 caractères.</p>\n");
            break;
        case 4:
            printf("    <p id=\"error-message\">Le nom d'utilisateur est déjà pris. Veuillez en choisir un autre.</p>\n");
            break;
        // Ajoutez plus de cas pour d'autres codes d'erreur si nécessaire
        default:
            printf("    <p id=\"error-message\">Une erreur inconnue s'est produite. Veuillez réessayer.</p>\n");
    }
    
	printf("<p class=\"again\">");
    printf("<a href='http://www.anita.com/var_log/sign_up.html'>Reessayer</a>");
    printf("</p>");


    printf("</body>\n");
    printf("</html>\n");

  
}
	

	
	
	
	
	
	
	
	
	
	
