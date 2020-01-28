#include <cstdio>
int num;
void input(){
    num = 0;
    while(true){
        char c = getchar();
        if(c == '\n'){
            break;
        }else{
            num += c-'0';
        }
    }
}
void outputEnglish(int n){
    switch(n){
        case 0:
            printf("zero");
            break;
        case 1:
            printf("one");
            break;
        case 2:
            printf("two");
            break;
        case 3:
            printf("three");
            break;
        case 4:
            printf("four");
            break;
        case 5:
            printf("five");
            break;
        case 6:
            printf("six");
            break;
        case 7:
            printf("seven");
            break;
        case 8:
            printf("eight");
            break;
        case 9:
            printf("nine");
            break;
    }
}

void output(){
    int base = 100;
    int n[4];
    int index = 0;
    if(num == 0){
        n[index] = 0;
    }else{
        while(num){
            n[index] = num % 10;
            index++;
            num /= 10;
        }
        index--;
    }
    for(int i = index;i > 0;i--){
        outputEnglish(n[i]);
        printf(" ");
    }
    outputEnglish(n[0]);
}

int main(){
    input();
    output();
    return 0;
}
