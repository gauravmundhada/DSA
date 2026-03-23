class Solution {
public:
    typedef long long ll;
    int maxProductPath(vector<vector<int>>& grid) {
        const int MOD = 1e9+7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<ll>> maxPro(m, vector<ll>(n));
        vector<vector<ll>> minPro(m, vector<ll>(n));

        maxPro[0][0] = minPro[0][0] = grid[0][0];

        for (int i = 1; i < n; i++) {
            maxPro[0][i] = minPro[0][i] = maxPro[0][i-1] * grid[0][i];
        }

        for (int i = 1; i < m; i++) {
            maxPro[i][0] = minPro[i][0] = maxPro[i-1][0] * grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] >= 0) {
                    maxPro[i][j] = max(maxPro[i][j-1], maxPro[i-1][j]) * grid[i][j];
                    minPro[i][j] = min(minPro[i][j-1], minPro[i-1][j]) * grid[i][j];
                }
                else {
                    maxPro[i][j] = min(minPro[i][j-1], minPro[i-1][j]) * grid[i][j];
                    minPro[i][j] = max(maxPro[i][j-1], maxPro[i-1][j]) * grid[i][j];
                }
            }
        }

        return (maxPro[m-1][n-1] < 0) ? -1 : maxPro[m-1][n-1] % MOD;
    }
};