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
const int maxn = 1e5 + 10;
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
struct node
{
	int v;
	int len;
	node(int v1 = 0, int len1 = 0): v(v1), len(len1) {}
};
int n;
int m[105][105];
int dis[105];
void bfs() {
	queue<node> q;
	for (int i = 2; i <= n; i++) {
		dis[i] = inf;
	}
	dis[1] = 0;
	q.push(node(1, 0));
	while (!q.empty()) {
		node tp = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (i != tp.v && m[tp.v][i] != inf && tp.len + m[tp.v][i] < dis[i]) {
				dis[i] = tp.len + m[tp.v][i];
				q.push(node(i, dis[i]));
			}
		}
	}
}
void sol() {
	clock_t st, en;
	scanf("%d", &n);
	char s[10];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			scanf("%s", s);
			m[i][j] = m[j][i] = (s[0] == 'x' ? inf : atoi(s));
		}
	}
	st = clock();
	bfs();
	int mx = 0;
	for (int i = 2; i <= n; i++) {
		mx = max(mx, dis[i]);
	}
	en = clock();
	printf("%d\n", mx);
	printf("%dms\n", (int)(en - st));
}

int main()
{
	int t;
	// cin >> t;
	t = 1;
	while (t--) {
		sol();
	}
	return 0;
}