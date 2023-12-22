from collections import deque

def is_valid(x, y, rows, cols, matrix, visited):
    return 0<=x<rows and 0<=y<cols and matrix[x][y]==0 and not visited[x][y]
    # check if (x, y) is valid way

def escape_maze(matrix, start_row, start_col):
    rows = len(matrix)
    cols = len(matrix[0])
    visited = [[False for _ in range(cols)] for _ in range(rows)] # initial state for visited

    queue = deque([(start_row, start_col, 0)])  # add the start point to the queue

    while queue:
        current_row, current_col, steps = queue.popleft()

        if matrix[current_row][current_col] == 1:
            continue # skip if it's a wall

        if current_row == 0 or current_col == rows - 1 or current_col == 0 or current_col == cols - 1:
            return steps # Found the exit
        
        visited[current_row][current_col] = True

        #Explore neighbors
        neighbors = [(current_row - 1, current_col), (current_row , current_col + 1), (current_row + 1, current_col), (current_row , current_col - 1)]

        for neighbor_row, neighbor_col in neighbors: # visit each neighbor
            if is_valid(neighbor_row, neighbor_col, rows, cols, matrix, visited):
                queue.append((neighbor_row, neighbor_col, steps + 1)) # add neighbor to queue after visiting

    return -1 # no way founded
    
n, m, r, c = map(int, input().split(' '))
maze = [list(map(int, input().split())) for _ in range(n)]

# Find the esc
result = escape_maze(maze, r - 1, c - 1)


print(result)