#include<stdio.h>
  int gcd(int m,int n);
  int main(){
    int c=1;
    FILE *fp;
    char buff[255];
    int i =0;
    int j =0;

    fp = fopen("testcase.txt","r");
    fscanf (fp, "%d", &i);
    while (!feof (fp))
      {
        // printf ("%d AND %d ", i,j);
        fscanf (fp, "%d", &i);
        fscanf (fp, "%d", &j);
        printf("%d and %d GCD ASWER: %d\n",i,j, gcd(i,j));
      }
       fclose(fp);
    return 0;
  }

  int gcd(int m,int n){
    int t ;
    int bool = 1;
    if(m<n){
      t=m;
    }else if(m>n){
      t=n;
    }else{
      bool = 0;
      return t;

    }

    while(bool==1){
      // printf("%d\n", t);
      if( m%t== 0 ){
        if(n%t==0){
          bool = 0;
          return t;
        }else{
          t--;
          }
        }else{
          t--;
        }
      }
    }
