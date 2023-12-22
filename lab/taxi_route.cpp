#include <bits/stdc++.h>
using namespace std;

const int max_size = 25;
int n, distances[max_size][max_size], route[max_size], best_route[max_size];
int visited[max_size];
int cmin, len_route, shortest_route, blank;

int pick_up(int point){
    if (visited[point]) return 0;
    if (point > n){
        if (!visited[point - n]) return 0;
    }
    else {
        if (!blank) return 0;
    }
    return 1;
}

void Try(int k){
    for (int x = 1; x <= 2*n; x++){
        if (pick_up(x)){
            visited[x] = 1;
            route[k] = x;
            blank = x<=n ? 0 : 1;
            len_route += distances[route[k-1]][route[k]];
            
            if (k == 2*n){
                if (len_route + distances[route[2*n]][route[0]] < shortest_route){
                    shortest_route = len_route + distances[route[2*n]][route[0]];
                    // cout << shortest_route << endl;
                    // for (int z = 0; z <= 2*n; z++) best_route[z] = route[z]; 
                }
            }  else if (len_route + (2*n+1-k)*cmin < shortest_route)
                Try(k+1);

            blank = x<=n ? 1 : 0;
            visited[x] = 0;
            len_route -= distances[route[k-1]][route[k]];
        }
    }
}

int main(){
    cin >> n;
    cmin = 1000000;
    shortest_route = 1000000;
    len_route = 0;
    for (int i = 1; i <= 2*n; i++) visited[i] = 0;
    route[0] = 0;
    for (int i = 0; i <= 2*n; i++) 
        for (int j = 0; j <= 2*n; j++){
            cin >> distances[i][j];
            if (i!=j)
                cmin = distances[i][j] < cmin ? distances[i][j] : cmin;
        }
    blank = 1;
    Try(1);
   
    cout << shortest_route;
}
