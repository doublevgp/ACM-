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
int n;

struct node {
	int level;
	int cn;
	int vis[55];
	node(int len = 0, int cn0 = 0): level(len), cn(cn0) {}
	bool operator < (const node& b) const {
		return cn + n - level < b.cn + n - b.level;
	}
};

int e[55][55];
int ans;
int x[55];

void bfs() {
	priority_queue<node> q;
	node a = node(0, 0);
	memset(a.vis, 0, sizeof(a.vis));
	q.push(a);
	while (!q.empty()) {
		node fro = q.top();
		q.pop();
		if (fro.level == n) {
			if (ans < fro.cn) {
				ans = fro.cn;
				for (int i = 1; i <= n; i++) {
					x[i] = fro.vis[i];
				}
			}
			return ;
		}
		int i = fro.level + 1;
		bool tag = true;
		for (int j = 1; j < i; j++) {
			if (fro.vis[j] && e[i][j] == 0) {
				tag = false;
				break;
			}
		}
		node nxt = fro;
		for (int j = 1; j <= n; j++) {
			nxt.vis[j] = fro.vis[j];
		}
		nxt.level = fro.level + 1;
		if (tag) {
			nxt.cn = fro.cn + 1;
			nxt.vis[nxt.level] = 1;
			q.push(nxt);
			//ans = max(ans, nxt.cn);
		}
		nxt.cn = fro.cn;
		nxt.vis[nxt.level] = 0;
		if (nxt.cn + n - nxt.level > ans) {
			q.push(nxt);
		}
	}
}
void sol() {
	while (cin >> n && n) {
		clock_t st, en;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> e[i][j];
			}
		}
		st = clock();
		ans = 0;
		memset(x, 0, sizeof(x));
		bfs();
		en = clock();
		cout << ans << endl;
		for (int i = 1; i <= n; i++) {
			if (i > 1) {
				cout << " ";
			}
			cout << x[i];
		}
		cout << endl;
		cout << (en - st) << "ms" << endl;
	}
}

int main()
{
	ios;
	sol();
	return 0;
}