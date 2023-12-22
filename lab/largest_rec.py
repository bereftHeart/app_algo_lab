def largestRectangleArea(heights):
    stack = []
    max_area = 0
    i = 0
    while i < len(heights):
        if not stack or heights[i] >= heights[stack[-1]]:
            stack.append(i)
            i += 1
        else:
            top = stack.pop()
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, heights[top] * width)

    while stack:
        top = stack.pop()
        width = i if not stack else i - stack[-1] - 1
        max_area = max(max_area, heights[top] * width)

    return max_area

def largestRectangle(matrix):
    if not matrix:
        return 0

    n, m = len(matrix), len(matrix[0])
    heights = [0] * m
    max_area = 0

    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 1:
                heights[j] += 1
            else:
                heights[j] = 0

        max_area = max(max_area, largestRectangleArea(heights))

    return max_area

# Đọc dữ liệu vào
n, m = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(n)]

# Tính và in ra kết quả
result = largestRectangle(matrix)
print(result)
