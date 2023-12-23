#include <bits/stdc++.h>
using namespace std;

const int N = 51;
int n,m, mt[N][N], cnt = 0, Q = 0;
int x[N], xopt[N], dk, dopt, fk, fopt, cmin = 1000001, dmax = 0;

bool visit[N];

void init(){
    x[0] = 0;
    visit[1] = true;
    fk = 0;
    dk = 0;
    fopt = INT_MAX;
}

void solution() {
    if (fopt == INT_MAX) cout << -1;
    else{
    cout<<fopt<<endl;
    cout<<dopt<<endl;
    for (int i = 1; i <= dopt; i++ )
        cout<<xopt[i]<<" ";
        //cout<<xopt[1];
        cout<<endl;
    }
}

void TRY (int k, int a[]){
    for ( int y = 1; y <= n; y++) {
        //if((k == n) && !mt[y][0]) continue;
        //if(!mt[x[k-1]][y]) continue;
        if ( !visit[y] ){
            cnt++;
            x[k] = y;
            visit[y] = true;
            fk += mt[x[k-1]][y];
            dk += a[y];
            if(dk == m){
                if (fk + mt[x[k]][0] < fopt ){
                    fopt = fk + mt[x[k]][0];
                    for( int i = 1; i <= cnt; i++)
                        xopt[i] = x[i];
                    dopt = cnt;
                }
            }else
            if (dk < m) TRY(k + 1, a);

            cnt--;
            visit[y] = false;
            fk -= mt[x[k-1]][y];
            dk -= a[k];
        }
    }
}

int main() {
    freopen("input0.txt", "r", stdin);
    freopen("output0.txt", "w", stdout);
    cin >> n >> m;
        int a[n+1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
    dmax = *max_element(a, a+n);
    for ( int i = 0; i <= n; i++)
    for ( int j = 0 ; j <= n; j++){
        cin >> mt[i][j];
        if (mt[i][j] != 0)
            cmin = (cmin > mt[i][j])? mt[i][j]:cmin;
    }
    init();
    for (int i = 1;i <= n;i++) visit[i] = false;
    TRY(1, a);
    solution();
    return 0;
}

