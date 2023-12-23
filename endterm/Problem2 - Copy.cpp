#include <bits/stdc++.h>
using namespace std;
//int a[1001], n;
//int mem[1001];
// 6 3 4 2 1 5 6

//#Quy hoach dong
int lis(int i, int a[], int mem[]) {
    if (mem[i] != -1) return mem[i];
    int res = 1;
    for(int j = i - 1; j >= 0; j--) {
        if (a[j] + 1 == a[i])
        res = max(res, lis(j, a, mem) + 1);
    }
    mem[i] = res;
    return res;
}

/*
//#Truy vet loi giai
void trace(int i){
    for (int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == mem[j] + 1){
            trace(j);
            break;
        }
    }
    cout<<a[i]<<" ";
}
*/

int main(){
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int a[n];
        int mem[n];
        memset(mem, -1, sizeof(mem));
        for(int i = 0; i < n; i++) cin >> a[i];
        int res = 1; //pos = 0;
        for(int i = 1; i < n; i++){
            if (res < lis(i, a, mem)){
                res = lis(i, a, mem);
                //pos = i;
            }
        }
        cout << res << endl;
        //trace(pos);
    }
    return 0;
}
