#include<stdio.h>
	 int solver(int arr[] ,int l ,int r){

		 int k,i,j,cpr[r+1];
		 for(i = 0;i<=r;i++){
			 cpr[i] = arr[i];
			//  printf("%d\n",cpr[i]);
		 }
		 k=l+1;
		 i = 1;

		 while(i<r+1 && k<r+1){
			 for(j=i+1;j<r+1;j++){
				 if((arr[k-1]+cpr[j])/2 == arr[k]&&(arr[k-1]+cpr[j]+arr[k]>=3)){
					 arr[k] = cpr[j];
					 cpr[j] =-1;
					 printf("%d %d %d", arr[k-1] , arr[k],cpr[j]);
					 k++;
				 }
			 }
			 arr[k]= cpr[i];
			 i++;
			 k++;
		 }

		//  for(int i=0;i<n;i++){
		// 	 for(int j=0;j<n;j++){
		// 		 if(pres==(i+j)/2){
		 //
		// 		 }
		// 	 }
		//  }

		//  for(int i = 1;i<mid;i++){
		// 	 if(arr[i]==(arr[i-1]+arr[i-1])/2){
		 //
		// 	 }
		//  }


	 }
	 void solute(int arr[],int l,int r ){
		 if (l < r)
	    {
	        // Same as (l+r)/2, but avoids overflow for
	        // large l and h
	        int m = l+(r-l)/2;

	        // Sort first and second halves
	        solute(arr, l, m);
	        solute(arr, m+1, r);

	       solver(arr, l, r);
	    }
	 }
	 void printArray(int A[], int size){
		    int i;
		    for (i=0; i < size; i++)
		        printf("%d ", A[i]);
		    printf("\n");
	}
	 int main(int argc, char const *argv[]) {
		if(argc>1)return 0;
		int n;
		scanf("%d",&n);
		int arr[n+1];
		for(int i=0;i<=n;i++){
			arr[i] = i;
		}

		solute(arr,0,n);
		printArray(arr,n+1);
		return 0;
	}
