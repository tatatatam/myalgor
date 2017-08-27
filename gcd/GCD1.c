#include<stdio.h>
#include <stdlib.h>
// #include<limits.h>
  long long gcd(long long m,long long n);
  long long main(){
    printf("%lli\n",gcd(111, 234));
    printf("%lli\n",gcd(60, 225) );
    printf("%lli\n",gcd(42, 584010));
        printf("%lli\n",gcd(11, 13));
    printf("%lli\n",gcd(7854, 4746));
    printf("%lli\n",gcd(37894060279, 18272779829));
    printf("%lli\n",gcd(742271756, 606228865));
    printf("%lli\n",gcd(0, -1));
    printf("%lli\n",gcd(gcd(-15, 0) ,gcd(20, -25)));
    printf("%lli\n",gcd(gcd(36, 84) ,120));
    printf("%lli\n",gcd(gcd(189, 252), gcd(1197, 292005)));
    printf("%lli\n",gcd(0,1));
    printf("%lli\n",gcd(gcd(-15, 0) ,gcd(20, -25)));

    // int c=1;
    FILE *fp;
    long long i =0;
    long long j =0;
    printf("fileGCD1\n");
    fp = fopen("testcase.txt","r");
    fscanf (fp, "%lli", &i);
    while (!feof (fp))
      {
        // printf ("%lli AND %lli ", i,j);
        fscanf (fp, "%lli", &i);
        fscanf (fp, "%lli", &j);
        printf("%lli and %lli GCD ASWER: %lli\n",i,j, gcd(i,j));
      }
       fclose(fp);
    return 0;
  }

  long long gcd(long long m,long long n){
    long long t ;
    long long bool = 1;
    long long count=0;
    if(m<n){//n-1
      t=m;//n-1
    }else{//n-1
      t=n;//n-1
    }
    m= abs(m);//n
    n= abs(n);//n
    t= abs(t);//n
    while(bool==1){//n
      if(m==0||n==0){//n-1
      bool = 0;//n-1
      return 0;//n-1
      }
      else if(m%t== 0 ){//n-1
        count++;//n-1
        if(n%t==0){//2n-1
          count++;//2n-1
          bool = 0;//2n-1
          printf("counter:%lli\n ",count);
          return t;
        }else{//2n-1
          count++;//2n-1
           t--;//2n-1
          }
      }else{//n-1
         count++;//n-1
         t--;//n-1
        }
    }
  }
