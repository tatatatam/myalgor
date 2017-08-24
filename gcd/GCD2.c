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
  int gcd(int m , int n){
    int i=m;
    int j=n;
    int modder = 2;
    int res =1;
    int bool = 1;

    while((m!=1&&n!=1)){
      if(i%modder==0&&j%modder==0){
        while(i%modder==0&&j%modder==0){
          i = i/modder;
          j = j/modder;
          // printf("%d------%d---%d\n",i,j,modder);
          res*=modder;
        }
        // printf("%d",res);
      }else if(m==modder||n==modder){
        m = m/modder;
        m = n/modder;
        // return m;
      }
      // prisntf("modder%d\n%",m);
        modder++;
    }
    return res;
  }
