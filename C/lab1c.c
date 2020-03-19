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

void multiplica(char primerNumero [1000],char segundoNumero[1000]){
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
	strcpy(segundoNumero,resultadoFinal);
}

void potenciaUno(int potencia,char numero[1000]){
	if (potencia == 0){
		strcpy(numero,"1");
	} else {
		char resultadoPotencia[1000];
		strcpy(resultadoPotencia,numero);
		int i;
		for (i = 0;i<potencia-1;i++){
			//printf("%d %s\n",potencia,resultadoPotencia);
			multiplica(numero,resultadoPotencia);
		}
		strcpy(numero,resultadoPotencia);
	}
}

void potenciaDos(int potencia,char numero[1000]){
	div_t resultadoDivision;
	resultadoDivision = div(potencia,2);
	int residuo = resultadoDivision.rem;
	if (potencia == 0){
		strcpy(numero,"1");
	} else if (potencia % 5 == 0){
		char resultadoPotencia[1000];
		strcpy(resultadoPotencia,numero);
		potenciaUno(potencia/5,resultadoPotencia);
		char numeroAuxiliar [1000];
		strcpy(numeroAuxiliar,resultadoPotencia);
		multiplica(numeroAuxiliar,resultadoPotencia);
		multiplica(numeroAuxiliar,resultadoPotencia);
		multiplica(numeroAuxiliar,resultadoPotencia);
		multiplica(numeroAuxiliar,resultadoPotencia);
		strcpy(numero,resultadoPotencia);
	} else if (residuo % 3 == 0){
		char resultadoPotencia[1000];
		strcpy(resultadoPotencia,numero);
		potenciaUno(potencia/3,resultadoPotencia);
		char numeroAuxiliar [1000];
		strcpy(numeroAuxiliar,resultadoPotencia);
		multiplica(numeroAuxiliar,resultadoPotencia);
		multiplica(numeroAuxiliar,resultadoPotencia);
		strcpy(numero,resultadoPotencia);
	} else if (residuo == 0){
		char resultadoPotencia[1000];
		strcpy(resultadoPotencia,numero);
		potenciaUno(potencia/2,resultadoPotencia);
		char numeroAuxiliar [1000];
		strcpy(numeroAuxiliar,resultadoPotencia);
		multiplica(numeroAuxiliar,resultadoPotencia);
		strcpy(numero,resultadoPotencia);
	} else {
		char resultadoPotencia[1000];
		strcpy(resultadoPotencia,numero);
		potenciaUno(potencia/2,resultadoPotencia);
		char numeroAuxiliar [1000];
		strcpy(numeroAuxiliar,resultadoPotencia);
		multiplica(numeroAuxiliar,resultadoPotencia);
		multiplica(numero,resultadoPotencia);
		strcpy(numero,resultadoPotencia);
	}
}

void convertirBaseDiez(int base, char numero[1000]){
	char posibles [36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char resultadoFinal[1000] = "0";
	int i;
	//printf("%s ESTE ES EL NUMOER\n",numero);
	//printf("%d VAMOS POR ACA\n",strlen(numero));
	for (i=0;i<strlen(numero);i++){
		int i2;
		for(i2=0;i2<strlen(posibles);i2++){
			if (numero[i] == posibles[i2]){
				break;
			}
		}
		char resultadoPotencia [1000];
		sprintf(resultadoPotencia,"%d",base);
		potenciaDos(strlen(numero)-(i+1),resultadoPotencia);
		//printf("%c %d %d\n",numero[i],base,strlen(numero)-(i+1));
		//printf("%s EY ACA HAY POTENCIA\n",resultadoPotencia);
		char numeroActual[1000];
		sprintf(numeroActual,"%d",i2);
		multiplica(numeroActual,resultadoPotencia);
		sumaDeNumeros(resultadoPotencia,resultadoFinal,resultadoFinal);
	}
	if (base == 10){
		printf("%s\n",numero);
	} else {
		printf("%s\n",resultadoFinal);
	}
}

int main(){
	int numero;
	char numeroConvertir [1000];
	int base;

	scanf("%d\n",&numero);
	int i;
	for(i = 0;i<numero;i++){
		scanf("%i %s",&base,numeroConvertir);
		//printf("%d VAMOS POR ACA\n",strlen(numeroConvertir));
		convertirBaseDiez(base,numeroConvertir);
	}
	return 0;
}

