#include<stdio.h>
int n,st=-1;
int path(int matrix[100][100],int x){
	int y;
	//printf("st\n");
	if(st==-1)st=x;
	else if(st==x){
		for(y=0;y<n;y++)
			if(!matrix[y][n]){
				return 0;
			}
		return 1;
	}
	//printf("start %d\n",x);
	for(y=0;y<n;y++){
		//printf("%d %d\n",st,y);
		if(matrix[y][n]==0 || st==y){
			if(x!=y && matrix[x][y]){
				// printf("showxy%d,%dst%d\n",x,y,st);
				matrix[x][n]=1;
				if(path(matrix,y)){
					printf("%d ",y);
					return 1;
				}else {
					printf("%d%d",x,n);
					matrix[x]	[n]=0;
					printf("re \n");
				}
			}else{

			}
		}printf("\n");
	}

	return 0;
}

int main(){
	int m ;
	int x,y,temp[100][100],matrix[100][100];
	scanf("%d",&n);
	for(x=0;x<n;x++)
		for(y=0;y<n;y++)
			scanf("%d",&matrix[x][y]);

			// temp = matrix;
			for(m=0;m<n;m++){
				// matrix = temp;
				st = -1;
				path(matrix,m);
			}

	// if(path(matrix,1	))printf("%d\n",st);
	return 0;
}
