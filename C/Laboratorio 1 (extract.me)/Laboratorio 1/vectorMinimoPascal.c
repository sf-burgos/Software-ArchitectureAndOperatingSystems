
#include <stdio.h>

void eVector(int n, int vector[n]){
	int i=0;
	printf("\nEscribir el vector\n");
	for(i=0; i<n; i++){
		printf("%i\n", vector[i]);
	}
	printf("\n");
}

void sumatoria(int n, int vector[n]){
	int i=0;
	int suma=0;
	printf("\nCalcular la suma\n");	
	for(i=0; i<n; i++){
		suma = suma + vector[i];
	}
	printf("%i\n", suma);
	eVector(n, vector);
}

void leerVector(int n){
	int vector[n];
	int current;
	int i=0; 
	printf("\nLeer el vector\n");
	for(i=0; i<n; i++){
		scanf("%i", &current);
		vector[i] = current;
	}
	sumatoria(n,vector);
}

int main(){
	int n;
	scanf("%i", &n);
	leerVector(n);
}
