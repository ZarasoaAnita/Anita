#include <stdio.h>
char itoascii (int i);
char lmtoascii (char c); //on peut aussi faire char mais pas toujours int , ça revient au meme
char lMtoascii (int i);

int main() {
	printf("Affichage des codes ascii des  caracteres alphanumeriques\n\n");
	
	printf("Les digits decimaux:\n");
	for(int i=0 ; i<10 ; i++) {
	printf("%c = %d\t", itoascii(i), itoascii(i));
	}
	
	printf("\n\nLes lettres miniscules:\n");
	for(int i=0; i<26 ; i++) {
	printf("%c = %d\t", lmtoascii(i),lmtoascii(i));
	}
	
	printf("\n\nLes lettres majuscules:\n");
	for(int i=0; i<26 ; i++) {
	printf("%c = %d\t", lMtoascii(i) , lMtoascii(i));
	}
	
	return 0;
}
char itoascii (int i) {
	return '0' + i;//code ASCII des bits decimals
}

char lmtoascii (char c) {
	return 'a' + c;//code ASCII des lettres miniscules
}

//char lMtoascii (char c) 
char lMtoascii (int i) {
	return 'A' + i;//code ASCII des lettres majuscules
}	
