#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void sumaDeNumeros(char primerNumero [1000],char segundoNumero [1000]){
	int carga = 0;
	int i;
	int resultadoParcial;
	char resultadoFinal[1001] = "";
	char resultadoMedioParcial = '0';
	div_t resultadoDivision;
	for (i = strlen(primerNumero);i>-1;i--){
		resultadoParcial = (primerNumero[i]-'0')+(segundoNumero[i]-'0')+carga;
		if (resultadoParcial > 9){
			resultadoDivision = div(resultadoParcial,10);
			carga = resultadoDivision.quot;
			resultadoParcial = resultadoDivision.rem;
		} else {
			carga = 0;
			resultadoDivision = div(resultadoParcial,10);
			resultadoParcial = resultadoDivision.rem;
		}
		resultadoMedioParcial = '0' + resultadoParcial;
		resultadoFinal[i] = resultadoMedioParcial;
	}
	if (carga != 0){
		printf("%c",'0'+carga);
	}
	int banderaDeImpresion = 1;
	for (i = 0;i<strlen(resultadoFinal);i++){
		if ((carga != 0 || resultadoFinal[i] != '0') && banderaDeImpresion == 1){
			printf("%c",resultadoFinal[i]);
			banderaDeImpresion = 0;
		} else if (banderaDeImpresion == 0 && resultadoFinal[i]!= '*'){
		
			printf("%c",resultadoFinal[i]);
		}
	}
	printf("\n");
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
		if (strlen(primerNumero) > strlen(segundoNumero)){
			int diferencia = strlen(primerNumero) - strlen(segundoNumero);
			strcpy(auxiliar,"0");
			for (i2 = 0;i2<diferencia-1;i2++){
				strcat(auxiliar,"0");
			}
			strcat(auxiliar,segundoNumero);
			strcpy(segundoNumero,auxiliar);
		} else if (strlen(primerNumero) < strlen(segundoNumero)){
			int diferencia = strlen(segundoNumero) - strlen(primerNumero);
			strcpy(auxiliar,"0");
			for (i2 = 0;i2<diferencia-1;i2++){
				strcat(auxiliar,"0");
			}
			strcat(auxiliar,primerNumero);
			strcpy(primerNumero,auxiliar);
		}
		sumaDeNumeros(primerNumero,segundoNumero);
	
	}
	
}

