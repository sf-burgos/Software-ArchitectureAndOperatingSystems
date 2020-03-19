#include<stdio.h>
 
int menu(int opc){

	printf("CALCULADORA\n");	
	printf("----------------------\n");	
	printf("\n");
	printf("1. Sumar dos numeros\n");
	printf("2. Restar dos numeros\n");
	printf("3. Multiplicion de dos numeros\n\n");
	printf("4. Dividir dos numeros\n\n");
      	printf("\n");
	printf("Ingrese la opcion\n");
	scanf("%i", &opc);
	return opc;	
}

void sumar(float x, float y){
	float r ;
	r = x+y;
	printf("%f\n", r);
}

void restar(float x, float y){
	float r ;
	r = x-y;
	printf("%f\n", r);
}

void multiplicar(float x, float y){
	float r ;
	r = x*y;
	printf("%f\n", r);
}

void dividir(float x, float y){
	if (y == 0){
		printf("No es posible dividir por cero\n");
	}else{
		float r ;
		r = x/y;
		printf("%f\n", r);
	}
}

int main(){
	int opc=0;
	while (opc != 5){
		opc = menu(opc);
		if (opc != 5){
			float x,y;
			printf("Primer numero:\n");
			scanf("%f", &x);
			printf("Segundo numero:\n");
			scanf("%f", &y);
			if (opc == 1){
				sumar(x,y);
			}else if(opc == 2){
				restar(x,y);
			}else if(opc == 3){
				multiplicar(x,y);
			}else if(opc == 4){
				dividir(x,y);
			}else {
				printf("No es una opción válida\n");
			}
		}
	}
}
