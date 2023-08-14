#include <stdio.h>
#include <stdlib.h>
void decoupe_minute(int* hour, int* minutes);

int main(){
	int nombre=10;
	int* pointeur=NULL;
	
	pointeur=&nombre;
	
	printf("%p\n",pointeur);
	printf("%p\n",&nombre);
	
	
	return 0;
}
void decoupe_minute(int* hour, int* minute){
	*hour=*minute/60;
	*minute=*minute%60;
}
	
