#include <bits/stdc++.h>
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);
using namespace std;

int a[10001];
int n, k;
long max_s[10001];
int element[10001];
float max_l[10001];

int main() {
    HNT;
    cin >> n >> k;
    int max_sub = 0;
    for (int i = 1; i <= k; i++){
        cin >> a[i];
        max_s[k] += a[i];
    }
    element[k] = k;
    max_l[k] = (float)max_s[k]/k;

    for (int i = k + 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = k + 1; i <= n; i++) {
        long sum = max_s[i] = max_s[i-1] + a[i];
        int ele = element[i] = element[i-1] + 1;
        for (int j = i - element[i-1]; j <= i-k; j++){
            sum -= a[j];
            ele--;
            if(sum*element[i] >= ele*max_s[i]){
                max_s[i] = sum;
                element[i] = ele;
            }
        }
        max_l[i] = (float)max_s[i]/element[i];
    }
    printf("%.5f",*max_element(max_l + k, max_l + n));
    return 0;
}
