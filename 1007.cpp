#include <cstdio>
int k;
int num[10005];
bool flag = false;
bool fz = false;
typedef struct{
    int sum;
    int l;
    int r;
}node;


void input(){
    scanf("%d",&k);
    for(int i = 0;i < k;i++){
        scanf("%d",&num[i]);
        if(num[i] > 0){
            flag = true;
        }
        if(!num[i]){
            fz = true;
        }
    }
}

node max(node a,node b,node c){
    node m;
    m.l = -1;
    if(a.sum > b.sum && a.sum > c.sum){
        m = a;
    }
    if(b.sum > c.sum && b.sum > a.sum){
        m = b;
    }
    if(c.sum > a.sum && c.sum > b.sum){
        m = c;
    }
    if(m.l < 0){
        if(a.sum == b.sum){
            m = a;
            return m;
        }
        if(a.sum == c.sum){
            if(a.l == c.l){
                if(a.r > c.r){
                    m = c;
                }else{
                    m = a;
                }
            }else if(a.l < c.l){
                m = a;
            }else{
                m = c;
            }
            return m;
        }
        if(b.sum == c.sum){
            m = b;
        }
    }
    return m;
}

node work(int l,int r){
    int mid = (l+r)>>1;
    if(l ==  r){
        node a;
        a.sum = num[l];
        a.l = l;
        a.r = r;
        return a;
    }else{
        node a = work(l,mid);
        node b = work(mid+1,r);
        node c;
        int lM = -0xffff;
        int rM = -0xffff;
        int left;
        int right;
        int numb = 0;
        for(int i = mid;i>=l;i--){
            numb += num[i];
            if(numb > lM){
                lM = numb;
                left = i;
            }
        }
        numb = 0;
        for(int i = mid+1;i<=r;i++){
            numb += num[i];
            if(numb > rM){
                rM = numb;
                right = i;
            }
        }
        c.sum = rM + lM;
        c.l = left;
        c.r = right;
        return max(a,b,c);
    }
}

int main(){
    input();
    if(!flag && !fz){
        printf("0 %d %d",num[0],num[k-1]);
    }else if(!flag && fz){
        printf("0 0 0");
    }else{
        node res = work(0,k-1);
        printf("%d %d %d",res.sum,num[res.l],num[res.r]);
    }
    return 0;
}
