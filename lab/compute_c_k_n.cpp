#include <bits/stdc++.h>
using namespace std;

map <int, int> m;
int prime_num[1000];

int is_prime(int n){
    if (n<2) return 0;
    for (int i=2; i<= sqrt(n); i++)
        if (n%i==0) return 0;
    return 1;
}

void to_prime(int num, int oper){
    int iter = 0;
    while (num!=1){
        while (num%prime_num[iter] == 0 && num!=1){
            num = num/prime_num[iter];
            m[prime_num[iter]] += oper;
        }
        iter++;
    }
}

int cal_cnk(int n, int k){
    int c = 1;
    for (int i=n-k+1; i<=n; i++)
        to_prime(i, 1);
    for (int i=2; i<=k; i++)
        to_prime(i, -1);

    for (int i=2; i<=n; i++)
        if (m[i] > 0){
            c = c*pow(i, m[i]);
            if ()
            // cout << i << "^" << m[i] << endl;
            // cout << "c=" << c << endl;
        }
    return c;
}

int main(){
    int n, k, ans;
    cin >> k >> n;

    int j=0;
    for (int x=2; x<=1000; x++)
        if (is_prime(x))
            prime_num[j++]=x;
    
    // for (int i=0; i<j; i++)
    //     cout << prime_num[i] << ",";
    ans = cal_cnk(n, k);
    cout << ans;
    
}