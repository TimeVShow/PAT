#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int N,M,O,T;
int num[501];
int currnum[501] ={0};
int map[501][501]={{0}};
int dis[501];
bool visit[501];
int pc;
int nc;

void input(){
    memset(visit,false,sizeof(visit));
    memset(dis,0x3fff,sizeof(dis));
    scanf("%d%d%d%d",&N,&M,&O,&T);
    for(int i = 0;i < N;i++){
       scanf("%d",&num[i]);
    }
    int a,b,c;
    for(int i = 0;i < M;i++){
        scanf("%d%d%d",&a,&b,&c);
        map[a][b] = c;
        map[b][a] = c;
    }
    dis[O] = 0;
}

void dij(){
    for(int i = 0;i<N;i++){
        if(map[i][O]){
            dis[i] = map[i][O];
            currnum[i] = num[i] + num[O];
        }
    }
    for(int i = 1;i<N;i++){
        int x;
        int m = 0xfff;
        for(int j = 0;j<N;j++){
           if(j != O && !visit[j]){
               if(m > dis[j]){
                   m = dis[j];
                   x = j;
                }
            }
        }
        visit[x] = true;
        for(int j = 0;j<N;j++){
            if(j != O && !visit[j]){
                if(dis[x] + map[x][j] < dis[j]){
                    dis[j] = dis[x] + map[x][j];
                    if(j == T)
                        pc = 1;
                    currnum[j] = currnum[x] + num[j];
                }else if(dis[x] + map[x][j] == dis[j]){
                    if(j==T)
                        pc++;
                    currnum[j] = max(currnum[j],currnum[x] + num[j]);
                }
            }
        }
    }
}

int main(){
   input();
   dij();
   printf("%d %d",pc,currnum[T]);
   return 0;
}