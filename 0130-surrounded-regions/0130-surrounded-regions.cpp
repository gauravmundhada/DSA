class Solution {
public:
    vector<vector<int>> directions = {
        {0,1}, {1, 0}, {-1, 0}, {0, -1}
    };

    void dfs(vector<vector<char>>& board, int m, int n, int i, int j, vector<int>& visited) {
        visited[i*n+j] = 1;

        for (auto& d : directions) {
                int nx = i + d[0];
                int ny = j + d[1];

                // out of bound + not accessible + already processed cell
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || board[nx][ny] == 'X' || visited[nx*n+ny] == 1) continue;

                dfs(board, m, n, nx, ny, visited);
            }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // keep track of cell which is not to be marked
        vector<int> visited(m*n, 0);

        //queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                //q.push({0, i});
                dfs(board, m, n, 0, i, visited);
            }

            if (board[m-1][i] == 'O') {
                //q.push({m-1, i});
                dfs(board, m, n, m-1, i, visited);
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                //q.push({i, 0});
                dfs(board, m, n, i, 0, visited);
            }

            if (board[i][n-1] == 'O') {
                //q.push({i, n-1});
                dfs(board, m, n, i, n-1, visited);
            }
        }

        // mark the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = i * n + j;

                if (visited[idx] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};


/*
An 'O' is surrounded if there is NO path from it to the boundary of the matrix 
(ie. row index 0, column index 0, row index matrix.length-1, column index matrix[0].length-1)
Boundary elements se start kr
Keep track of all the cells accessible from boundary cells
Don't mark this cells 'X'
*/