#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], s[n];
    s[-1] = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        s[i] = a[i] + s[i-1];
    }
    
    int max_even_weight = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if ((s[i] - s[j-1]) % 2 == 0 && (s[j] - s[j-1]) > max_even_weight) max_even_weight = s[i] - s[j-1];

    cout << max_even_weight << endl;
}