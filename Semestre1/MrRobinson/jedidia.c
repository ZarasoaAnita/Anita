#include <stdio.h>
#include <stdlib.h>
int main(){
	int**tab=malloc(3*sizeof(int*));
	for(int i=0;i<3;i++)
		*(tab+i)=malloc(3*sizeof(int));
	**(tab+1)=23;
	tab[1][2]=12;
	printf("tab[1][0]=%d\n",tab[1][0]);
	printf("**(tab+1)=%d\n",**(tab+1));
	printf("*(*(tab+1)+2)=%d\n",*(*(tab+1)+2));
	printf("&tab[1][0]=%p\n",&tab[1][0]);
	printf("*(tab+1)=%p\n",*(tab+1));
	printf("(*(tab+1)+2)=%p\n",*(tab+1)+2);
	printf("&tab[1][2]=%p\n",&tab[1][2]);
	return 0;
}
