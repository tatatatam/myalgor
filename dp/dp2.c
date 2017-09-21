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
	double cmt(double data[][2],int i,int j){//start at i 0  j 4
		if(j<i+2)return 0;
		int k;
		double res=MAX;
			for(k=i+1;k<j;k++){
				res = min(res,(
					cmt(data,i,k)+cmt(data,k,j)
					+cost(data,i,j,k)));

			}
			// printf("%.2f %.2f %.2f r%.2f \n",i,j,k,cost(data,i,j,k));
		return res;
	}
	int main(){
		double data[5][2] = {{0, 0},
		 					 {1, 0},
							 {2, 1},
							 {1, 2},
							 {0, 2}
						 	};
		int x =2;
		int y =0;
	    // double z = sqrt(((data[x][0]-data[y][0])*(data[x][0]-data[y][0])) +((data[x][1]-data[y][1])*(data[x][1]-data[y][1])));
		// printf("%fadsfasd",cost(data,0,1,2));
		//input  0 n-1
		printf("%f",cmt(data,0,4));
		return 0;
	}
