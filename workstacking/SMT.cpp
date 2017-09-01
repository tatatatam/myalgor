#include<stdio.h>
#include<stdlib.h>
#include <queue> 

struct edge{
	struct vertex *a;
	struct vertex *b;
	int weight;
	int index;
};
struct vertex{
	int index;
	int len = 0;
	struct edge *e[10000];
};

struct vertex *listv[200000];
struct edge *liste[200000];
int addnode_var =0;
int addnode(int n,int index){
    int i,sum,j;
    int arr[20000]={0};
    struct vertex *a;
    struct edge *e;
	std::queue<struct vertex*> queue;
    for(i=0;i<20000;i++)arr[i]=0;
	queue.push(listv[0]);
    while(queue.size()>0){
        a=(struct vertex*)queue.front();
        for(i=0;i<a->len && !arr[a->index];i++){
            if(a->e[i]->a->index!=a->index){
                queue.push(a->e[i]->a);	
			}else{
               	queue.push(a->e[i]->b);		
			} 
            
        }
        arr[a->index]=1;
        queue.pop();
    }
    for(i=sum=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum!=n){
        for(i=0;i<n;i++){
            if(arr[i]){
                for(j=0;j<n;j++){
                    if(!arr[j]){
                        e=(struct edge*)malloc(sizeof(struct edge));
                        e->a=listv[i];
                        e->b=listv[j];
                        e->weight=1;
                        e->index=index;
                        liste[index++]=e;
                        listv[i]->e[listv[i]->len++]=e;
                        listv[j]->e[listv[j]->len++]=e;
                        addnode_var=1;
                        break;
                    }
                }
                break;
            }
        }
    }
    return index;
}
int setlist(int matrix[200][200],int n){
	int i,j,indexE=0,x,y;
	struct edge *e;
	struct vertex *a,*b;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
            if(matrix[i][j]!=matrix[j][i] && matrix[j][i]!=-2 && matrix[i][j]!=-2){
                if(matrix[i][j]==-1){
                    matrix[i][j]=matrix[j][i];
                }else matrix[j][i]=matrix[i][j];
            }
			if(matrix[i][j]>0){
                e=(struct edge*)malloc(sizeof(struct edge));
                if(listv[i]==NULL){
					a=(struct vertex*)malloc(sizeof(struct vertex));
					listv[i]=a;
				}
				if(listv[j]==NULL){
					b=(struct vertex*)malloc(sizeof(struct vertex));
					listv[j]=b;
				}
				e->a = listv[i]; 
				e->b = listv[j];
				e->weight=matrix[i][j];
                e->index=indexE;
				liste[indexE++]=e;
				listv[i]->index=i;
				listv[i]->e[listv[i]->len++]=e;
				listv[j]->index=j;
				listv[j]->e[listv[j]->len++]=e;
				matrix[i][j]=-2;
				matrix[j][i]=-2;
			}
		}
	}
    indexE=addnode(n,indexE);
	return indexE;
}
int iscycle(int len,int n,int *path){
	int arr[20000],arr2[20000];
	int i,egde=0,j;
	struct vertex *a;
	std::queue<struct vertex*> queue;
	for(i=0;i<20000;i++)arr[i]=arr2[i]=0;
	for(i=0;i<len;i++){
		arr[path[i]]=1;
        //printf("path %d\n",path[i]);
    }
	queue.push(liste[path[0]]->a);
	while(queue.size()>0){
		a=(struct vertex*)queue.front();
		if(arr2[a->index])return 1;
        else arr2[a->index]=1;
		egde++;
        for(j=0;j<a->len;j++){
            //printf("%d arr %d %d %d\n",a->index,arr[a->e[j]->index],a->e[j]->index,a->e[j]->weight);
			if(arr[a->e[j]->index]){
				if(a->e[j]->a->index!=a->index){
                    //printf("put A %d %d\n",a->e[j]->a->index,a->e[j]->weight);
					queue.push(a->e[j]->a);	
				}else{
                    //printf("put B %d %d\n",a->e[j]->b->index,a->e[j]->weight);
					queue.push(a->e[j]->b);		
				} 
				arr[a->e[j]->index]=0;
			}
		}
		queue.pop();
	}
    //printf("len %d %d\n",egde-1,len);
	if(egde-1!=len)return 1;
	return 0;
}
void prim(int len,int n){
	int i,j,s,min=999999,alllen=0,ch;
	int arr[5000]={0},arr2[5000],arr2e[5000];
	std::queue<struct edge*> queue;
	struct vertex *a;
	struct edge *e;
	for(i=0;i<5000;i++)arr[i]=arr2[i]=arr2e[i]=0;
	arr[0]=arr2[0]=0;
	for(i=0;i<listv[0]->len;i++){
        if(listv[0]->e[i]->weight<min)
            min=listv[0]->e[i]->weight;
    }
    ch=1;
    for(i=0;i<listv[0]->len;i++)
        if(min==listv[0]->e[i]->weight && ch){
            e=(struct edge*)listv[0]->e[i];
            ch=0;
        }else queue.push(listv[0]->e[i]);
    arr2[0]=1;
    while(alllen<n-1){
        if(!arr2[e->a->index])
            a=(struct vertex*)e->a;
        else a=(struct vertex*)e->b;
        arr2[a->index]=1;
        arr[alllen]=e->weight;
        arr2e[alllen]=e->index;
        alllen++;
       // printf("===== %d %d\n",alllen,n-1);
      //  printf("--> %d %d %d\n",a->index,queue.size(),e->weight);
        for(i=0;i<a->len;i++){
           // printf("index %d %d %d %d %d\n",a->e[i]->a->index,a->e[i]->b->index,arr2[a->e[i]->a->index],arr2[a->e[i]->b->index],a->e[i]->weight);
            if(!arr2[a->e[i]->a->index] || !arr2[a->e[i]->b->index]){
                queue.push(a->e[i]);
               // printf("%d %d\n",a->e[i]->weight,a->index);
            }
        }
        min=999999;
        for(i=0;i<queue.size();i++){
            s=queue.front()->weight;
            //printf("min %d %d %d %d %d\n",queue.front()->a->index,queue.front()->b->index,arr2[queue.front()->a->index],arr2[queue.front()->b->index],s);
                if(min>s && (!arr2[queue.front()->a->index] || !arr2[queue.front()->b->index])){
                   // printf("%d\n",s);
                    min=s;
                    queue.push(queue.front());
                    queue.pop();
                }else{
                    queue.push(queue.front());
                    queue.pop();
                }
        }
       // printf("-->1 %d\n",queue.size());
       ch=1;
        for(i=0;i<queue.size();i++){
            s=queue.front()->weight;
            if(ch && min==s){
                arr2e[alllen]=queue.front()->index;
                if(!iscycle(alllen+1,n,arr2e)){
                    e=queue.front();
                   // printf("----> %d %d %d\n",queue.front()->weight,e->weight,a->index);
                    queue.pop();
                    ch=0;
                }else{
                    queue.push(queue.front());
                    queue.pop();
                }
            }else{
                queue.push(queue.front());
                queue.pop();
            }
        }
        //printf("-->2 %d\n",queue.size());
	}
	int ink[n][n]={0},sum=0;
	for(i=0;i<n;i++)for(j=0;j<n;j++)ink[i][j]=0;
	for(i=0;i<n;i++){
       // printf("%d\n ",arr[i]);
		sum+=arr[i];
		e=liste[arr2e[i]];
		ink[e->a->index][e->b->index]=e->weight;
		ink[e->b->index][e->a->index]=e->weight;
	}
	printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)printf("%d ",ink[i][j]);	
		printf("\n");
	}
	printf("MST by PRIM = %d\n",sum-addnode_var);
}
void kruskal(int len,int n){
	int i,j,arrl[5000],index=0,arr2[5000],arr[5000],arruse[20000];
	struct edge *e;
    for(i=0;i<20000;i++)arruse[i]=0;
	for(i=0;i<len;i++){
		for(j=i+1;j<len;j++){
			if(liste[i]->weight>liste[j]->weight){
				e=liste[i];
				liste[i]=liste[j];
				liste[j]=e;
                liste[i]->index=i;
                liste[j]->index=j;
                
			}
		}
	}
//	for(i=0;i<len;i++)printf("%d\n",liste[i]->weight);
	for(i=0;i<n;i++)arr2[i]=arr[i]=0;
	for(i=0;i<len;i++){
	//	printf("ecf\n");
		arrl[index]=liste[i]->index;
		//printf("add %d %d\n",liste[i]->index,liste[i]->weight);
		if(!arruse[liste[i]->index] && !iscycle(index+1,n,arrl)){
            arruse[liste[i]->index]=1;
           //printf("--> %d\n",arrl[index]);
			arr2[index]=liste[i]->weight;
            arr[index++]=i;
            i=-1;
		}
		if(index==n-1)
			break;
	}
	int ink[n][n]={0},sum=0;
	for(i=0;i<n;i++)for(j=0;j<n;j++)ink[i][j]=0;
	for(i=0;i<n;i++){
	/*	printf("%d ",arr2[i]);
        printf("\n\n");*/
		sum+=arr2[i];
		e=liste[arr[i]];
		ink[e->a->index][e->b->index]=e->weight;
		ink[e->b->index][e->a->index]=e->weight;
	}
	printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)printf("%d ",ink[i][j]);	
		printf("\n");
	}
	printf("MST by KRUSKAL = %d\n",sum-addnode_var);
}
int main(){
	int matrix[200][200];
	int n,i,j,lenE;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&matrix[i][j]);
	lenE=setlist(matrix,n);
    //printf("len E %d\n",lenE);
    kruskal(lenE,n);
    prim(lenE,n);
	
	return 0;
}

