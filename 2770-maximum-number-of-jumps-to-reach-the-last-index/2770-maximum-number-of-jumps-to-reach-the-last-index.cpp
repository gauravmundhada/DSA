class Solution {
public:
    int n;
    vector<int> dp;

    int solve(vector<int>& nums, int target, int i) {

        // reached last index
        if (i == n - 1)
            return 0;

        // already computed
        if (dp[i] != -2)
            return dp[i];

        int ans = -1;

        for (int j = i + 1; j < n; j++) {

            // valid jump
            if (abs(nums[j] - nums[i]) <= target) {

                int next = solve(nums, target, j);

                // only consider valid paths
                if (next != -1) {
                    ans = max(ans, 1 + next);
                }
            }
        }

        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {

        n = nums.size();

        // -2 => unvisited
        // -1 => impossible to reach end
        dp.resize(n, -2);

        return solve(nums, target, 0);
    }
};