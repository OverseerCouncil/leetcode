class Solution {
    unsigned int N;
    int DIRECTIONS[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

public:
    int swimInWater(vector<vector<int>>& grid) {
        N = grid.size();
        int left = 0;
        int right = N * N - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            vector<vector<bool>> visited(N, vector<bool>(N));
            if ((grid[0][0] <= mid) && dfs(grid, 0, 0, visited, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited, int threshold) {
        visited[x][y] = true;
        for (auto direction : DIRECTIONS) {
            int newX = x + direction[0];
            int newY = y + direction[1];
            if (newX >= 0 && newX < N && newY >= 0 && newY < N && !visited[newX][newY] && grid[newX][newY] <= threshold) {
                if (newX == N - 1 && newY == N - 1) {
                    return true;
                }

                if (dfs(grid, newX, newY, visited, threshold)) {
                    return true;
                }
            }
        }
        return false;
    }
};