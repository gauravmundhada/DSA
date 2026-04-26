class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    bool dfs(vector<vector<char>>& grid, int i, int j, int pi, int pj, vector<vector<bool>>& visited) {
        visited[i][j] = true;

        for (auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                continue;

            if (grid[ni][nj] != grid[i][j])
                continue;
                
            if (!visited[ni][nj]) {
                if (dfs(grid, ni, nj, i, j, visited))
                    return true;
            }
            else if (ni != pi || nj != pj) {
                return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1, visited))
                        return true;
                }
            }
        }
        return false;
    }
};