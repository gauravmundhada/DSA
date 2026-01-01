// 0 - land; 1 - water
/*
You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, 
the cell on the rith row and cith column (1-based coordinates) will be covered with water 
(i.e., changed to 1).
*/
class Solution {
public:
    vector<vector<int>> directions {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    bool canCross(vector<vector<int>>& cells, int m, int row, int col) {
        // create a how will be the grid after m days
        vector<vector<int>> grid(row, vector<int>(col, 0));

        for (int i = 0; i < m; i++) {
            int r = cells[i][0] - 1; // as this is 1-based index
            int c = cells[i][1] - 1;

            grid[r][c] = 1; // mark as water
        }

        // start the bfs
        queue<pair<int, int>> q; // row, col
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        // push all the possible starting points from the row
        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 0) {
                q.push({0, i});
            }
        }

        while (!q.empty()) {
            auto[currentRow, currentCol] = q.front();
            q.pop();

            if (currentRow == row-1) return true;

            for (auto& d : directions) {
                int nRow = currentRow + d[0];
                int nCol = currentCol + d[1];

                // out of bound
                if (nRow < 0 || nCol < 0 || nRow >= row || nCol >= col || visited[nRow][nCol] || grid[nRow][nCol] == 1)
                    continue;

                visited[nRow][nCol] = true;
                q.push({nRow, nCol});
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 1;
        int r = cells.size(); 
        int ans = 0; 

        // binary search on answer
        while (l <= r) {
            int m = l + (r - l)/2;

            // check if it is possible to cross at m day
            if (canCross(cells, m, row, col)) {
                ans = m;
                l = m + 1;
            } else {
                r = m -1;
            }
        }  
        return ans;
    }
};