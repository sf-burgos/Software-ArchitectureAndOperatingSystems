#include <stdio.h>
#include <math.h>
int main(){
	int casos;
	scanf("%d", &casos);
	int i = 0;
	for (i=0; i<casos; i++){
		unsigned long int res = -1;
		unsigned long int coc;
		unsigned long int arriba;
		unsigned long int abajo;
		scanf("%lu" ,&arriba);
		scanf("%lu" ,&abajo);
		while (res != 0){
			coc = abajo / arriba;
			res = abajo % arriba;
			if (res == 0){
				printf("%lu\n", coc);
			}
			else{
				coc = coc + 1; 
				printf("%lu\n" ,coc);
			}
			arriba = (arriba*coc)- abajo;
			abajo = abajo*coc;
		}
		printf("0\n");
	}
	return 0;
}