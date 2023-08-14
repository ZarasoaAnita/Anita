#include <stdio.h>
#include <math.h>

int main () {
	int a=7 , b=3;
	b = ++a;
	printf("a = %d \tb = %d\n",a,b);
	
	a =7 ; b=3;
	b = a++;
	printf("a = %d \tb = %d\n",a,b);
	
	a=7 ;
	b=3 ;
	int c=2;
	printf("a-b-c= %d \ta-(b-c)= %d\n",a-b-c,a-(b-c));
	
	printf("a/b/c= %d \ta/(b/c)= %d\n", a/b/c, a/(b/c));
	return 0;
}
