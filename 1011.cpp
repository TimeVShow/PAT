#include <cstdio>
double mon[5][5];
char order[5];
double sum = 1;

void input(){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            scanf("%lf",&mon[i][j]);
        }
    }
}

void work(){
    for(int  i = 0;i < 3;i++){
        double max = -0xfff;
        int s;
        for(int j = 0;j < 3;j++){
            if(mon[i][j] > max){
                max = mon[i][j];
                s = j;
            }
        }
        switch (s){
            case 0:
                order[i] = 'W';
                break;
            case 1:
                order[i] = 'T';
                break;
            case 2:
                order[i] = 'L';
                break;
        }
        sum *= max;
    }
}

void output(){
    double res = (sum * 0.65 - 1) * 2;
    for(int i = 0;i < 3;i++){
        printf("%c ",order[i]);
    }
    printf("%.2lf",res);
}

int main(){
    input();
    work();
    output();
    return 0;
}
