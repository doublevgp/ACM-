#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    if(b == 0)return a;
    return gcd(b, a % b);
}
void exeulid(ll a, ll b, ll &m, ll &n)
{
    if(b == 0){
        m = 1;
        n = 0;
        return ;
    }
    exeulid(b, a % b, m, n);
    ll t;
    t = m;
    m = n;
    n = t - a / b * n;
}
int main()
{
    ll x, y, m, n, l, a, b, c, r, j1 = 0, j2 = 0, t;
    a = 0;
    while(scanf("%lld%lld%lld%lld%lld",&x, &y, &m, &n, &l) != EOF){
        a = n - m;
        b = l;
        c = x - y;
        r = gcd(a, b);
        if(c % r){
            puts("Impossible");continue;
        }
        a /= r;
        b /= r;
        c /= r;
        exeulid(a, b, j1, j2);
        t = c * j1 / b;
        j1 = c * j1 - t * b;
        if(j1 < 0){
            if(b > 0)j1 += b;
        }
        printf("%lld\n",j1);
    }
    return 0;
}
