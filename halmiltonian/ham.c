#include<stdio.h>
#include <conio.h>
#define MAX 25
// int MAX = 25;
int x[MAX];

int main(){
  int n=0;
  int Edges;
  int G[MAX][MAX];
  int i;
  int j;
  int v1;
  int v2;

  printf("vertice graph");
  scanf("%d",&n);
  for( i=1;i<=n;i++ ){
    for(j=1;j<=n;i++){
      G[i][j]=0;
      x[i]=0;
    }
  }
  printf("\ninput");
  for(int i =1;i<Edges;i++){
    scanf("%d%d",&v1,&v2);
    G[v1][v2]=1;
    G[v2][v1]=1;
  }
  // hami(G,n,2);
  return 0;

}
