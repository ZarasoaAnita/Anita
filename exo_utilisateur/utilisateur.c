#include <stdio.h>
#include <stdlib.h>

int main(){
	
	FILE *file= NULL;
	
	file=fopen("/etc/passwd","r");
	
	char contenu[255][255];
	char user[25];
	char dir[50];
	char shell[50];
	int uid=0;
	int gid=0;
	
	printf("Content-Type:text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<title>Recuperation utilisateur</title>\n");
	printf("<style>\n");
	printf("table{margin:auto;background-color:#f6ebf2;}\ntable,td,th,tr{border:5px solid #8a6489;\nborder-collapse:collapse;\npadding:25px}\nth{font-size:2.3em;\ncolor:#811453;}\ntd{color:#db0073;font-size:1.8em;font-family:monospace;font-weight:bold;}\n");
	printf("</style>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<center>\n");
	
	
	if(file==NULL){
		exit(1);
	}
	
	printf("<table>\n");
	printf("<thead>\n");
	printf("<tr>\n");
	printf("<th>UTILISATEUR</th>\n");
	printf("<th>DIRECTORY</th>\n");
	printf("</tr>\n");
	printf("</thead>\n");
	
	int i=0;
	for(i=0; feof(file)!=1; i++){
		if(uid>=1000 && gid>=1000 && uid<2000 && gid<2000){
			printf("<tr>\n");
			printf("<td>%s</td><td>%s</td>\n",user,dir);
			printf("</tr>\n");		
	   }
		fgets(contenu[i],255,file);		
		sscanf(contenu[i],"%[^:]:%*[^:]:%d:%d:%*[^:]:%[^:]:%[^:]",user,&uid,&gid,dir,shell);
	}

	printf("</table>\n");
	printf("</ center>\n");
	printf("</body>\n");
	printf("</html>\n");
	
	fclose(file);
	return 0;
}
