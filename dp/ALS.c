#include<stdio.h>
#define n_line 3
#define n_st 4

  int min(int x ,int y){
	  if(x<=y)return x;
	  else return y;
  }
  void printer(int t[],int size){
	  int i;
	  for(i=0;i<size;i++)printf("%d ",t[i]);printf("\n");
  }
  int computing(int t[][n_line],int a[][n_line],int e[],int x[]){
	  int T1[n_st], T2[n_st],T3[n_st], i;
	  printf("%d %d\n",e[0],e[1]);
	  	T1[0] = e[0] + a[0][0]; // time taken to leave first station in line 1
	  	T2[0] = e[1] + a[0][1]; // time taken to leave first station in line 2
	  	T3[0] = e[2] + a[0][2];
	  // Fill tables T1[] and T2[] using the above given recursive relations
	  for (i = 1; i < n_st; i++)
	  {
	   T1[i] =min(T3[i-1]+t[i-1][4]+a[i][0], min(T1[i-1] + a[i][0], T2[i-1] + t[i-1][2] + a[i][0]));
	   T2[i] =min(T3[i-1]+t[i-1][5]+a[i][1], min(T2[i-1] + a[i][1], T1[i-1] + t[i-1][0] + a[i][1]));
	   T3[i] =min(T3[i-1]+a[i][2], min(T1[i-1]+t[i-1][1]+a[i][2], T2[i-1]+t[i-1][3]+a[i][2]));
	  }
	  printer(T1,n_st);
	  printer(T2,n_st);
	  printer(T3,n_st);
	  // Consider exit times and retutn minimum
	  int lastpick = min(T3[n_st-1]+x[3], min(T1[n_st-1] + x[0], T2[n_st-1] + x[1]));
	//    lastpick =0;
	  return lastpick;
  // return 0;
  }

  void main(){
    int n;//station
    scanf("%d",&n);
    int e[3];
    scanf("%d %d %d",&e[0],&e[1],&e[2]);
    int x[3];
    scanf("%d %d %d",&x[0],&x[1],&x[2]);
    int i;
    int a[n][n_line];
    int j;
    for(j=0;j<3;j++)
    for(i=0;i<n;i++){
      scanf("%d",&a[i][j]);
    }

    int t[n-1][n_line];
    for(j=0;j<6;j++)
    for(i=0;i<n-1;i++){
      scanf("%d",&t[i][j]);
    }

    printf("%d",computing(t,a,e,x));
  }
