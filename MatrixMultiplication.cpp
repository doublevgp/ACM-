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
#define pii pair<int,int>

const double PI = acos(-1.0);
const double eps = 1e-6;
const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 10;
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

int n;
int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];
bool MC() {
	int i, j;
	int x[maxn], d[maxn], e[maxn];
	for (i = 1; i <= n; i++) {
		x[i] = rand() % 2 * 2 - 1;
	}
	for (i = 1; i <= n; i++) {
		for (d[i] = 0, j = 1; j <= n; j++) {
			d[i] += b[i][j] * x[j];
		}
	}
	for (i = 1; i <= n; i++)
		for (e[i] = 0, j = 1; j <= n; j++)
			e[i] += a[i][j] * d[j]; // e = abx
	for (i = 1; i <= n; i++)
		for (d[i] = 0, j = 1; j <= n; j++)
			d[i] += c[i][j] * x[j]; // d = cx
	for (i = 1; i <= n; i++)
		if (e[i] != d[i]) // abx = cx?
			return false;
	return true;
}
void sol() {
	// cin >> n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// cin >> a[i][j];
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// cin >> b[i][j];
			scanf("%d", &b[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// cin >> c[i][j];
			scanf("%d", &c[i][j]);
		}
	}
	clock_t st, en;
	st = clock();
	bool ans = true;
	for (int i = 1; i <= 10; i++) {
		if (!(ans = MC())) break;
	}
	en = clock();
	// cout << ((ans == true) ? "YES" : "NO") << endl;
	if (ans == true) puts("YES");
	else puts("NO");
	printf("%d %dms\n", n, en - st);
}

int main()
{
	// ios;
	int t;
	// cin >> t;
	t = 1;
	while (t--) {
		sol();
	}
	return 0;
}