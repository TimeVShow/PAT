#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int num[501];
int map[501][501]={{0}};
int dis = 0xffff;
int pc;
int nc = 0;
int N,M,O,T;
bool visit[501]={false};

void dfs(int o,int pathcount,int count){
    for(int i = 0 ;i < N;i++){
        if(!visit[i] && map[o][i]){
            if(i == T){
                pathcount += map[o][i];
                if(pathcount < dis){
                    dis = pathcount;
                    pc = 1;
                    nc = count + num[T];
                }else if(pathcount == dis){
                    if(count + num[T]> nc){
                        nc = count + num[T];
                    }
                    pc++;
                }
            }else{
                visit[i] = true;
                dfs(i,pathcount + map[o][i],count+num[i]);
                visit[i] = false;
            }
        }
    }
}

int main(){
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
    visit[O] = true;
    dfs(O,0,num[O]);
    if(O == T){
        pc = 1;
        nc = num[O];
    }
    printf("%d %d",pc,nc);
    return 0;
}