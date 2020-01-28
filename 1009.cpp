#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef struct{
    int num;
    double sum;
}node;
node a[13];
node b[13];
double c[2003];
int n,m;

void input(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d%lf",&a[i].num,&a[i].sum);
    }
    scanf("%d",&m);
    for(int i = 0;i < m;i++){
        scanf("%d%lf",&b[i].num,&b[i].sum);
    }
}

void work(){
    int count = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int num = a[i].num + b[j].num;
            double sum = a[i].sum*b[j].sum;
            if(c[num] < 1e-9){
                count++;
            }
            c[num] += sum;
        }
    }
    printf("%d",count);
    for(int i = 2000;i>=0;i--){
        if(c[i] < 1e-9){
            continue;
        }else{
            printf(" %d %.1lf",i,c[i]);
        }
    }
}

int main(){
    memset(c,0,sizeof(z));
    input();
    work();
    return 0;
}