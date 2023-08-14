#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	int n=4;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){			
			printf(" #");
		}
		sleep(1);
		printf("\n");
	}
	return 0;
}
