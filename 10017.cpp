#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int n,nwindows;
int cost[10004];
typedef struct{
    int time;
    int num;
    int wtime;
    int cost;
}person;
person s[10004];
queue<person> window[1003];

bool cmp(person a,person b){
    return a.time < b.time;
}
void input(){
    scanf("%d%d",&n,&nwindows);
    int a,b,c,d;
    for(int i = 0;i < n;i++){
        scanf("%d:%d:%d%d",&a,&b,&c,&d);
        s[i].cost = d * 60;
        s[i].time = a * 3600 + b * 60 + c;
        s[i].num = i;
    }
}

void work(){
    sort(s,s+n,cmp);
    int i;
    for(i = 0;i < nwindows;i++){
        if(s[i].time < 28800){
            s[i].wtime = 28800 - s[i].time;
        }else{
            s[i].wtime = 0;
        }
        window[i].push(s[i]);
    }
    for(i;i < n;i++){
        if(s[i].time > 17 * 3600){
            s[i].wtime = 0;
            continue;
        }
        int min = 0xffff;
        int num;
        for(int j = 0;j < nwindows;j++){
            person temp = window[j].front();
            if(temp.time + temp.cost < min){
                min = temp.time + temp.cost;
                num = j;
            }
        }
        window[num].pop();
        if(s[i].time > min){
            s[i].wtime = 0;
        }else{
            s[i].wtime = min - s[i].time;
        }
        window[num].push(s[i]);
    }
}

void output(){
    double average;
    for(int i = 0;i < n;i++){
        average += s[i].wtime;
    }
    printf("%.2lf",average / (60.0 * n));
}

int main(){
    input();
    work();
    output();
    return 0;
}