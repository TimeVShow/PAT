#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct{
    char number[16];
    int ST;
    int ET;
}person;

person p[1005];
int n;
bool cmp1(person a,person b){
    return a.ST<b.ST;
}

bool cmp2(person a,person b){
    return a.ET > b.ET;
}

void getname(person* a){
    int index = 0;
    while(true){
        char c = getchar();
        if(c == ' '){
            break;
        }else{
            a->number[index] = c;
            index++;
        }
    }
}

void output(){
    sort(p,p+n,cmp1);
    printf("%s",p->number);
    sort(p,p+n,cmp2);
    printf(" %s",p->number);
}

void input(){
    scanf("%d",&n);
    int h,m,s;
    for(int i = 0;i < n;i++){
        getname(p+i);
        scanf("%d:%d:%d",&h,&m,&s);
        (p+i)->ST=h*3600+m*60+s;
        scanf("%d:%d:%d",&h,&m,&s);
        (p+i)->ET=h*3600+m*60+s;
        getchar();
    }
}

int main(){
    input();
    output();
    return 0;
}