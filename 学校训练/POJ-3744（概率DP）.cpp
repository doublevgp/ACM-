#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

int n, a[20];
double p;

struct Matrix{
    double a,b,c,d;
    Matrix operator * (Matrix &y){
        Matrix z;
        z.a = a * y.a + b * y.c;
        z.b = a * y.b + b * y.d;
        z.c = c * y.a + d * y.c;
        z.d = c * y.b + d * y.d;
        return z;
    }
    Matrix(double a0 = 1, double b0 = 0, double c0 = 0, double d0 = 1) : a(a0),b(b0),c(c0),d(d0){}
};

double quickPower(int k)
{
    Matrix r;
    Matrix m(p, 1-p, 1, 0);

    while(k){
        if(k & 1)
            r = r * m;
        m = m * m;
        k >>= 1;
    }
    return r.a;
}

int main()
{
    while(cin>>n>>p){
        for(int i = 1; i <= n; i ++)
            cin>>a[i];
        sort(a+1,a+n+1);
        double probability = 1.0;
        for(int i = 1; i <= n; i ++){
            double q = quickPower(a[i]-a[i-1]-1);
            probability *= (1 - q);
        }
        cout<<fixed<<setprecision(7) << probability << endl;
    }
    return 0;
}
