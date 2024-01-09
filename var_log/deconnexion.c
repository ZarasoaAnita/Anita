#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE* file=NULL;
	file=fopen("/home/anita/HTML/AT_SCHOOL/var_log/connected.txt","w");
	fclose(file);
	
	printf("Content-type: text/html\n\n");

///Ne pas mettre en cache
	printf("Cache-control: no-cahe , no-store , must-revalidate\n");
	printf("Pragma: no-cache\n");
	printf("Expires: 0\n");
	
	
	
	printf("<meta http-equiv=\"refresh\" content=\"0;url=http://www.anita.com/var_log/login.html\">\n");
	
	return 0;
}
