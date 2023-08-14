#include <stdio.h>
void permute( int *a ,int *b );

int main () {
	int a = 2;
	int b = 3;

	printf("Entrez a\n");
	scanf("%d",&a);

	printf("Entrez b\n");
	scanf("%d",&b);

/*	int temp = a;
	a = b;
	b = temp;
*/
	permute(&a,&b);

	printf("a=%d\nb=%d\n ",a,b);

	return 0;
}
void permute ( int* a , int* b ) {
	int temp = *a;
	*a = *b;
	*b = temp;

}
