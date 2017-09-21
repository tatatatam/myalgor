#include<stdio.h>

int main(){
	int i,j,mech,intime[3],outtime[3],p1[30],p2[30],p3[30],t1[30],t2[30],t3[30],re[31][3],path[31];
	scanf("%d",&mech);
	for(i=0;i<2;i++)
		scanf("%d",&intime[i]);
	for(i=0;i<2;i++)
		scanf("%d",&outtime[i]);
	for(i=0;i<mech;i++)
		scanf("%d",&p1[i]);
	for(i=0;i<mech;i++)
		scanf("%d",&p2[i]);
	for(i=0;i<mech-1;i++)
		scanf("%d",&t1[i]);
	for(i=0;i<mech-1;i++)
		scanf("%d",&t2[i]);
	re[0][0]=intime[0]+p1[0];
	re[0][1]=intime[1]+p2[0];
	re[0][1]=intime[2]+p3[0];
	for(i=1;i<mech;i++){
		if(re[i-1][0]+p1[i]>re[i-1][1]+t2[i-1]+p1[i] ){
			re[i][0]=re[i-1][1]+t2[i-1]+p1[i];
			path[i]=2;
		}else if(re[i-1][0]+p1[i]>re[i-1][2]+t3[i-1]+p1[i]){
			re[i][0]=re[i-1][2]+t3[i-1]+p1[i];
			path[i]=3;
		}else{
			re[i][0]=re[i-1][0]+p1[i];
			path[i]=1;
		}

		if(re[i-1][1]+p2[i]>re[i-1][0]+t1[i-1]+p2[i]){
			re[i][1]=re[i-1][0]+t1[i-1]+p2[i];
			path[i]=1;
		}else if(re[i-1][1]+p2[i]>re[i-1][2]+t3[i-1]+p2[i]){
			re[i][1]=re[i-1][2]+t3[i-1]+p2[i];
			path[i]=3;

		}else{
			re[i][1]=re[i-1][1]+p2[i];
			path[i]=2;
		}
		if(re[i-1][2]+p3[i]>re[i-1][0]+t1[i-1]+p3[i]){
			re[i][2]=re[i-1][0]+t1[i-1]+p3[i];
			path[i]=1;
		}else if(re[i-1][2]+p3[i]>re[i-1][1]+t2[i-1]+p3[i]){
			re[i][2]=re[i-1][1]+t2[i-1]+p3[i];
			path[i]=2;
		}else{
			re[i][2] =re[i-1][2]+p3[i];
			path[i]=3;
		}

	}
	if(re[mech-1][0]+outtime[0]>re[mech-1][1]+outtime[1]&&re[mech-1][2]+outtime[2]>re[mech-1][1]+outtime[1]){
		printf("%d\n",re[mech-1][1]+outtime[1]);
		path[mech]=2;
	}else if(re[mech-1][1]+outtime[1]>re[mech-1][0]+outtime[0]&&re[mech-1][2]+outtime[2]>re[mech-1][0]+outtime[0]){
		printf("%d\n",re[mech-1][0]+outtime[0]);
		path[mech]=1;
	}else{
		printf("%d\n",re[mech-1][2]+outtime[2]);
		path[mech]=3;
	}
	// re[mech][1]=re[mech-1][1]+outtime[1];
	// re[mech][0]=re[mech-1][0]+outtime[0];
	// for(i=0;i<=mech;i++){
	// 	printf("%d ",re[i][0]);
	// }
	// printf("\n");
	// for(i=0;i<=mech;i++){
	// 	printf("%d ",re[i][1]);
	// }
	printf("\n");
	for(i=1;i<=mech;i++){
		printf("%d ",path[i]);
	}
	return 1;
}
