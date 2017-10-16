#include<stdio.h>
  int gb=0;
  int dpact(int a[],int t[],int n,int* node){
    if(node==0){
      if((a[n][node+1]+t[n][node])<=a[n+1][node]){
		  printf("%d0 ",n);
        return a[n][node+1]+t[n][node]+dpact(a,t,n+1,node+1);
      }else{
		  printf("%d1 ",n);
        return a[n][node]+dpact(a,t,n+1,node);
      }
  	}else{
		if((a[n][node]+t[n][node])<=a[n+1][node])){
			    return a[n][node+1]+t[n][node]+dpact(a,t,n+1,node+1);
		}

  	}
	  printf("\n");
  }
  void dppath(int e[],int x[],int* a,int* t){
	  int pointer = 0;
    if(e[0]>=e[1]){
      gb=e[0]+dpact(a,t,0,(int *)pointer);
    }else{
		pointer =1;
      gb=e[1]+dpact(a,t,0,(int *)pointer);
    }
	printf("%d---\n",gb);
  }
  void main(){
    int n;//station
    scanf("%d",&n);
    int e[2];
    scanf("%d %d",&e[0],&e[1]);
    int x[2];
    scanf("%d %d",&x[0],&x[1]);
    int i;
    int a[n][2];
    int j;
    for(j=0;j<2;j++)
    for(i=0;i<n;i++){
      scanf("%d",&a[i][j]);
    }

    int t[n-1][2];
    for(j=0;j<2;j++)
    for(i=0;i<n-1;i++){
      scanf("%d",&t[i][j]);
    }

    dppath(e,x,(int *)a,(int *)t);

  }
