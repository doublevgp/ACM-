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
#define mp make_pair
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


int w, h;
int x, y;
ll ans;
bool mmp[25][25];
string s[25];
const int mov[4][2] = {0, -1, 0, 1, 1, 0, -1, 0};
void bfs() {
	memset(mmp, 0, sizeof(mmp));
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	mmp[x][y] = 1;
	ans++;
	while (!q.empty()) {
		int nx = q.front().first, ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nxtx = nx + mov[i][0], nxty = ny + mov[i][1];
			if (nxtx >= 0 && nxtx < h && nxty >= 0 && nxty < w && s[nxtx][nxty] == '.') {
				if (mmp[nxtx][nxty] == false) {
					ans++;
					q.push(make_pair(nxtx, nxty));
					mmp[nxtx][nxty] = true;
				}
			}
		}
	}
}
void sol() {
	while (cin >> w >> h) {
		if (!w && !h) break;
		for (int i = 0; i < h; i++) {
			cin >> s[i];
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (s[i][j] == '@') {
					x = i;
					y = j;
					goto go1;
				}
			}
		}
go1:
		ans = 0;
		bfs();
		cout << ans << endl;
	}
}

int main()
{
	ios;
	sol();
	return 0;
}