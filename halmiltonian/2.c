#include<stdio.h>
int check(int tem[],int path[],int n){
  int x;
  for(x=0;x<n;x++){
    if(path[x]==-1)
      return 0;
  }
  for(x=0;x<n;x++){
    printf("%d ",path[x]);
  }
  printf("\n");
  return 1;
}
int main(){
  int n,x,y,path[10],tem[10];
  scanf("%d",&n);

  for(x=0;x<n;x++){
    path[x]=-1;
    tem[x]=-1;
  }
  path[0]=0;
  tem[0]=1;
  x=1;
  while(path[0]!=-1){
    if(path[x]>=n){
      tem[x]=-1;
      x--;
      path[x]++;
    }
    if(path[x]==-1)path[x]=0;
    for(y=path[x];y<n;y++){
      printf("%d ",y);
      if(tem[y]==-1){
        path[x++]=y;
        tem[y]=1;
        if(check(tem,path,n)){
          tem[x]=-1;
          x--;
          path[x]++;
        }
        break;
      }
    }
    if(x<=0)break;
  }
  return 1;
}
