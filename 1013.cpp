#include <cstdio>
#include <cstring>
int n,m,k;
int city[1003][1003] = {{0}};
int concern[1003];
bool visit[1003];

void input(){
    scanf("%d%d%d",&n,&m,&k);
    int a,b;
    for(int i = 0;i < m;i++){
        scanf("%d%d",&a,&b);
        city[a][b] = 1;
        city[b][a] = 1;
    }
    for(int i = 0;i < k;i++){
        scanf("%d",&concern[i]);
    }
}

void dfs(int num){
    visit[num] = true;
    for(int i = 1;i <= n;i++){
        if(city[num][i] && !visit[i]){
            dfs(i);
        }
    }
    return;
}

void work(){
    for(int i = 0;i < k;i++){
        memset(visit,false,sizeof(visit));
        visit[concern[i]] = true;
        int sum = 0;
        for(int i = 1;i <= n;i++){
            if(!visit[i]){
                sum++;
                dfs(i);
            }
        }
        printf("%d\n",sum-1);
    }
}

int main(){
    input();
    work();
    return 0;
}