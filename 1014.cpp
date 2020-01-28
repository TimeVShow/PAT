    #include <cstdio>
    #include <queue>
    #include <algorithm>
    #include <cstring>
    using namespace std;
    queue<long long int> windows[1003];

    long long int n,m,k,q;
    long long int tim[1003];
    long long int ans[1003];
    long long int ask[1003];
    long long int ltime[1003] = {0};
    long long int rtime[1003] = {0};
    bool book[1003] = {false};

    void input(){
        scanf("%lld%lld%lld%lld",&n,&m,&k,&q);
        for(int i = 1;i <= k;i++){
            scanf("%lld",&tim[i]);
        }
        if(!m)
            m = !m;
    }

    void work(){
        int index = 1;
        while(index <= min(k,n * m)){
            for(int i = 0;i < n;i++){
                windows[i].push(index);
                if(rtime[i] >= 540){
                    book[index] = true;
                }
                rtime[i] += tim[index];
                ans[index] = rtime[i];
                index++;
            }
        }
        for(int i = 0;i < n;i++){
            if(windows[i].size()){
                int num = windows[i].front();
                ltime[i] += tim[num];
            }
        }
        while(index <= k){
            long long int tag = 0;
            for(int i = 0;i < n;i++){
                if(ltime[i] < ltime[tag]){
                    tag = i;
                }
            }
            windows[tag].pop();
            windows[tag].push(index);
            if(rtime[tag] >= 540){
                book[index] = true;
            }
            rtime[tag] += tim[index];

            ans[index] = rtime[tag];
            long long int num = windows[tag].front();
            ltime[tag] += tim[num];
            index++;
        }
    }

    void output(){
        for(int i = 0;i < q;i++){
            scanf("%lld",&ask[i]);
            long long int num = ask[i];
            long long int hours = ans[num] / 60;
            int mins = ans[num] % 60;
            hours += 8;
            if(book[num]){
                printf("Sorry");
            }else{
                printf("%02lld:%02lld",hours,mins);
            }
            puts("");
        }
    }

    int main(){
        memset(ltime,0,sizeof(ltime));
        memset(rtime,0,sizeof(rtime));
        input();
        work();
        output();
        return 0;
    }
