#include <bits/stdc++.h> 
using namespace std;

const int max_size = 10000;
int n, M, f, ans, a[max_size];
int x[max_size], t[max_size];

void Try(int k){
    int estimate = (M - f - t[n] + t[k]) / a[k];
    for (int v = 1; v<= estimate; v++){ 
        x[k] = v;
        f += a[k]*x[k];
        if (k == n) {
            if ( f == M) ans++;
        } else Try(k+1);

        f-= a[k]*x[k];
    }
}

int main(){
    cin >> n >> M;
    t[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        t[i] = t[i-1] + a[i];
    }
    f = 0;
    ans = 0;
    Try(1);
    cout << ans;
}