#include<stdio.h>
#include <stdlib.h>
  long long gcd(long long m,long long n);
  long long main(){
    long long c=1;
    FILE *fp;
    char buff[255];
    long long i =0;
    long long j =0;
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

    fp = fopen("testcase.txt","r");
    fscanf (fp, "%d", &i);
    while (!feof (fp))
      {
        // printf ("%d AND %d ", i,j);
        fscanf (fp, "%d", &i);
        fscanf (fp, "%d", &j);
        printf("%d and %d GCD ASWER: %d\n",i,j, gcd(i,j));
      }
    //    fclose(fp);

       return 0;
  }
  long long gcd(long long m , long long n){
    long long i=abs(m); //n
    long long j=abs(n);//n
    long long modder = 2;
    long long res =1;
    long long count =0;
    m=abs(m);//n
    n=abs(n);//n

    while((m>1&&n>1)){ //n

    if(i%modder==0&&j%modder==0){//n-1;
        count++;//n-1
        while(i%modder==0&&j%modder==0){//2n-1
          count++;//2n-1
          i = i/modder;//2n-1
          j = j/modder;//2n-1
          res*=modder;//2n-1
          // printf("I:%d J:%d res:%d\n",i,j,res);
        }

      }else if(m==modder||n==modder){//n-1
        count++;//n-1
        m = m/modder;//n-1
        n = n/modder;//n-1

      }else{//n-1
        count++;//n-1
      }
        modder++;//n
    }
    if(m==0||n==0){//n-1
      res =0;//n-1
    }
    printf("Count: %d\n",count );
    return res;
  }
