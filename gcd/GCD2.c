#include<stdio.h>
#include <stdlib.h>
  long long gcd(long long m,long long n);
  long long main(){
    long long c=1;
    FILE *fp;
    char buff[255];
    long long i =0;
    long long j =0;
    // printf("%lli\n",gcd(111, 234));
    // printf("%lli\n",gcd(60, 225) );
    // printf("%lli\n",gcd(42, 584010));
    // printf("%lli\n",gcd(11, 13));
    // printf("%lli\n",gcd(7854, 4746));
    // printf("%lli\n",gcd(37894060279, 18272779829));
    // printf("%lli\n",gcd(742271756, 606228865));
    // printf("%lli\n",gcd(0, -1));
    // printf("%lli\n",gcd(gcd(-15, 0) ,gcd(20, -25)));
    // printf("%lli\n",gcd(gcd(36, 84) ,120));
    // printf("%lli\n",gcd(gcd(189, 252), gcd(1197, 292005)));
    // printf("%lli\n",gcd(0,1));
    // printf("%lli\n",gcd(gcd(-15, 0) ,gcd(20, -25)));

    fp = fopen("testcase.txt","r");

    while (!feof (fp))
      {
        // printf ("%d AND %d ", i,j);
        fscanf (fp, "%lli", &i);
        fscanf (fp, "%lli", &j);
        printf("%lli and %lli GCD ASWER: %lli\n",i,j, gcd(i,j));
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
    long long a[200];
    long long b[200];
    m=abs(m);//n
    n=abs(n);//n
    long long stack_a = m;
    long long stack_b = n;
    long long min_mod ;
    // printf("aaaaaaaaa%lli %lli",m,n);
    int k=0;
    while(m>1){
      while(m%modder==0){
        // printf("aarray%lli \n",modder);
      m = m/modder;
      a[k] = modder;
      k++;
      }modder++;
    }
    min_mod = modder-1;
    modder=2;//init again
    k=0;
    while(n>1){
      while(n%modder==0){
          // printf("barray%lli \n",modder);
      n = n/modder;
      b[k] = modder;
      k++;
      }modder++;
    }
    if(modder<min_mod)min_mod =modder-1;
    modder=2;
    k=0;
    int l=0;
    int value=1;
    // for(k=0;k<200;k++){
    // }
    while(a[k]<=min_mod&&b[l]<=min_mod){

      // printf("%lli %lli %lli\n",a[k],b[l],min_mod);
      if(a[k]==b[l]){
        value *= a[k];
        k++;l++;
      }else if(a[k]<b[l]){
        k++;
      }else if(a[k]>b[l]){
        // printf("%lli %lli %lli\n",a[k],b[l],min_mod);
        l++;
      }
    }

    return value;
    //
    // while((m>1&&n>1)){ //n
    //
    //
    // if(i%modder==0&&j%modder==0){//n-1;
    //     count++;//n-1
    //     while(i%modder==0&&j%modder==0){//2n-1
    //       count++;//2n-1
    //       i = i/modder;//2n-1
    //       j = j/modder;//2n-1
    //       res*=modder;//2n-1
    //       // printf("I:%d J:%d res:%d\n",i,j,res);
    //     }
    //
    //   }else if(m==modder||n==modder){//n-1
    //     count++;//n-1
    //     m = m/modder;//n-1
    //     n = n/modder;//n-1
    //
    //   }else{//n-1
    //     count++;//n-1
    //   }
    //     modder++;//n
    // }
    // if(m==0||n==0){//n-1
    //   res =0;//n-1
    // }
    // printf("Count: %d\n",count );

  }
