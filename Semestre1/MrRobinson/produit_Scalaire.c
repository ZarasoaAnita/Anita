#include <stdio.h>
float pscal (int dim , float* u , float* v );
void display(int dim , float* u,float* v ,float prod );
void changeU (int dim , float *u);

int main () {
	printf("Calcul de produit scalaire de 2 vecteurs\n");

///Donnée
	int 	dim=3 ; //la dimension des vecteurs 
	float	u[3] = {1., 2., 3.}, // déclaration avec initialisation de tableau de type float 
			v[3] = {1., 4., 5.};
	
	float prod =0.35 ;	           //le produit scalaire
	
	changeU(dim , u);
	
///Calcul 
	/*
	 prod = 0;
	for(int i=0; i<dim ; i++) {
		prod += (u[i]*v[i]);
	}
	*/
	prod = pscal (dim , u , v);

///Sortie
	display(dim, u, v, prod);

//	printf("Le produit scalaire de u et de v est = %f\n",prod);
	
	return 0;
 }
void changeU (int dim , float *u) {
	 u[2] = 1;//notation tableau
	*(u+2) = 1;//notation pointeur
	//*u = 0;
	//u[0] = 0;
 }

void display(int dim , float* u,float* v ,float prod ) {
	
	printf("\nu= \n");
	for(int i=0 ; i<dim ; i++) {
		//printf("u[%d] = %f\n", i, u[i]);
		printf("u[%d] = %f\n", i, *(u+i));
	}
	
	printf("\nv= \n");
	for(int i=0 ; i<dim ; i++) {
		printf("v[%d] = %f\n", i, v[i]);
	}		
		
		
	printf("Le produit scalaire de u et de v est = %f\n",prod);
	}
	
float pscal (int dim , float* u , float* v ) {
	float prod = 567;  //on le redeclare ici car la fonction pscal ne le connait pas 
	prod = 0;
	for(int i=0; i<dim ; i++) {
		prod += (u[i]*v[i]);
	}
	return prod;
}

