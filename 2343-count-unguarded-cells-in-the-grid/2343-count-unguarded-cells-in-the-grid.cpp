class Solution {
public:
    void markGuarded(vector<vector<int>>& grid, int i, int j) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        // top
        for (int a = i-1; a >= 0; a--) {
            if (grid[a][j] == -1 || grid[a][j] == 1)
                break;

            grid[a][j] = 2;
        }

        // bottom
        for (int a = i+1; a < m; a++) {
            if (grid[a][j] == -1 || grid[a][j] == 1)
                break;

            grid[a][j] = 2;
        }

        // left
        for (int a = j-1; a >= 0; a--) {
            if (grid[i][a] == -1 || grid[i][a] == 1)
                break;

            grid[i][a] = 2;
        }

        // right
        for (int a = j+1; a < n; a++) {
            if (grid[i][a] == -1 || grid[i][a] == 1)
                break;

            grid[i][a] = 2;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto& g : guards) {
            int i = g[0];
            int j = g[1];

            grid[i][j] = 1; // mark as guard
        }

        for (auto& w : walls) {
            int i = w[0];
            int j = w[1];

            grid[i][j] = -1;
        }

        for (auto& g : guards) {
            int i = g[0];
            int j = g[1];

            markGuarded(grid, i, j);
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    count++;
            }
        }
        return count;
    }
};