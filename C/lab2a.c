#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void sumaDeNumeros(char primerNumero [1001],char segundoNumero [1001],char resultadoSuperFinal[1001]){
	char auxiliar [1000];
	if (strlen(primerNumero) > strlen(segundoNumero)){
		int diferencia = strlen(primerNumero) - strlen(segundoNumero);
		strcpy(auxiliar,"0");
		int i2;
		for (i2 = 0;i2<diferencia-1;i2++){
			strcat(auxiliar,"0");
		}
		strcat(auxiliar,segundoNumero);
		strcpy(segundoNumero,auxiliar);
	} else if (strlen(primerNumero) < strlen(segundoNumero)){
		int diferencia = strlen(segundoNumero) - strlen(primerNumero);
		strcpy(auxiliar,"0");
		int i2;
		for (i2 = 0;i2<diferencia-1;i2++){
			strcat(auxiliar,"0");
		}
		strcat(auxiliar,primerNumero);
		strcpy(primerNumero,auxiliar);
	}
	int carga = 0;
	int i;
	int resultadoParcial;
	char resultadoFinal[1001] = "";
	char resultadoMedioParcial = '0';
	div_t resultadoDivision;
	for (i = strlen(primerNumero)-1;i>-1;i--){
		resultadoParcial = (primerNumero[i]-'0')+(segundoNumero[i]-'0')+carga;
		if (resultadoParcial > 1){
			resultadoDivision = div(resultadoParcial,2);
			carga = resultadoDivision.quot;
			resultadoParcial = resultadoDivision.rem;
		} else {
			carga = 0;
			resultadoDivision = div(resultadoParcial,2);
			resultadoParcial = resultadoDivision.rem;
		}
		resultadoMedioParcial = '0' + resultadoParcial;
		resultadoFinal[i] = resultadoMedioParcial;
	}
	strcpy(resultadoSuperFinal,"");
	if (carga != 0){
		char cargaEnCadena[1];
		sprintf(cargaEnCadena, "%d", carga);
		strcat(resultadoSuperFinal,cargaEnCadena);
	}
	int banderaDeImpresion = 1;
	for (i = 0;i<strlen(resultadoFinal);i++){
		char actual[2];
		if ((carga != 0 || resultadoFinal[i] != '0') && banderaDeImpresion == 1){
			actual[0] = resultadoFinal[i];
			actual[1] = '\0';
			strcat(resultadoSuperFinal,actual);
			banderaDeImpresion = 0;
		} else if (banderaDeImpresion == 0 && resultadoFinal[i]!= '*'){
			actual[0] = resultadoFinal[i];
			actual[1] = '\0';
			strcat(resultadoSuperFinal,actual);
		}
	}
}

void complementoDos(char numero[1000]){
	char auxiliar[1000] = "";
	int i;
	for (i=0;i<strlen(numero);i++){
		if (numero[i]=='1'){
			auxiliar[i] = '0';
		} else {
			auxiliar[i] = '1';
		}
	}
	char UNO [1000] = "1";
	char auxiliarDos [1000] = "1";
	sumaDeNumeros(auxiliar,UNO,auxiliarDos);
	strcpy(numero,auxiliarDos);
}

void restaBinario(char primerNumero [1000],char segundoNumero[1000]){
	char resultado[1000] = "";
	char auxiliar [1000];
	char variableDeCeros [1000] = "";
	char segundoNumeroAuxiliar[1000] = "";
	strcpy(segundoNumeroAuxiliar,segundoNumero);
	if (strlen(primerNumero) > strlen(segundoNumero)){
		int i;
		for (i = 0; i < strlen(primerNumero)-strlen(segundoNumero);i++){
			strcat(variableDeCeros,"0");
		}
	}
	strcpy(auxiliar,segundoNumero);
	strcpy(segundoNumero,variableDeCeros);
	strcat(segundoNumero,auxiliar);
	complementoDos(segundoNumero);	
	sumaDeNumeros(primerNumero,segundoNumero,resultado);
	if (strlen(primerNumero)>strlen(segundoNumeroAuxiliar)){
		if (strlen(resultado)< strlen(primerNumero)){
			strcpy(auxiliar,"");
			strcpy(variableDeCeros,"");
			int i;
			for (i = 0; i < strlen(primerNumero)-strlen(resultado);i++){
				strcat(variableDeCeros,"0");
				
			}
			strcpy(auxiliar,resultado);
			strcpy(resultado,variableDeCeros);
			strcat(resultado,auxiliar);
			printf("%s\n",resultado);
		} else {
			int i2;
			for (i2 = strlen(resultado)-strlen(primerNumero);i2<strlen(resultado);i2++){
				printf("%c",resultado[i2]);
			}
			printf("\n");
		}
	} else {
		if (strlen(resultado)< strlen(segundoNumeroAuxiliar)){
			strcpy(auxiliar,"");
			strcpy(variableDeCeros,"");
			int i;
			for (i = 0; i < strlen(segundoNumeroAuxiliar)-strlen(resultado);i++){
				strcat(variableDeCeros,"0");
				
			}
			strcpy(auxiliar,resultado);
			strcpy(resultado,variableDeCeros);
			strcat(resultado,auxiliar);
			printf("%s\n",resultado);
		} else {
			int i2;
			for (i2 = strlen(resultado)-strlen(segundoNumeroAuxiliar);i2<strlen(resultado);i2++){
				printf("%c",resultado[i2]);
			}
			printf("\n");
		}
	}	
}

int main(){
	int numero;
	char primerNumero [1000];
	char segundoNumero [1000];

	scanf("%d\n",&numero);
	int i;
	for(i = 0;i<numero;i++){
		scanf("%s",primerNumero);
		scanf("%s",segundoNumero);
		int i2;
		char auxiliar [1000];
		
		restaBinario(primerNumero,segundoNumero);
	
	}
	return 0;
}
