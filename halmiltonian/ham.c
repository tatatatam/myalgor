#include<stdio.h>
#include <conio.h>

	void print(int *num, int n)
	{
		int i;
		for ( i = 0 ; i < n-1 ; i++)
			printf("%d ", num[i]);
		printf("\n");
	}
	void main(){
	int m ;
	int n;
	int i,j,x,y,temp,tmp[100][100],matrix[100][100];
	  scanf("%d",&n);
		for(x=0;x<n;x++)
			for(y=0;y<n;y++)
				scanf("%d",&matrix[x][y]);
		int num[n+1];
		for(i=0;i<n;i++){
			num[i]=i;
		}
		for (j = 1; j <= n; j++) {
		 for (i = 0; i < n-1; i++) {
			 temp = num[i];
			 num[i] = num[i+1];
			 num[i+1] = temp;
			//  num[n] = num[0];
			 print(num, n+1);
			 y=0;//STACK DDATA
			 for(x =0 ;x<n-1;x++){
				 if(matrix[num[x]][num[x+1]]==1){

					 y++;
				 }
			 }
			//  printf("%d")
			 if(y==n-1)printf("true\n");
			//  else printf("false\n");
		}
	 	}
	}
