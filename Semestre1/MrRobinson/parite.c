#include <stdio.h>
#include <stdlib.h>

int main() {
		printf("Savoir si un nombre saisi est pair ou impair\n\n");
		int n=0;
		
		printf("Saisissez un entier : ");
		scanf("%d",&n);
		
		if(n%2==0) {
			printf("%d est un nombre pair\n",n);
		}
		
		else {
			printf("%d est un nombre impair\n",n);
		}
		
		return 0;
	
}
