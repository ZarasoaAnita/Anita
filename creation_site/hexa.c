char*placepourcent(char*t){
	char*car=malloc(250);
	
	for(int i=0,l=0;i<strlen(t);i++){
		
    if((t[i]!='%')){
		car[l++]=t[i];	
			
		}	
	}
	return car;
}
int chartoint(char*ca){
	int n=0;
	int k=16;
	int*tab=malloc(sizeof(int)*2);
	int*tab1=malloc(sizeof(int)*2);
	
	tab=tableau2(ca);
	tab1=tableau1(ca);
	
	for(int i=0;i<strlen(ca);i++){
		if((ca[i]>='0'&& ca[i]<='9')||(ca[i]>='A' && ca[i]<='F')){
			if((ca[i]>='0'&& ca[i]<='9')){
		    n+=((ca[i]-'0')*pow(k,strlen(ca)-1-tab[i]));
	        }
	        if((ca[i]>='A' && ca[i]<='F')){
		     n+=((ca[i]-'A'+10)* pow(k,strlen(ca)-1-tab1[i]));
		    
		    }
	   }
	  }
	     
    
	return n;
}
char* withoutHex(char* tab){
    char* new = malloc(strlen(tab) + 1);
    int i = 0, j = 0;
    char hex[3];
    char car;

    while (tab[i] != '\0') {
        if (tab[i] == '%' && tab[i + 1] != '\0' && tab[i + 2] != '\0') {
            hex[0] = tab[i + 1];
            hex[1] = tab[i + 2];
            hex[2] = '\0';

            car=chartoint(hex);

            if (car != -1) {
                new[j] = car;
                i += 3;
            } else {
                new[j] = tab[i];
                i++;
            }
        } else if (tab[i] == '+') {
            new[j] = ' ';
            i++;
        } else {
            new[j] = tab[i];
            i++;
        }
        j++;
    }
    new[j] = '\0';

    return new;
}

int*tableau2(char*ca){
	int l=strlen(ca);
	int*tab=malloc(sizeof(int)*l);
	for(int i=0;i<strlen(ca);i++){
			if((ca[i]>='0'&& ca[i]<='9')){
				tab[i]=i;
			}
		}
	return tab;
}
int*tableau1(char*ca){
	int l=strlen(ca);
	int*tab1=malloc(sizeof(int)*l);
	for(int i=0;i<strlen(ca);i++){
			if((ca[i]>='A'&& ca[i]<='F')){
				tab1[i]=i;
			}
		}
	return tab1;
}
