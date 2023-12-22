#include <bits/stdc++.h>
using namespace std;

const int max_size = 1001;
int a[max_size][max_size], h[max_size], n, m, ans;
stack<int> s;

int largest_rec_area(){
    int max_area = 0, i = 0, top, width;
    // Stack s store indexes of columns in ascending order of height
    while (i<m){
        if (s.empty() || h[i] >= h[s.top()])   // If the height of current column is greater than the top of stack, push it into stack
        {
            s.push(i);
            i++;
        } else {
            // we take the columns from the top of the stack and calculate the area of the rectangle with height being the height 
            // of the column at the top of the stack and width being the distance between the index of the current column and the 
            // column at the top of the stack before.
            top = s.top();
            s.pop();
            width = s.empty() ? i : i - 1 - s.top();
            max_area = max(max_area, h[top] * width);
        }
    }
    while (!s.empty()){
        top = s.top();
        s.pop();
        width = s.empty() ? i : i - 1 - s.top();
        max_area = max(max_area, h[top] * width);
    }

    return max_area;
}

int largestRec(){
    int max_rec = 0, lra;
    for (int i = 0; i < m; i++)     // initialize the height
        h[i] = 0;
    
    for (int i = 0; i <n; i++){
        for (int j = 0; j < m; j++)
            h[j] = a[i][j] == 1 ? h[j]+1 : 0;
        lra = largest_rec_area();
        max_rec = max(max_rec, lra);
    }

    return max_rec;

}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];

    ans = largestRec();
    cout << ans << endl;
}