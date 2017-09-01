#include<stdio.h>
int n,st=-1;
int path(int matix[100][100],int x){
	int y;
	//printf("st\n");
	if(st==-1)st=x;
	else if(st==x){
		for(y=0;y<n;y++)
			if(!matix[y][n]){
				return 0;
			}
		return 1;
	}
	//printf("start %d\n",x);
	for(y=0;y<n;y++){
		//printf("%d %d\n",st,y);
		if(matix[y][n]==0 || st==y){
			if(x!=y && matix[x][y]){
				matix[x][n]=1;
				if(path(matix,y)){
					printf("%d<-",y);
					return 1;
				}else {
					matix[x][n]=0;
					//printf("re \n");
				}
			}
		}
	}
	return 0;
}

int main(){
	int x,y,matix[100][100];
	scanf("%d",&n);
	for(x=0;x<n;x++)
		for(y=0;y<n;y++)
			scanf("%d",&matix[x][y]);
	if(path(matix,0))printf("%d\n",st);
	return 0;
}
