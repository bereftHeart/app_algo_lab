#include <bits/stdc++.h>
using namespace std;

const int max_size = 1000;
int matrix[max_size][max_size], visited[max_size][max_size], m, n, r, c;

struct coordinate {
    int x,y, steps;
};

bool is_valid(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m && matrix[x][y] == 0 && visited[x][y] == 0;
}

int escape_maze(){
    std::deque<struct coordinate> dq;
    dq.push_back({r - 1, c - 1, 0});    // add the start point
    int current_row, current_col, current_steps;
    std::vector<std::pair<int, int>> neighbors;

    while (!dq.empty()){
        const coordinate& current_coor = dq.front();
        current_row = current_coor.x;
        current_col = current_coor.y;
        current_steps = current_coor.steps;
        dq.pop_front();

        if (matrix[current_row][current_col] == 1)
            continue;   // skip if it's a wall

        // if (current_row == 0 || current_col == 0 || current_row == n-1 || current_col == m-1)
        //     return current_steps + 1;   // Found the exit
        visited[current_row][current_col] = 1;

        // Explore neighbors
        neighbors = {{current_row - 1, current_col}, {current_row, current_col + 1}, {current_row + 1, current_col}, {current_row, current_col - 1}};

        for (auto neighbor : neighbors){
            // Visit each neighbor
            int neighbor_row = neighbor.first;
            int neighbor_col = neighbor.second;
            if (is_valid(neighbor_row, neighbor_col)){
                if (neighbor_row == 0 || neighbor_col == 0 || neighbor_row == n-1 || neighbor_col == m-1)
                return current_steps + 2;
                dq.push_back({neighbor_row, neighbor_col, current_steps+1});                 
            }
        }
    }

    return -1;
}

int main(){
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    int result = escape_maze();
    cout << result;
}