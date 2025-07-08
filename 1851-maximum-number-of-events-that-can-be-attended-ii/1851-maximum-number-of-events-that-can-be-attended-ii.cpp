class Solution {
public:
    int helper(vector<vector<int>>& events, int k, int i, vector<vector<int>>& dp) {
        if (i == events.size() || k == 0) return 0;

        if (dp[i][k] != -1) return dp[i][k];

        int start = events[i][0];
        int end = events[i][1];
        int value = events[i][2];

        int skip = helper(events, k, i+1, dp);

        int j = i + 1;
        for (; j < events.size(); j++) {
            if (events[j][0] > end) {
                break;
            }
        }
        int take = value + helper(events, k-1, j, dp);

        return dp[i][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();        
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return helper(events, k, 0, dp);
    }
};