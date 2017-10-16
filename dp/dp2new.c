#include<stdio.h>
#include<math.h>
#define MAX 1000000.0
#define PI 3.14159265358979323846
	double min(double data_r,double data_l){
		if(data_r<=data_l)return data_r;
		else return data_l;
	}
	double dist(double data[][2],int x,int y){
		return sqrt(((data[x][0]-data[y][0])*(data[x][0]-data[y][0])) +((data[x][1]-data[y][1])*(data[x][1]-data[y][1])));
	}
	double cost(double data[][2],int i,int j,int k){
		return dist(data,i,j)+dist(data,i,k)+dist(data,j,k);
	}
	double circular(double data[][2],int i,int j,int k){
		double a = dist(data,i,j);
		double b = dist(data,i,k);
		double c = dist(data,j,k);
		double s = (a+b+c)/2.0;
		double area = sqrt(s*(s-a)*(s-b)*(s-c));

		return (4*PI*area)/pow(cost(data,i,j,k),2);

	}
	double cmt(double data[][2],int n){//start at i 0  j 4
		int i,j,k,gap;
		if(n<3) return 0;

		double table[n][n];
		double table2[n][n];
		double min2 = 0.0;
		for(i=n;i>=0;i--){
			for(j=0;j<n;j++){
				table[i][j] =0;
				table2[i][j]=0;
			}
		}
		for( gap=0;gap<n;gap++){
			for(i=0,j=gap;j<n;i++,j++){
				if(j<i+2) table[i][j]=0.0;
				else{
					table[i][j]=MAX;
					for(k=i+1;k<j;k++){
						double val = table[i][k]+table[k][j]+circular(data,i,j,k);
						if(table[i][j]>val){
							//min2 = table[i][j];
							table[i][j]=val;
							//table2[i][j]=k;
						}
						//else if(min2>val){
							//min2=val;
						//}
					}
					printf("%f %d %d i j ",table[i][j],i,j);
				}

			}
		}
		for(i=n;i>=0;i--){
		for(j=0;j<n;j++){

				printf("%.2f ",table[j][i]);
			}printf("\n");
		}
		printf("%.2f\n",min2);
		return table[0][n-1];
	}
	int main(){
		int n;
		n = 5;
		double data[5][2] = {
	{-5.5,-2}, {4,0}, {15,7}, {2,10}, {-3,6}
						 	};


		printf("%f",cmt(data,n));

		return 0;
	}
