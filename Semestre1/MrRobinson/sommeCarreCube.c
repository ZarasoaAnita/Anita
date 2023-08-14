#include <stdio.h>
#include <math.h>

void display (int n , int scarres , int scubes ) ;
void sommes ( int n , int *pscarre , int *pscube) ;

int main () {
	printf("Calcul de la somme des carres et des cubes des n premiers entiers non nuls\n");
	
///Données
	int n =3 ;          //limite de sommation en entrée
	int scarres = 777,  //somme des carrés à calculer
		scubes = 34 ;	//somme des cubes à calculer
/*	int *pscarre = NULL;
		pscarre = &scarres;
	int *pscube = NULL;
		pscube = &scubes;
*/		
///Transformation
	sommes ( n , &scarres , &scubes);
	//sommes(n, pscarre , pscube);

///Résultats
	display(n , scarres , scubes );
	
	return 0;
}
void display (int n , int scarres , int scubes ) {
	printf("La somme des carres des %d premiers entiers non nuls est : %d\n",n,scarres);
	
	printf("La somme des cubes des %d premiers entiers non nuls est : %d\n",n,scubes);	
	
}

void sommes ( int n , int *pscarre , int *pscube)  {
	int k = 0 ;
	*pscarre = 0;
	*pscube = 0;
	
	for (k=1 ; k<=n ; k++) {
		*pscarre += (k*k);	
		*pscube += (k*k*k);
		//*pscube += pow ( k , 3);
	}
	
}
