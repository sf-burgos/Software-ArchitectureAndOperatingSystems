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

void multiplicando(char primerNumero, char segundoNumero[500],char resultadoParcial[1001]){
	int i,carga,valor;
	carga = 0;
	div_t resultadoDivision;
	for (i = strlen(segundoNumero)-1;i>-1;i--){
		valor = (segundoNumero[i]-'0')*(primerNumero-'0')+carga;
		resultadoDivision = div(valor,10);
		carga = resultadoDivision.quot;
		resultadoParcial[i] = resultadoDivision.rem+'0';
	}
	if (carga != 0){
		for(i = strlen(resultadoParcial)-1;i>-1;i--){
			resultadoParcial[i+1] = resultadoParcial[i];
		}
		resultadoParcial[0] = carga+'0';
	}
}

void multiplica(char primerNumero [500],char segundoNumero[500]){
	char resultadoFinal[1001] = "";
	char resultadoParcial[1001] = "";
	int i;
	multiplicando(segundoNumero[strlen(segundoNumero)-1],primerNumero,resultadoParcial);
	for (i = 0;i<strlen(resultadoParcial);i++){
		resultadoFinal[i] = resultadoParcial[i];
	}
	i = 0;
	char variableDeCeros [1001] = "0";
	for (i = strlen(segundoNumero)-2;i>-1;i--){
		char resultadoParcial[1001] = "";
		multiplicando(segundoNumero[i],primerNumero,resultadoParcial);

		strcat(resultadoParcial,variableDeCeros);
		
		strcat(variableDeCeros,"0");
		
		sumaDeNumeros(resultadoParcial,resultadoFinal,resultadoFinal);
	}
	printf("%s\n",resultadoFinal);	
}

int main(){
	int numero;
	char primerNumero [500];
	char segundoNumero [500];

	scanf("%d\n",&numero);
	int i;
	for(i = 0;i<numero;i++){
		scanf("%s",primerNumero);
		scanf("%s",segundoNumero);
	
		if (strlen(primerNumero)>=strlen(segundoNumero)){
			multiplica(primerNumero,segundoNumero);
		} else {
			multiplica(segundoNumero,primerNumero);
		}	
	}
	return 0;
}

