#include <bits/stdc++.h>
using namespace std;

const int ms = 10001;
int main(){
    int m,n;
    cin >> n >> m;
    int a[ms], b[ms], dp[ms][ms];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int i = -1; i < n; i++)
        for (int j = -1; j < m; j++)
            dp[i][j] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];

    cout << dp[n-1][m-1];
}