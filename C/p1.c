#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
unsigned long int egipcio (unsigned long int balance);

main(){
	int i=0, casos;
	unsigned long int balance [100];
	unsigned long int a,b,c, uno=1;
	scanf("%d",&casos);
	for (i;i<casos;i=i+1){
		scanf("%lu",&a);
		scanf("%lu",&b);
		printf("A   :   %lu\n", (unsigned long) a);
		printf("B   :   %lu\n", (unsigned long) b);
		
		while ((a/b)!=egipcio(balance)){
			printf("I am here!");
		}
	}
}

unsigned long int egipcio (unsigned long int RR[]){
	int i;
	unsigned long int salida=0;
	for (i=0;i<100;++i){
		salida+=1/RR[i];
	
	
	}
	return salida;


}


