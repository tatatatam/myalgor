#include<stdio.h>
#define n_line 2
#define n_st 4

  int min(int x ,int y){
	//   printf("%d %d\n",x,y);
	  if(x>y)return x;
	  else return y;
  }
  void printer(int t[],int size){
	  int i;
	  for(i=0;i<size;i++)printf("%d ",t[i]);printf("\n");
  }
  int computing(int t[][n_line],int a[][n_line],int e[],int x[]){
  int T1[n_st], T2[n_st], L2[n_st],L1[n_st],i;
	// printf("%d %d\n",e[0],e[1]);
  	T1[0] = e[0] + a[0][0]; // time taken to leave first station in line 1
  	T2[0] = e[1] + a[0][1]; // time taken to leave first station in line 2

  // Fill tables T1[] and T2[] using the above given recursive relations
  for (i = 1; i < n_st; i++)
  {
   // printf("%d %d\n",T1[i-1],T2[i-1]);
   // T1[i] = min(T1[i-1] + a[i][0], T2[i-1] + t[i-1][1] + a[i][0]);
   // T2[i] = min(T2[i-1] + a[i][1], T1[i-1] + t[i-1][0] + a[i][1]);
   if((T1[i-1] + a[i][0])> (T2[i-1] + t[i-1][1] + a[i][0])){
	  T1[i] = T1[i-1] + a[i][0];
	  L1[i-1]=1;
   }else{
	 T1[i] = T2[i-1] + t[i-1][1] + a[i][0];
	   L1[i-1]=2;
   }
   if((T2[i-1] + a[i][1])>(T1[i-1]+t[i-1][0]+a[i][1])){
	  T2[i] = T2[i-1] + a[i][1];
	  L2[i-1] = 2;
   }else{
	 T2[i] =T1[i-1]+t[i-1][0]+a[i][1];
		 L2[i-1] = 1;

  }
	}
	printer(T1,n_st);
	printer(T2,n_st);
	printer(L1,n_st-1);
	printer(L2,n_st-1);
  // Consider exit times and retutn minimum
  int lastpick = min(T1[n_st-1] + x[0], T2[n_st-1] + x[1]);
	// lastpick =0;
	if(T1[n_st-1] + x[0]>T2[n_st-1] + x[1]){
		// printer(T1);
		printf(" %d",2);
	}else{
		// printer(T2)
	}

  return lastpick;
  // return 0;
  }

  void main(){
    int n;//station
    scanf("%d",&n);
    int e[2];
    scanf("%d %d",&e[0],&e[1]);
    int x[2];
    scanf("%d %d",&x[0],&x[1]);
    int i;
    int a[n][n_line];
    int j;
    for(j=0;j<2;j++)
    for(i=0;i<n;i++){
      scanf("%d",&a[i][j]);
    }

    int t[n-1][n_line];
    for(j=0;j<2;j++)
    for(i=0;i<n-1;i++){
      scanf("%d",&t[i][j]);
    }

    printf("%d",computing(t,a,e,x));
  }

    // if((T1[i-1] + a[i][0])<= (T2[i-1] + t[i][1] + a[i][0])){
 //  	  T1[i] = T1[i-1] + a[i][0];
 //  	  L1[i]=1;
    // }else{
 //  	 T1[i] = T2[i-1] + t[i][1] + a[i][0];
 //  	   L1[i]=2;
    // }
    // if((T2[i-1] + a[i][1])<=(T1[i-1]+t[i][0]+a[i][1])){
 //  	  T2[i] = T2[i-1] + a[i][1];
 //  	  L2[i] = 2;
    // }else{
 //  	 T2[i] =T1[i-1]+t[i][0]+a[i][1];
 // 		 L2[i] = 1;
