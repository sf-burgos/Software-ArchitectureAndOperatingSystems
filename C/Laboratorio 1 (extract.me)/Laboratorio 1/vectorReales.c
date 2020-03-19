#include <stdio.h>

int main(){
	int n;
	scanf("%i",&n);
	int i = 0;
	float curr;
	float vector[n];
	for(i=0; i<n; i++){
		scanf("%f", &curr);
		vector[i] = curr;
	}
	i = 0;
	float mm = vector[0];
	for(i=0; i<n; i++){
		if (vector[i] < mm){
			mm = vector[i];
		}
	}
	printf("%f\n", mm);
}
