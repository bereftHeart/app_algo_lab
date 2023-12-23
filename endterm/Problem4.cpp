#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);


int main(){
    HNT
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    int n, Q;
    cin >> n >> Q;
    int a[n+1];
    int d[n+1][n+1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n ; j++){
            cin >> d[i][j];
        }
    }

    return 0;
}
