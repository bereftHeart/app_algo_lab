#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    int a[n], l[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        l[i] = 1;
    }

    for (int i = 1; i < n; i++)
        for (int j = i-1; j>=0; j--){
            if (a[j] < a[i])
                l[i] = max(l[i], l[j] + 1);
        }

    for (int i = 1; i < n; i++)
        ans = l[i] > ans ? l[i] : ans;
    
    cout << ans;
    
}