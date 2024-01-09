#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void comparaison(char* name , char* passwd);

int main(){
	char* data = getenv("QUERY_STRING");
    char* name = malloc(100);
    char* passwd = malloc(100);
    
    if(data == NULL){
        free(name);
        free(passwd);
        exit(1);
    }
    
    sscanf(data, "name=%[^&]&password=%[^&]&submit=Login", name, passwd);
	comparaison(name,passwd);
	
	return 0;
}
//~ void comparaison(char* name , char* passwd){
	//~ FILE* file_1 = fopen("/home/anita/HTML/AT_SCHOOL/var_log/data.txt", "r");
	//~ FILE* file_2 = fopen("/home/anita/HTML/AT_SCHOOL/var_log/connected.txt","w+");
	
	//~ if(file_1 != NULL){
		//~ char ligne[255];
        //~ int i = 1;

        //~ while (fgets(ligne, 255, file_1) != NULL) {
            //~ char name_tmp[255] = "";
            //~ char password_tmp[255] = "";

            //~ sscanf(ligne, "name=%[^\t]\tpassword=%[^\n]\n", name_tmp, password_tmp);

            //~ if (strcmp(name, name_tmp) == 0 && strcmp(passwd, password_tmp) == 0) {
                
                //~ // Redirection 1 avec la balise <meta>
                //~ printf("Content-type: text/html\n\n");
                //~ printf("<meta http-equiv=\"refresh\" content=\"0;url=http://www.anita.com/cgi-bin/var_log/welcome_log.cgi\">\n");
                //~ i = 0;
                //~ break;
            //~ }
        //~ }

        //~ if (i == 1) {
            //~ // Redirection 2 avec la balise <meta>
            //~ printf("Content-type: text/html\n\n");
            //~ printf("<meta http-equiv=\"refresh\" content=\"0;url=http://www.anita.com/var_log/login_error.html\">\n");
        //~ }	
	//~ }
	//~ fclose(file_1);
	//~ fclose(file_2);
//~ }
void comparaison(char* name, char* passwd) {
    FILE* file_1 = fopen("/home/anita/HTML/AT_SCHOOL/var_log/data.txt", "r");
    FILE* file_2 = fopen("/home/anita/HTML/AT_SCHOOL/var_log/connected.txt", "w+");

    if (file_1 != NULL && file_2 != NULL) {
        char ligne[255];
        int i = 1;

        while (fgets(ligne, 255, file_1) != NULL) {
            char name_tmp[255] = "";
            char password_tmp[255] = "";

            sscanf(ligne, "name=%[^\t]\tpassword=%[^\n]\n", name_tmp, password_tmp);

            if (strcmp(name, name_tmp) == 0 && strcmp(passwd, password_tmp) == 0) {
                // Écriture dans file_2
                fprintf(file_2, "Utilisateur connecté : %s\n", name);
                
                // Redirection 1 avec la balise <meta>
                printf("Content-type: text/html\n\n");
                printf("<meta http-equiv=\"refresh\" content=\"0;url=http://www.anita.com/cgi-bin/var_log/welcome_log.cgi\">\n");
                i = 0;
                break;
            }
        }

        if (i == 1) {
            // Redirection 2 avec la balise <meta>
            printf("Content-type: text/html\n\n");
            printf("<meta http-equiv=\"refresh\" content=\"0;url=http://www.anita.com/var_log/login_error.html\">\n");
        }
    } else {
        printf("Erreur lors de l'ouverture des fichiers.\n");
    }

    fclose(file_1);
    fclose(file_2);
}

