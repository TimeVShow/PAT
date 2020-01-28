#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
int n,m,k;

vector<pair<int,int>> eadge;
int concern[1003];
int root[1003] = {0};

int findf(int x){
    if(x == root[x]){
        return x;
    }
    root[x] = findf(root[x]);
    return root[x] = findf(root[x]);
}

void input(){
    scanf("%d%d%d",&n,&m,&k);
    int a,b;
    eadge.resize(m);
    for(int i = 0;i < m;i++){
        scanf("%d%d",&a,&b);
        eadge[i] = make_pair(a,b);
    }
    for(int i = 0;i < k;i++){
        scanf("%d",&concern[i]);
    }
}

void join(int a,int b){
    int fx = findf(a);
    int fy = findf(b);
    if(fx != fy){
        root[fx] = fy;
    }
}

void solve(int id){
    for(int i = 1;i <= n;i++){
        root[i] = i;
    }
    for(int i = 0;i < m;i++){
        if(eadge[i].first == id || eadge[i].second == id){
            continue;
        }
        join(eadge[i].first,eadge[i].second);
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(i  == id){
            continue;
        }
        if(root[i] == i ){
            cnt++;
        }
    }
    printf("%d\n",cnt-1);
}

void output(){
    for(int i = 0;i<k;i++){
        solve(concern[i]);
    }
}

int main(){
    input();
    output();
    return 0;
}
