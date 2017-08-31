#include<stdio.h>
#include <conio.h>
#define MAX 25
// int MAX = 25;
int x[MAX];
void cycle(int G[MAX][MAX],int n,int k);
  void next(int G[MAX][MAX],int n,int k);
int main(){
  int n;
  int Edges;
  int G[MAX][MAX];
  int i;
  int j;
  int v1;
  int v2;

  printf("vertice graph");
  scanf("%d",&n);

  for( i=1;i<=n;i++ ){
    for(j=1;j<=n;j++){
      G[i][j]=0;
      x[i]=0;
    }
  }
  printf("\ninput");
   scanf("%d",&Edges);
  for(i =1;i<=Edges;i++){
    scanf("%d%d",&v1,&v2);
    G[v1][v2]=1;
    G[v2][v1]=1;
  }
  int B[MAX][MAX]= {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
 int C[MAX][MAX] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };
  x[1]=1;
  cycle(G,n,2);
  return 0;
}
  void cycle(int G[MAX][MAX],int n,int k){
    int i;

    printf("%d%d\n",n,k );
    // while(1)
    // {
    next(G,n,k);//generates next legal vertex for determining cycle

    // if(x[k]==0)
    // return;

     if(k==n)
     {
      printf("\n");
      for(i=1;i<=n;i++)
       printf(" %d",x[i]);  //printing Hamiltonian cycle
      printf(" %d",x[1]);


     }
     else
      cycle(G,n,k+1);
    // }
  }
  void next(int G[MAX][MAX],int n,int k){
    int j;
   while(1)
   {
    //obtain next vertex
    x[k]=(x[k]+1)%(n+1);
    printf("x[%d]%d\n",k,x[k]);
    if(x[k]==0)
     return;
    if(G[x[k-1]][x[k]]!=0)
    { //if edge between k and k-1 is present
     for(j=1; //every adjacent vertex
     {
      if(x[j]==x[k]){//not a distinct vertex
        printf("running" );
       break;}
     }
     if(j==k) //obtain a distinct vertex
     {
       printf("passing to loop2 j:%d:%d\n",j,k);
      if((k<n)||((k==n)&&(G[x[n]][x[1]]!=0)))
       return;//return a distinct vertex
     }
    }
   }
  }
