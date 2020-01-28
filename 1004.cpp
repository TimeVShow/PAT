#include <cstdio>
#include <cstring>
#include <cstdlib>
typedef struct{
    int num;
    int next[101];
}node;

int n,m;
node a[101];
int count[101];
int max = -1;

void init(){
    memset(count,0,sizeof(count));
    for(int i=0;i<101;i++){
        memset(a[i].next,0,sizeof(a[i].next));
    }
}

void input(){
    scanf("%d%d",&n,&m);
    int root;
    int numb;
    for(int i = 0;i < m;i++){
        scanf("%2d%d",&root,&numb);
        a[root].num = numb;
        for(int j = 0;j < numb;j++){
            scanf("%2d",&a[root].next[j]);
        }
    }
}

void dfs(int nn,int deep){
    if(deep > max){
        max = deep;
    }
    if(a[nn].num == 0){
        count[deep]++;
    }else{
        for(int i = 0;i<a[nn].num;i++){
            dfs(a[nn].next[i],deep+1);
        }
    }
    return;
}

void output(){
    printf("%d",count[0]);
    for(int i = 1;i<=max;i++){
        printf(" %d",count[i]);
    }
}

int main(){
    init();
    input();
    dfs(1,0);
    output();
    return 0;
}