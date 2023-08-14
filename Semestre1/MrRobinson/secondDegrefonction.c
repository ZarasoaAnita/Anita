#include <stdio.h>
#include <math.h>

void displayResult ( float a , float b , float c , float delta , float x1 , float x2 );
float calcDelta ( float a, float b, float c ) ;
//void resolve ( float a , float b , float c , float * delta , float * x1 , float * x2 ) ;
float resolve1 (float a , float b , float c, float *x1 , float *x2 ) ;
void getData ( float * pa , float * pb , float * c );

int main () {
	printf("Resolution de ax^2+bx+c=0 dans R\n");
	
///Données
	float a= 1 , b= 2 , c= 1 ; //les coefficients de l'équation
	float x1= 167 , x2= 678.7 ; //les solutions éventuelles
	float delta= 1 ; //le discriminant de l'équation
	
	while (1) {
	getData ( &a , &b , &c ); //pour recuper les valeurs de a , b et c

///Calcul
	delta = resolve1 ( a , b, c, &x1 ,&x2 ); //Pour résoudre l'équation
//	resolve ( a , b , c , &delta , &x1 ,&x2 );

/*	delta = calcDelta ( a, b, c );//sert à sortir la valeur de delta
	if ( delta >= 0 ) {
		x1 = ( (-b - (sqrt(delta))) / 2*a ) ;
		x2 = ( (-b + (sqrt(delta))) / 2*a ) ;
	} */

///Sortie
	displayResult (a , b , c, delta , x1 , x2) ; //pour afficher les résultats	
    }
    
	return 0 ;
}
void getData ( float * pa , float * pb , float * c ) {
	printf("Entrez a:");
	scanf("%f",pa);
	printf("Entrez b:");
	scanf("%f",pb);
	printf("Entrez c:");
	scanf("%f",c);
}

float resolve1 (float a , float b , float c, float* x1 , float* x2 ) {
	float delta1 = 1234 ; //le discriminant de l'equation
	
	delta1 = calcDelta (a , b , c);
	
	if (delta1 >= 0 ) {
		*x1 = ( (-b - (sqrt(delta1))) / 2*a ) ;
		*x2 = ( (-b + (sqrt(delta1))) / 2*a ) ;
	}
	
	return delta1 ;
}
/*void resolve ( float a , float b , float c , float *delta , float *x1 , float *x2 ) {
		*delta = calcDelta ( a, b, c );//sert à sortir la valeur de delta

	if (*delta >= 0 ) {
		*x1 = ( (-b - (sqrt(*delta))) / 2*a ) ;
		*x2 = ( (-b + (sqrt(*delta))) / 2*a ) ;
	}
}*/

float calcDelta ( float a, float b, float c ) {
	float delta = 0 ;
	delta = b*b - 4*a*c;
	
	return delta ;
}

void displayResult ( float a , float b , float c , float delta , float x1 , float x2 ) {
	if (delta < 0) {
		printf("Il n'y a pas de solutions reelles\n");
	}
	else {
	printf("Avec les coefficients:\na= %f\nb= %f\nc= %f\n",a,b,c);
	
	printf("Les solutions sont\nx1= %f\nx2= %f\n",x1,x2);
	}
}


