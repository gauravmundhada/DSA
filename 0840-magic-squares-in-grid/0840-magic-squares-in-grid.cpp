class Solution {
public:
    int m, n;
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        if (m < 3 || n < 3) return 0;

        for (int i = 0; i <= m-3; i++) {
            for (int j = 0; j <= n-3; j++) {
                if (isMagical(grid, i, j)) 
                    count++;
            }
        }
        return count;
    }

    bool isMagical(vector<vector<int>>& grid, int x, int y) {
        vector<int> seen(16, 0);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[i+x][j+y];

                if (num < 1 || num > 9 || seen[num] == 1) return false;
                else seen[num] = 1;
            }
        }

        for (int i = 0; i < 3; i++) {
            // row sum 
            if (grid[x+i][y] + grid[x+i][y+1] + grid[x+i][y+2] != 15) return false;

            // col sum
            if (grid[x][y+i] + grid[x+1][y+i] + grid[x+2][y+i] != 15) return false;
        }

        if (grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2] != 15) return false; 

        if (grid[x][y+2] + grid[x+1][y+1] + grid[x+2][y] != 15) return false;

        return true;        
    }
};