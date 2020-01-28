#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
int now;
typedef struct{
    int id;
    int grade[4];
}student;

student s[2003];
int Rank[1000003][4] = {0};
char S[4] = {'A','C','M','E'};

bool cmp(student a,student b){
    return a.grade[now] > b.grade[now];
}

void input(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++){
        scanf("%d",&s[i].id);
        int sum  = 0;
        for(int j = 1;j <= 3;j++){
            scanf("%d",&s[i].grade[j]);
            sum += s[i].grade[j];
        }
        s[i].grade[0] =  sum / 3;
    }
}

void work(){
    for(now = 0;now < 4;now++){
        sort(s,s+n,cmp);
        Rank[s[0].id][now] = 1;
        for(int i = 1;i < n;i++){
            if(s[i].grade[now] == s[i-1].grade[now]){
                Rank[s[i].id][now] = Rank[s[i - 1].id][now];
            }else{
                Rank[s[i].id][now] = i + 1;
            }
        }
    }
}

void output(){
    int num;

    for(int i = 0;i < m;i++){
        int x = -1;
        int mm = 0xffff;
       scanf("%d",&num);
       for(int i = 0;i < n;i++){
           if(num == s[i].id){
               for(int j = 0;j < 4;j++){
                   if(mm > Rank[num][j]){
                       mm = Rank[num][j];
                       x = j;
                   }
               }
           }
       }
       if(x < 0){
           printf("N/A\n");
       }else{
           printf("%d %c\n",mm,S[x]);
       }
    }
}

int main(){
    input();
    work();
    output();
    return 0;
}
