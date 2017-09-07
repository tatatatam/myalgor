#include<stdio.h>
#include<stdlib.h>
#define MAX 30
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
              if (cloner[j] > cloner[j+1]){
                  swap(&cloner[j], &cloner[j+1]);
                  swap(&arr2[j],&arr2[j+1]);
                  swap2(&count[j],&count[j+1]);
               }
    }

    void greed_act(double a[],double data_s[],double data_f[],int count[]){
      // double s[MAX] = a[1];
      int j=0;
      int i;
      printf("%d ** %.2lf->%.2lf||->",count[0]+1,data_s[0],data_f[0]);

      for(int i=1;i<=MAX;i++){
        // if(data_s[i]>=8.00 && data_f[i]<=17.00 )
        if(data_s[i]>=data_f[j]){
          printf("%d ** %.2lf->%.2lf||->",count[i]+1,data_s[i],data_f[i]);
          j=i;
        }
      }

    }
      int greed(double data_s[MAX], double data_f[MAX],int count[]){
        // qsort(data);
        double cloner[MAX];
        bubbleSort(data_f,data_s,MAX,cloner,count);
        int i ;
        for(i=0;i<MAX;i++)printf("%00.2lf|%00.2lf|%00.2lf|%d\n",data_s[i],data_f[i],cloner[i],count[i]);
        greed_act(data_f,data_s,cloner,count);
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
     fp = fopen("schedule.txt","r");
     fscanf (fp, "%d", &i);
     fscanf (fp, "%lf", &j);
     fscanf (fp, "%lf", &k);
      while (!feof (fp))
        {
          data_s[count]=j;
          data_f[count]=k;
          position[count]=count;
          // printf ("%d AND %d ", i,j);
          fscanf (fp, "%d", &i);
          fscanf (fp, "%lf", &j);
          fscanf (fp, "%lf", &k);

          // printf("%d %.2lf %.2lf\n",i,data_s[count],data_f[count]);
          count++;
          // printf("%d and %d GCD ASWER: %d\n",i,j, gcd(i,j));
        }


        // printf("ฟหกดฟหกด%.2lf %.2lf \n",data_s[0],data_f[0]);
        greed(data_s,data_f,position);
        // if(data[30][1])printf("%lf",data[101][1]);
      //    fclose(fp);
      return 0;
  }
