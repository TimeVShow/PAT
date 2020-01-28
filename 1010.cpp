#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char num1[13];
char num2[13];
int tag;
int radix;
int flag = 0;
int m = 0;

void getnum(char* num){
    int index = 0;
    while(1){
        char c = getchar();
        if(c == ' '){
            break;
        }else{
            num[index] = c;
            index++;
        }
    }
}

void input(){
    getnum(num1);
    getnum(num2);
    scanf("%d%d",&tag,&radix);
}

long long int getsum(char* num,int s){
    long long int sum = 0;
    long long int base = 1;
    int x;
    for(int i = strlen(num) - 1;i>=0;i--){
        if(num[i] >= '0' && num[i] <= '9'){
            x = num[i] - '0';
            if(x > s){
                return -1;
            }
            sum += (x) * base;
        }else{
            x = num[i] - 'a' + 10;
            if(x > s){
                return -1;
            }
            sum += x * base;
        }
        base *= s;
        m = max(m,x);
        if(sum < 0){
            return -1;
        }
    }
    return sum;
}
int getlow(char* num){
    int s = 0;
    int x;
    for(int i = strlen(num) - 1;i>=0;i--){
        if(num[i] >= '0' && num[i] <= '9'){
            x = num[i] - '0';
        }else{
            x = num[i] - 'a' + 10;
        }
        s = max(s,x);
    }
    return s + 1;
}

void resolve(char* num,long long int sum){
    long long int sum2 = getsum(num2,2);
    long long int low = getlow(num);
    long long int high = max(sum,low) + 1;
    while(low < high){
        long long int mid = (low + high) / 2;
        sum2 = getsum(num,mid);
        if(sum2 < 0 || sum2 > sum){
            high = mid;
        }else if(sum2 < sum){
            low = mid;
        }else{
            flag = mid;
            return;
        }
    }
}

void work(){
    long long int sum;
    if(tag == 1){
        sum = getsum(num1,radix);
        resolve(num2,sum);

    }else{
        sum = getsum(num2,radix);
        resolve(num1,sum);
    }
}

void output(){
    if(!flag){
        printf("Impossible");
    }else{
        printf("%d",flag);
    }
}

int main(){
    input();
    work();
    output();
    return 0;
}
