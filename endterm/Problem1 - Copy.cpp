#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);
#define ll long long

int main(){
    HNT
    int n, m, T, cnt = 0;
    cin >> T;
    while(T--) {
        vector<long> a;
        vector<long> b;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        cin >> m;
        for(int i = 0; i < m; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        /*for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        for(int i = 0; i < m; i++){
            cout << b[i] << " ";
        }
        cout<< endl;*/
        mer
        int i = 0; int j = 0;
        while(i < n || j < m){
            if(a[i] == b[j]) {
                cnt++;
                i++;
                j++;
            }
            else if(a[i] < b[j]) {
                i++;
            }
            else j++;
        }
        cout << cnt <<end;
    }
    return 0;
}
