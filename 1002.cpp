#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double cost[1002];
int pos[1001];
int in = 0;
bool cmp(int a,int b){
    return b > a;
}

int main(){
    memset(cost,0,sizeof(cost));
    int num = 0;
    for(int i = 0;i<2;i++){
        int n;
        scanf("%d",&n);
        for(int j = 0;j<n;j++){
            int k;
            double nk;
            scanf("%d%lf",&k,&nk);
            cost[k] += nk;
        }
    }
    for(int i = 1000;i>=0;i--){
        if(cost[i]!=0){
            num++;
        }
    }
    printf("%d",num);
    for(int i = 1000;i>=0;i--){
        if(cost[i] != 0){
            printf(" %d %.1lf",i,cost[i]);
        }
    }
    return 0;
}