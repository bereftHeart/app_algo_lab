//C++ 
#include <bits/stdc++.h> 
using namespace std;

float current(int n){
    if (n<=50)
        return n*1728;
    if (n<=100)
        return 50*1728 + (n-50)* 1786;
    if (n<=200)
        return 50*1728 + 50*1786 + (n-100)*2074;
    if (n<=300)
        return 50*1728 + 50*1786 + 100*2074 + (n-200)*2612;
    if (n<=400)
        return 50*1728 + 50*1786 + 100*2074 + 100*2612 + (n-300)*2919;
    return 50*1728 + 50*1786 + 100*2074 + 100*2612 + 100*2919 + (n-400)*3015;
}

float new_evn(int n){
    if (n<=100)
        return n*1728;
    if (n<=200)
        return 100*1728 + (n-100)*2074;
    if (n<=400)
        return 100*1728 + 100*2074 + (n-200)*2612;
    if (n<=700)
        return 100*1728 + 100*2074 + 200*2612 + (n-400)*3111;
    return 100*1728 + 100*2074 + 200*2612 + 300*3111 + (n-700)*3457;
}

int main() 
{ 
    int n;
    cin >> n;
    float diff = new_evn(n) - current(n);
    diff = diff * 1.1;
    cout << setprecision(2) << fixed << diff;
}
