#include <cstdio>
int quqee[105];
int n;
const int timeup = 6;
const int timedown = 4;
const int timestop = 5;
void work(){
    int old = 0;
    int res = 0;
    for(int i = 0;i < n;i++){
        if(quqee[i] > old){
            res += (quqee[i] - old)*timeup;
            res += timestop;
        }else if(quqee[i] < old){
            res += (old - quqee[i])*timedown;
            res += timestop;
        }else{
            res += timestop;
        }
        old = quqee[i];
    }
    printf("%d",res);
}

void input(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&quqee[i]);
    }
}

int main(){
    input();
    work();
    return 0;
}
