#include<stdio.h>
#include<math.h>

int main(){
	int i=0, casos;
	double a,b,c,x,x2,sol;
	scanf("%d",&casos);
	for (i;i<casos;i=i+1){
		scanf("%lf",&a);
		scanf("%lf",&b);
		scanf("%lf",&c);
		if(a==0){
			printf("no roots\n");
		}
		else{
			sol=b*b-4*a*c;
			if (sol>0){
				x=(-b+sqrt(sol))/(2.0*a);
				x2=(-b-sqrt(sol))/(2.0*a);
				if (x==x2){
					printf("%.2lf\n",x);
					
				}
				else{
				printf("%.2lf\n",x);
				printf("%.2lf\n",x2);
				}
			}
			else{
				if(sol==0){
					x=(-b)/(2*a);
					printf("%.2lf\n",x);
				}
				else{
					printf("no roots\n");
				}
				
			}
		}
	
	}
	return 0;
}
