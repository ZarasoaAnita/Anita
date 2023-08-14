#include <stdio.h>
#include <stdlib.h>
void getData(float* pa, float* pb, float* c);

int main(){
	printf("Resolution d'une equation du second degre\n");
	float a=0, b=0, c=0;
	
	getData(&a, &b, &c);
	
	return 0;
}
void getData(float* pa, float* pb, float* c){
	printf("Entrez a: ");
	scanf("%f",pa);
	printf("Entrez b: ");
	scanf("%f",pb);
	printf("Entrez c: ");
	scanf("%f",c);
}
