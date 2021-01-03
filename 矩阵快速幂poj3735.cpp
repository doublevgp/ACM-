#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 105
#define  ll long long
struct mat{
    ll v[MAXN][MAXN];
    mat(){
        memset(v, 0, sizeof(v));
    }
};
mat e, ans;
int N, M, K;
mat matrix_mul(mat p1, mat p2)
{
    mat t;
    int i, j, k;
    for(i = 0; i <= N; i++)
        for(j = 0; j <= N; j++)
            if(p1.v[i][j])
                for(k = 0; k <= N; k++)
                    t.v[i][k] += (p1.v[i][j] * p2.v[j][k]);
    return t;
}
mat matrix_mi(mat p, int k)
{
    mat t;
    for(int i = 0; i <= N; i++)t.v[i][i] = 1;
    while(k){
        if(k & 1)
            t = matrix_mul(t, p);
        k >>= 1;
        p = matrix_mul(p, p);
    }
    return t;
}
void Init()
{
    int i, x, y, t;
    char w[2];
    memset(e.v, 0, sizeof(e.v));
    for(i = 0; i <= N; i++)
        e.v[i][i] = 1;
    while(K--){
        scanf("%s",w);
        if(w[0] == 'g'){
            scanf("%d",&x);
            x--;
            e.v[N][x]++;
        }else if(w[0] == 's'){
            scanf("%d%d",&x,&y);
            x--;
            y--;
            if(x != y){
                for(i = 0; i <= N; i++){
                    swap(e.v[i][x],e.v[i][y]);
                }
            }
        }else{
            scanf("%d",&x);
            x--;
            for(i = 0; i <= N; i++){
                e.v[i][x] = 0;
            }
        }
    }
}
int main()
{
    while(scanf("%d%d%d",&N, &M, &K) != EOF){
        if(!N && !M && !K)break;
        Init();
        ans = matrix_mi(e, M);
        int i;
        for(i = 0; i < N; i++)
            printf("%lld ",ans.v[N][i]);
        printf("\n");
    }
    return 0;
}
