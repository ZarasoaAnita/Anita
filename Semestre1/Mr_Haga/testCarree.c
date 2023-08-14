#include <stdio.h>
#include <unistd.h>

int main(){
	int n=0,k=1;
	printf("entrer un entier \n");
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){			
			printf("%02d ",k);
			k+=1;
		}
		printf("\n");
	}
	return 0;
}
