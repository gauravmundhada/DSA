class Solution {
public:
    int m, n;

    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i == m && j == n) return 0;

        if (i == m) {
            int sum = 0;
            for (int k = j; k < n; k++) sum += s2[k];
            return sum;
        }

        if (j == n) {
            int sum = 0;
            for (int k = i; k < m; k++) sum += s1[k];
            return sum;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i + 1, j + 1, dp);
        }

        int deleteS1 = s1[i] + solve(s1, s2, i + 1, j, dp);
        int deleteS2 = s2[j] + solve(s1, s2, i, j + 1, dp);

        return dp[i][j] = min(deleteS1, deleteS2);
    }

    int minimumDeleteSum(string s1, string s2) {
        m = s1.size();
        n = s2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(s1, s2, 0, 0, dp);
    }
};
