#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
const ll mod = 20100713LL;
using namespace std;
ll jiecheng[1000005];

void solve()
{
    jiecheng[0] = jiecheng[1] = 1;
    int i;
    for(i = 2; i <= 1000000; i++)
        jiecheng[i] = jiecheng[i - 1] *i % mod;
}

ll multimod(ll x, ll n, ll mod)
{
    ll tmp = x, res = 1LL;
    while(n){
        if(n & 1LL){
            res *= tmp;
            res %= mod;
        }
        tmp *= tmp;
        tmp %= mod;
        n >>= 1LL;
    }
    return res;
}

int main()
{
    ll t, n, k, i, j;
    ll ans1, ans2, ans;
    solve();
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n, &k);
        if(k == 0){
            puts("1");
            continue;
        }
        ans1 = ans2 = jiecheng[k];
        ans1 *= multimod(k + 1, n - k, mod);
        ans1 %= mod;
        ans1 += mod;
        ans2 *= multimod(k, n - k, mod);
        ans2 %= mod;
        ans = (ans1 - ans2) % mod;
        printf("%lld\n",ans);
    }
    return 0;
}

/*
ll multi(ll a, ll b, ll m)
{
    ll exp = a % m, res = 0;
    while(b){
        if(b & 1){
            res += exp;
            if(res >= m)res -= m;
        }
        exp <<= 1;
        if(exp > m)exp -= m;
            b >>= 1;
    }
    return res;
}*/

ll quick_mul(ll a, ll b, ll r)
{
    ll ans = 0;
    while(b){
        if(b & 1)
            ans = (ans + a) % r;
        a = (a + a) % r;
        b >>= 1;
    }
    return ans;
}
ll quick_pow(ll a, ll b, ll r)
{
    ll ans = 1;
    while(b){
        if(b & 1)
            ans = quick_mul(ans, a, r);
        a = quick_mul(a, a, r);
        b >>= 1;
    }
    return ans;
}
