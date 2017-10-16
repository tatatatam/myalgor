#include<stdio.h>
void printarr(int arr[],int n){
  int i=0;
  for(i=0;i<n;i++)
  printf("%d--%d",arr[i],n);
  printf("\n");
}
void swap(int a[],int i,int j){
  int c;
  c= a[i]; a[i]= a[j];a[j]=c;
}
    int BruteForce(){

    }
  void perm(int a[],int n){
      if (n == 1) {
          //some how dump the contents into the 2D array "resulting2DArray"
          printarr(a,n);
           return;
       }
       for (int i = 0; i < n; i++) {
           swap(a, i, n-1);
           perm(a, n-1);
           swap(a, i, n-1);
       }
    }

int main(){
	int m ;
  int n;
	int x,y,temp[100][100],matrix[100][100];
  scanf("%d",&n);
	for(x=0;x<n;x++)
		for(y=0;y<n;y++)
			scanf("%d",&matrix[x][y]);

      int i,arr[n],res[n][n];
      for(i=0;i<n;i++){
        arr[i]=i;
        printf("%d->",arr[i]);
      }
      perm(arr,n);


			// temp = matrix;
			// for(m=0;m<n;m++){
				// matrix = temp;
				// st = -1;
				// path(matrix,m);
			// }

	// if(path(matrix,1	))printf("%d\n",st);
	return 0;
}
