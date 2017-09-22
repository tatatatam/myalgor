#include<stdio.h>
#include<math.h>
#define MAX 1000000.0
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
	double cmt(double data[][2],int n){//start at i 0  j 4
		int i,j,k,gap;
		if(n<3) return 0;

		double table[n][n];

		for( gap=0;gap<n;gap++){
			for(i=0,j=gap;j<n;i++,j++){
				if(j<i+2) table[i][j]=0.0;
				else{
					table[i][j]=MAX;
					for(k=i+1;k<j;k++){
						double val = table[i][k]+table[k][j]+cost(data,i,j,k);
						if(table[i][j]>val){
							
							table[i][j]=val;

						}
					}
				}
			}
		}
		return table[0][n-1];
	}
	int main(){
		double data[5][2] = {
			{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}
						 	};
		int x =2;
		int y =0;
	    // double z = sqrt(((data[x][0]-data[y][0])*(data[x][0]-data[y][0])) +((data[x][1]-data[y][1])*(data[x][1]-data[y][1])));
		// printf("%fadsfasd",cost(data,0,1,2));
		//input  0 n-1
		printf("%f",cmt(data,5));
		return 0;
	}
