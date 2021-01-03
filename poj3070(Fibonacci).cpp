#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 2
typedef long long ll;
const int MOD = 10000;
#define mod(x) ((x)%MOD)
int n;
struct mat{
    int v[MAXN][MAXN];
    mat(){
        memset(v,0,sizeof(v));
    }
};
mat unit;
mat operator *(mat a, mat b)
{
    mat ret;
    ll x;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            x = 0;
            for(int k = 0; k < 2; k++)
                x += mod((ll)a.v[i][k] * b.v[k][j]);
            ret.v[i][j] = mod(x);
        }
    }
    return ret;
}
void init_unit()
{
    for(int i = 0; i < MAXN; i++){
        unit.v[i][i] = 1;
    }
    return ;
}
mat pow_mat(mat a, ll n)
{
    mat ret = unit;
    while(n){
        if(n & 1)ret = ret * a;
        a = a * a;
        n >>= 1;
    }
    return ret;
}
mat mul(mat a, mat b)
{
    mat ret;
    for(int i = 0 ;i < 2; i ++){
        for(int j = 0; j < 2; j ++){
            if(a.v[i][j]){
                for(int k = 0; k < 2; k++){
                    ret.v[i][k] += a.v[i][j] * b.v[j][k];
                    ret.v[i][k] %= MOD;
                }
            }
        }
    }
    return ret;
}
ll solve(ll n)
{
    mat ret, p;
    ret.v[0][0] = ret.v[1][1] = 1;
    p.v[0][0] = p.v[1][0] = p.v[0][1] = 1;
    while(n){
        if(n & 1)ret = mul(ret,p);
        p = mul(p,p);
        n >>= 1;
    }
    return ret.v[0][1];
}
int main()
{
    while(scanf("%d",&n) && n != -1){
        if(!n){
            puts("0");
            continue;
        }
        else if(n < 3){
            puts("1");
            continue;
        }
        else{
            printf("%lld\n",solve(n));
        }
    }
    return 0;
}
