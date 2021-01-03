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
struct node {
	int step;
	int cost;
	int left;
	node(int lev = 0, int co = 0, int le = 0): step(lev), cost(co), left(le) {}
	bool operator< (const node&a)const {
		return cost + left < a.cost + a.left;
	}
};
int n, c, w[25];
bool vis[25];
int wmax;
void bfs() {
	priority_queue<node> q;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += w[i];
	}
	q.push(node(0, 0, sum));
	while (!q.empty()) {
		node top = q.top();
		q.pop();
		if (top.step == n) {
			if (top.cost > wmax) {
				wmax = top.cost;
			}
			break;
		}
		if (top.cost + w[top.step + 1] <= c) {
			q.push(node(top.step + 1, top.cost + w[top.step + 1], top.left - w[top.step + 1]));
		}
		if (top.cost + top.left - w[top.step + 1] > wmax && top.cost <= c) {
			q.push(node(top.step + 1, top.cost, top.left - w[top.step + 1]));
		}
	}
}
void sol() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	wmax = 0;
	clock_t st, en;
	st = clock();
	bfs();
	en = clock();
	cout << wmax << endl;
	cout << en - st << "ms" << endl;
	// for (int i = 1; i <= n; i++) {
	// 	cout << vis[i] << " ";
	// }
	// cout << endl;
}

int main()
{
	ios;
	int t;
	// cin >> t;
	t = 1;
	while (t--) {
		sol();
	}
	return 0;
}