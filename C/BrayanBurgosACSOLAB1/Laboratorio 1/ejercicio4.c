
#include <stdio.h>

void escribir_vector(int n, int vector[n]){
	int i=0;
	printf("\nEscribir el vector\n");
	for(i=0; i<n; i++){
		printf("%i\n", vector[i]);
	}
	printf("\n");
}

void calcular_suma(int n, int vector[n]){
	int i=0;
	int suma=0;
	printf("\nCalcular la suma\n");	
	for(i=0; i<n; i++){
		suma = suma + vector[i];
	}
	printf("%i\n", suma);
	escribir_vector(n, vector);
}

void leer_vector(int n){
	int vector[n];
	int current;
	int i=0; 
	printf("\nLeer el vector\n");
	for(i=0; i<n; i++){
		scanf("%i", &current);
		vector[i] = current;
	}
	calcular_suma(n,vector);
}

int main(){
	int n;
	printf("Tamaño del vector\n");
	scanf("%i", &n);
	leer_vector(n);
}
