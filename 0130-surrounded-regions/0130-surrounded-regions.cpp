class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        DSU dsu(m * n + 1);
        int dummy = m * n;

        vector<vector<int>> dirs = {
            {0,1}, {1,0}, {-1,0}, {0,-1}
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 'O') continue;

                int id = i * n + j;

                // boundary → connect to dummy
                if (i == 0 || j == 0 || i == m-1 || j == n-1) {
                    dsu.unite(id, dummy);
                }

                // union with neighboring O's
                for (auto& d : dirs) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                        board[ni][nj] == 'O') {
                        int nid = ni * n + nj;
                        dsu.unite(id, nid);
                    }
                }
            }
        }

        // flip all O's not connected to dummy
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    int id = i * n + j;
                    if (dsu.find(id) != dsu.find(dummy)) {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};
