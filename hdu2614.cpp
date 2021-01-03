/**
 *    author:  doublevgp
 *	  Which can not destroy me will make me strong
**/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
//#define mp make_pair
#define pii pair<int,int>

const double PI = acos(-1.0);
const double eps = 1e-6;
const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 20;
const int maxm = 100 + 10;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll quickpow(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1) res = res * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return res;
}
ll gcd(ll a, ll b) {
	if (a < b) swap(a, b);
	return b ? gcd(b, a % b) : a;
}

ll n;
int mp[maxn][maxn];
bool vis[maxn];
int ans;
void dfs(int x, int num, int sum) {
	for (int i = 0; i < n; i++) {
		if (vis[i] || mp[x][i] < sum) continue;
		vis[i] = 1;
		dfs(i, num + 1, mp[x][i]);
		vis[i] = 0;
	}
	ans = max(ans, num);
}
void sol() {
	for (int i = 0; i <= 15; i++) {
		vis[i] = false;
		for (int j = 0; j <= 15; j++) {
			mp[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}
	ans = 1;
	vis[0] = 1;
	dfs(0, 1, 0);
	cout << ans << endl;
}

int main()
{
	ios;
	while (cin >> n) {
		sol();
	}
	return 0;
}