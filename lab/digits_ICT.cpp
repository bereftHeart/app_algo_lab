#include <bits/stdc++.h> 
using namespace std;

int coefficients[8] = {100, 10, 2, -100, 1000, 100, 10};
int remainders[7] = {122, 112, 110, 210, -810, -890};
int used[10], f, n, ans;

void Try(int k){
    for (int i=1; i<=9; i++){
        if (!used[i]){
            used[i] = 1;
            f += i*coefficients[k];
            if (k == 6){
                if (f == n) ans++;
            }
            else if (f + remainders[k] < n)
                Try(k+1);
            
            used[i] = 0;
            f -= i*coefficients[k];

        }
    }
}

int main(){
    cin >> n;
    f = -62;
    ans = 0;
    Try(0);
    cout << ans;
}