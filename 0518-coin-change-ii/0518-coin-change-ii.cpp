class Solution {
public:
    int solve(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) {
        if (amount == 0) return 1;
        if (amount < 0 || i == coins.size()) return 0;

        if (dp[i][amount] != -1) 
            return dp[i][amount];

        // take current coin
        int take = solve(coins, i, amount - coins[i], dp);

        // skip current coin
        int skip = solve(coins, i + 1, amount, dp);

        return dp[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(301, vector<int>(5001, -1));
        return solve(coins, 0, amount, dp);
    }
};