#include <bits/stdc++.h>
using namespace std;

const int max_size = 25;
int n, k, distance_matrix[max_size][max_size];
int a[max_size]; // chuoi don-tra khach
int a_best[max_size]; 
int appear[max_size]; // arr contains the points that appear in the journey
int placed; // The number of passengers in the bus
int cmin, f, f_best;

int check(int at_point)  // Check if at_point is already in the journey or not
{ 
    if (appear[at_point] == 1) return 0;
    if (at_point > n){
        if (appear[at_point-n] == 0) return 0;
    } else {
        if (placed + 1 > k) return 0;
    }
    return 1;
}

void Try(int x){
    for (int v = 1; v <= 2*n; v++) {
        if (check(v) == 1 ){
            appear[v] = 1;
            a[x] = v;
            placed = v<=n ? placed + 1 : placed - 1;
            f += distance_matrix[a[x-1]][a[x]];
            if (x == 2*n) {
                    f_best = f + distance_matrix[a[2*n]][0] < f_best ? f + distance_matrix[a[2*n]][0] : f_best;
                    // for (int i = 0; i < 2*n; i++) a_best[i] = a[i];
                    // cout << f_best << endl;
            }
            else if (f + (2*n+1 - x)*cmin < f_best){
                Try(x+1);
            } 
            placed = v<=n ? placed - 1 : placed + 1;
            appear[v] = 0;
            f -= distance_matrix[a[x-1]][a[x]];
        }
    }
}

int main(){
    cin >> n >> k;
    cmin = 1000000;
    for (int i = 0; i <=2*n; i++)
        for (int j = 0; j <=2*n; j++){
            cin >> distance_matrix[i][j];
            if (i!=j && cmin > distance_matrix[i][j]) cmin = distance_matrix[i][j];
        }
    f = 0;
    f_best = 1000000;
    for (int i = 0; i <= 2*n; i++) appear[i] = 0;
    placed = 0;
    a[0] = 0;
    Try(1);
    cout << f_best;
    // cout << "solution:" << endl;
    // for (int i = 0; i < 2*n; i++) 
    //     cout << a[i] << " ";
}


