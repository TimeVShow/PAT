#include <cstdio>
#include <cmath>
using namespace std;
char pos[8];
int in = 0;
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int res = m+n;
    if(res < 0){
        printf("-");
    }
    res = abs(res);
    if(res == 0){
        pos[in] = '0';
        in++;
    }
    while(res){
        pos[in] = '0'+res%10;
        in++;
        res /= 10;
    }
    for(int i = in-1;i>=0;i--){
        printf("%c",pos[i]);
        if(i%3 == 0 && i){
            printf(",");
        }
    }
    return 0;
}