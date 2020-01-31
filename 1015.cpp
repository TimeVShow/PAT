#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool judgePrime(int num){
    if(num == 1){
        return false;
    }
    if(num == 2 || num == 3){
        return true;
    }
    if(num % 6 != 1 && num % 6 != 5){
        return false;
    }
    for(int i = 5;i * i < num;i += 6){
        if(num % i == 0 || num %(i+2) == 0){
            return false;
        }
    }
    return true;
}

void work(int a,int b){
    if(judgePrime(a)){
        vector<int> s;
        s.clear();
        int index = 0;
        while(a){
            int r = a % b;
            a = a / b;
            s.push_back(r);
        }
        int num = 0;
        for(int i = 0;i < s.size();i++){
            num = num * b + s[i];
        }
        if(judgePrime(num)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }else{
        printf("No\n");
    }
}

void input(){
    while(1){
        int a,b;
        scanf("%d",&a);
        if(a < 0)
            break;
        scanf("%d",&b);
        work(a,b);
    }
}

int main(){
    input();
    return 0;
}
