#include <bits/stdc++.h>
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = n - 1; i > 0; i--){
        if (a[i-1] >= a[i]) cnt++;
    }
    cout << cnt + 1;
    return 0;
}
