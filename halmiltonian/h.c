#include<stdio.h>
int n,mark[10],path[10],mat[100][100];
int check(){
	int i;
	for(i=0;i<n;i++){
		if(mark[i]==0)
			return 0;
	}
	for(i=0;i<n-1;i++){
		if(mat[path[i]][path[i+1]]==0 && i+1<n){
			printf("%d %d %d*\n",path[i],path[i+1],mat[path[i]][path[i+1]]);
			for(i=0;i<n;i++){
				printf("%d ",path[i]);
			}
			printf("\n");
			return 0;
		}
	}
	if(mat[path[i]][path[0]]==0){
		/*printf("%d %d %d **\n",path[n-1],path[0],mat[path[n-1]][path[0]]);
		for(i=0;i<n;i++){
				printf("%d ",path[i]);
			}
			printf("\n");*/
		return 0;
	}
	for(i=0;i<n;i++){
		printf("%d ",path[i]);
	}

	printf("%d\n",path[0]);
	return 1;
}
int main(){
	int x=0,y,c=0,k=0;
	scanf("%d",&n);
	for(x=0;x<n;x++)
		for(y=0;y<n;y++)
			scanf("%d",&mat[x][y]);
	for(y=0;y<n;y++)
		mark[y]=0;
	x=0;
	path[x]=0;
	while(1){
		mark[path[x]]=0;
		for(y=k;y<n;y++){
			if(mark[y]==0){
				//printf("%d %d %d\n",x,y,mark[y]);
				path[x]=y;
				mark[y]=1;
				if(check()==1){
					c++;
					break;
				}
				y=-1;
				x++;
			}
				//printf("%d %d %d **\n",x,y,mark[y]);
		}
		if(y>=n-1 && x==0)break;
		mark[path[x]]=0;
		path[x]=0;
		x--;
		k=path[x]+1;

	}
	printf("%d",c);
	return 1;
}
