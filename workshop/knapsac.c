#include<stdio.h>

	void main(){

		int n;
		// int w=0;
		int i=0;
		int W;
		scanf("%d",&n);
		int x[n],p[n],w[n];
		// for(i=0;i<n;i++){
		// 	scanf("%d",&x[i]);
		// }
		// for(i=0;i<n;i++){
		// 	scanf("%d",&p[i]);
		// }
		for(i=0;i<n;i++){
			scanf("%d",&w[i]);
			printf("inw%d\n",w[i]);
		}
		scanf("%d",&W);
		for(i=0;i<n;i++){
			x[i]=0;
		}
		int weight =0;
		for (i=0;i<n;i++){
			if(weight+w[i] <=W){
				x[i]=100;
				weight = weight +w[i];
				printf("%d\n",w[i]);
			}else{
				x[i] = ((W-weight)*100)/w[i];
				weight = W;
				break;
			}
		}
		printf("%d\n ",weight);
		for(i=0;i<n;i++){
			printf("%d",x[i]);

		}
		// return x;
	}
