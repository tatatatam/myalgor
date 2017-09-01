#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include<string.h>

char **maze;
struct coordinate{
    int x;
    int y; 
    int dis;
};
char** makearr(int x,int y){
    int i;
    char **tmp_maze;
    tmp_maze=(char **)malloc(sizeof(char**)*x);
    for(i=0;i<x;i++){
        tmp_maze[i]=(char*)malloc(sizeof(char*)*y);
    }
    return tmp_maze;
}
char** cpymaze(char **maze,int x,int y){
    int i,j;
    char **tmp_maze;
    tmp_maze=makearr(x,y);
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            tmp_maze[i][j]=maze[i][j];
        }
    }
    return tmp_maze;
}
int DFS(char **maze,int x,int y,int sx,int sy){
    if(sx<0 || sy<0 || sx >= x || sy >= y)return 0;
    if(maze[sx][sy]=='#')return 0;
    if(maze[sx][sy]=='.' || maze[sx][sy]=='S'){
        if(maze[sx][sy]=='.')maze[sx][sy]='*';
        if(DFS(maze,x,y,sx+1,sy))
            return 1;
        if(DFS(maze,x,y,sx,sy+1))
            return 1;
        if(DFS(maze,x,y,sx-1,sy))
            return 1;
        if(DFS(maze,x,y,sx,sy-1))
            return 1;
        if(maze[sx][sy]=='*')maze[sx][sy]='.';
    }else if(maze[sx][sy]=='G')return 1;
    return 0;
}
int BFS(char **maze,int x,int y,int sx,int sy){
    struct coordinate *tmp,*ntmp;
    std::queue<struct coordinate*> queue;
    tmp=(struct coordinate*)malloc(sizeof(struct coordinate*));
    tmp->x=sx;
    tmp->y=sy;
    tmp->dis=0;
    queue.push(tmp);
    while(queue.size()>0){
        tmp=queue.front();
        if(tmp->x < 0 || tmp->y <0 || tmp->x >=x || tmp->y >= y)queue.pop();
        else if(maze[tmp->x][tmp->y]=='#' || maze[tmp->x][tmp->y]=='*')queue.pop();
        else if(maze[tmp->x][tmp->y]=='.' || maze[tmp->x][tmp->y]=='S'){
            if(maze[tmp->x][tmp->y]=='.')maze[tmp->x][tmp->y]='*';
            ntmp=(struct coordinate*)malloc(sizeof(struct coordinate*));
            ntmp->x=tmp->x+1;
            ntmp->y=tmp->y;
            ntmp->dis=tmp->dis+1;
            queue.push(ntmp);
            ntmp=(struct coordinate*)malloc(sizeof(struct coordinate*));
            ntmp->x=tmp->x;
            ntmp->y=tmp->y+1;
            ntmp->dis=tmp->dis+1;
            queue.push(ntmp);
            ntmp=(struct coordinate*)malloc(sizeof(struct coordinate*));
            ntmp->x=tmp->x-1;
            ntmp->y=tmp->y;
            ntmp->dis=tmp->dis+1;
            queue.push(ntmp);
            ntmp=(struct coordinate*)malloc(sizeof(struct coordinate*));
            ntmp->x=tmp->x;
            ntmp->y=tmp->y-1;
            ntmp->dis=tmp->dis+1;
            queue.push(ntmp);
            queue.pop();
        }else if(maze[tmp->x][tmp->y]=='G')return tmp->dis;
    }
}
void print_maze(char **maze,int x,int y){
    int i,j;
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
        
}
int finddis(char **maze,int x,int y){
    int i,j,sum=0;
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
            if(maze[i][j]=='*')
                sum++;
    return sum;
}
int findpathBFS(char **maze,int x,int y,int sx,int sy,int dis,int walk){
    if(sx<0 || sy<0 || sx >= x || sy >= y)return 0;
    if(maze[sx][sy]=='#')return 0;
    if(maze[sx][sy]=='*' || maze[sx][sy]=='S'){
        if(maze[sx][sy]=='*')maze[sx][sy]='-';
        if(findpathBFS(maze,x,y,sx+1,sy,dis,walk+1))
            return 1;
        if(findpathBFS(maze,x,y,sx,sy+1,dis,walk+1))
            return 1;
        if(findpathBFS(maze,x,y,sx-1,sy,dis,walk+1))
            return 1;
        if(findpathBFS(maze,x,y,sx,sy-1,dis,walk+1))
            return 1;
        if(maze[sx][sy]=='-')maze[sx][sy]='*';
    }else if(maze[sx][sy]=='G' && walk==dis)return 1;
    return 0;
}
void maze_int(char **maze,int x,int y){
    char **tmp_maze=cpymaze(maze,x,y);
    int sx,sy,ch,i,j,dis;
    ch=0;
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            if(maze[i][j]=='S'){
                sx=i;
                sy=j;
                ch=1;
                break;
            }
        }
        if(ch)break;
    }
    if(DFS(tmp_maze,x,y,sx,sy)){
        printf("DFS Path:\n");
        print_maze(tmp_maze,x,y);
        dis=finddis(tmp_maze,x,y);
        printf("path dis %d\n",dis+1);
        printf("\n");
    }
    tmp_maze=cpymaze(maze,x,y);
    if((dis=BFS(tmp_maze,x,y,sx,sy))>0){
        printf("BFS Path:\n");
        print_maze(tmp_maze,x,y);
        printf("Short path %d\n",dis);
        printf("Path in BFS:\n");
        findpathBFS(tmp_maze,x,y,sx,sy,dis,0 );
        print_maze(tmp_maze,x,y);
        printf("\n");
    }
}

int main(){
    int x,y,i,j;
    scanf("%d%d",&x,&y);
    maze=(char **)malloc(sizeof(char**)*x);
    for(i=0;i<x;i++){
        maze[i]=(char*)malloc(sizeof(char*)*y);
    }
    gets(maze[0]);
    for(i=0;i<x;i++){
        gets(maze[i]);
    }
    maze_int(maze,x,y);
    return 0;
}