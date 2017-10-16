#include<stdio.h>
#include<stdlib.h>
#define MAX 8
   void swap(double *xp, double *yp)
   {
   double temp = *xp;
       *xp = *yp;
       *yp = temp;
    }
    void swap2(int  *xp, int *yp)
    {
      int  temp = *xp;
        *xp = *yp;
        *yp = temp;
     }

    // A function to implement bubble sort
    void bubbleSort(double arr[],double arr2[],int n,double cloner[],int count[])
    {
      int i, j;
      for(i=0;i<n;i++){
        cloner[i] = arr[i];
      }
      for (i = 0; i < n-1; i++)

          // Last i elements are already in place
          for (j = 0; j < n-i-1; j++)
              // if (cloner[j]-arr2[j]>cloner[j+1]-arr2[j+1]){//sort diff
                if (cloner[j]>cloner[j+1]){//normal
                // printf("%.2lf %.2lf\n",cloner[j],cloner[j+1]);
                  swap(&(cloner[j]), &(cloner[j+1]));
                  swap(&arr2[j],&arr2[j+1]);
                  swap2(&count[j],&count[j+1]);
               }
    }
	double caltime(double a,double b){

		int x = (a - (double)((int)a))*100/60;
		int y = (b - (double)((int)b))*100/60;

		int result = (a+x)*60 -(b+y)*60;
		return result ;//minutes
	}

    void greed_act(double a[],double data_s[],double data_f[],int count[]){
      // double s[MAX] = a[1];
      int j=0;
      int i;
      printf("%d ** %.2lf->%.2lf||->",count[0]+1,data_s[0],data_f[0]);

      for(int i=1;i<MAX;i++){
        // if()
        // if(data_s[j]>=data_f[i]){//normal
        if((data_s[j]>=data_f[i]&&data_f[j]>data_f[i])||(data_f[j]<=data_s[i])){
        // if(data_s[i]>=data_f[j]){
          printf("%d ** %.2lf->%.2lf||->",count[i]+1,data_s[i],data_f[i]);
          j=i;
        }
      }

    }
    void greed_act2(double a[],double data_s[],double data_f[],int count[]){
      // double s[MAX] = a[1];
	  double time =0;
      int j=0;
      int i;
      printf("%d ** %.2lf->%.2lf||->",count[0]+1,data_s[0],data_f[0]);

      int trigger =0;
      int k=0;

      int day=0;
      while(trigger == 0){
        for(int i=1;i<MAX;i++){

          if(data_s[i]>=data_f[j]){//normal

          if(data_s[i]!=0&&data_f[i]!=0){
            printf("%d ** %.2lf->%.2lf||->",count[i]+1,data_s[i],data_f[i]);
			time += caltime(data_f[i],data_s[i]);
            count[j]=0;
            data_s[j]=0;
            data_f[j]=0;
            j=i;

            }else{
              k++;
              j=i;
            }
          }

          // if(data_s[i]==0&&data_f[i]==0&k==MAX){
          //     printf("\nasdf%d ** %.2lf->%.2lf||->",count[i]+1,data_s[i],data_f[i]);
          // }
          //  if(data_s[i]==0){
          //   k++;
          //   // printf("%d ** %.2lf->%.2lf||->%d",count[i]+1,data_s[i],data_f[i],k);
          // }
          if(k==MAX){
            trigger = 1;
          }
          if(i+1==MAX){
            count[j]=0;
            data_s[j]=0;
            data_f[j]=0;
          }
        }j=0;
		printf("%f",time/60.00);
		time=0;
        printf("\n");
        day++;
      }
    //   for(i=0;i<MAX;i++){
    //       printf("%d ** %.2lf->%.2lf||->",count[i]+1,data_s[i],data_f[i]);
    //   }
      printf("\n%d",day);
    }
      int greed(double data_s[MAX], double data_f[MAX],int count[]){
        // qsort(data);
        double cloner[MAX];
        bubbleSort(data_f,data_s,MAX,cloner,count);
        int i ;
        for(i=0;i<MAX;i++)printf("%00.2lf|%00.2lf|%00.2lf|%d\n",data_s[i],data_f[i],cloner[i],count[i]);
        // greed_act(data_f,data_s,cloner,count);
        greed_act2(data_f,data_s,cloner,count);
        return 0;
      }

      void printArray(int arr[], int size)
      {
          int i;
          for (i=0; i < size; i++)
              printf("%d ", arr[i]);
          printf("\n");
      }
   int main(int argc, char const *argv[]) {
    FILE *fp;
    int i;
    double j;
    double k;
    double data_s[MAX];
    double data_f[MAX];
    int position[MAX];
    int count=0;
     fp = fopen("2301365_lab3_2017_1sol_2.txt","r");
     fscanf (fp, "%d", &i);
     fscanf (fp, "%lf", &j);
     fscanf (fp, "%lf", &k);
      while (!feof (fp))
        {
          data_s[count]=j;
          data_f[count]=k;
          position[count]=count;
          fscanf (fp, "%d", &i);
          fscanf (fp, "%lf", &j);
          fscanf (fp, "%lf", &k);
          count++;
        }


		// printf("%f",caltime(data_f[1],data_s[1]));
        greed(data_s,data_f,position);

      return 0;
  }
