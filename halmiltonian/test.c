#include<stdio.h>

void print(int path[],int n){
  int x;
  for(x=0;x<n;x++){
    if(path[x]!=-1)
      printf("%d ",path[x]+1);
  }
  printf("\n");
}
int main(){
int x,y,n,tmp,pointer,j,temp[10],mark[10],matrix[100][100];
  scanf("%d",&n);
  for(x=0;x<n;x++)
    for(y=0;y<n;y++){
      temp[y]=-1;
      scanf("%d",&matrix[x][y]);
    }
  temp[0]=0;
  pointer=0;
  for(j=0;j<n;j++){
    mark[j]=0;
  }
  mark[0]=1;
  j=0;
  while(mark[0]==0){
    x=temp[pointer];
    for(;j<n;j++){
      if(matrix[x][j]>0 && mark[j]==0 && j!=x){
        x=temp[++pointer]=j;
        mark[x]=1;
        j=-1;
      }else if(matrix[x][j]>0 && temp[0]==j && j!=x){
        print(temp,n);
      }
    }
    mark[x]=0;
    temp[pointer--]=0;
    j=temp[pointer];
  }
  return 1;
}
