#include<bits/stdc++.h>
using namespace std;
#define eps 1e-7
const double PI = acos(-1);
double a,r,s,t; 
double f(double x)
{
	return exp((a - x) * (x - a) / r / r / 2);
}
double S(double a, double b)
{
	return (f(a) + 4 * f((a + b) / 2) + f(b)) * (b - a) / 6;
}
double Simpson(double s, double err, double l, double r)
{
	double mid = (l + r) / 2;
	double s1 = S(l, mid);
	double s2 = S(mid, r);
	if(fabs(s - s1 - s2) < 15 * err){
		return s1 + s2;
	}
	return Simpson(s1, sqrt(err), l, mid) + Simpson(s2, sqrt(err), mid, r);
}
int main()
{
	while(cin >> a >> r >> s >> t){
		cout << fixed << setprecision(5);
		cout << Simpson(S(s,t), eps, s, t) / sqrt(2 * PI) / r <<endl;
	}
	return 0;
}
