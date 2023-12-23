#include <bits/stdc++.h>
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);
using namespace std;

stack<int> stk;
queue<int> que;
int n;
string str;

int main() {
    HNT;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = n - 1; i >= 0; i--) stk.push(a[i]);
    cin >> str;
    int m = str.length();

    for(int i = 0; i < m; i++){
        if (str[i] == 'C'){
            if(!stk.empty()){
                que.push(stk.top());
                stk.pop();
            }
        }
        if (str[i] == 'H'){
            if(!que.empty()){
                stk.push(que.front());
                que.pop();
            }
        }
    }
    while(!stk.empty()){
        cout << stk.top() <<" ";
        stk.pop();
    }
    return 0;
}
