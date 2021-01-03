#include<bits/stdc++.h>
using namespace std;
#define NMAX 20
int n, k, a[NMAX];
int s[NMAX];
int mintime;
struct Node{
	int i; //已安排的作业数目
	int t[5];
	int mct, lb, ctsum;
	Node(){
		i = 0;
		for(int j = 0;j < k;j++){
			t[j] = 0;
		}
		ctsum = 0;mct = 0;
		lb = (s[1] + k - 1) / k;
	} 
	bool operator <(const Node &b)const {
		return lb > b.lb;
	}
}; 
void bfs()
{
	priority_queue<Node> pq;
	mintime = s[1];
	pq.push(Node());
	while(!pq.empty()){
		Node cn = pq.top();
		pq.pop();
		if(cn.i == n){
			if(cn.mct < mintime){
				mintime = cn.mct;
			}
			break;
		} 
		for(int j = 0; j < k; j++){
			Node nn = cn;
			nn.i++;
			nn.t[j] += a[nn.i];
			nn.ctsum += a[nn.i];
			if(nn.t[j] > nn.mct)
				nn.mct = nn.t[j];
			if(nn.mct >= mintime)
				continue;
			int r = nn.mct * k - nn.ctsum;
			nn.lb = r < s[nn.i + 1] ? ((s[1] + k - 1) / k) : nn.mct;
			pq.push(nn);
		}
	}
}
int main()
{
	while(1){
		scanf("%d%d",&n,&k);
		if(n == 0 && k == 0)break;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		s[n + 1] = 0;
		for(int i = n; i >= 1; i--){
			s[i] = s[i + 1] + a[i];
		}
		bfs();
		cout << mintime << endl;
	}
	return 0;
} 
